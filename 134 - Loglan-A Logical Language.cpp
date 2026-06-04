#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// টোকেনের ধরন নির্ধারণের জন্য এনাম (Enum)
enum TokenType { UNKNOWN, A, MOD, BA, DA, LA, NAM, PREDA };

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// একটি শব্দ কোন টোকেন তা পরীক্ষা করা
TokenType getTokenType(const string& s) {
    int len = s.length();
    if (len == 0) return UNKNOWN;
    
    // নামের শেষে কনসোনেন্ট থাকে
    if (!isVowel(s[len - 1])) return NAM;
    
    // ১ অক্ষরের শব্দ (A)
    if (len == 1 && isVowel(s[0])) return A;
    
    // ২ অক্ষরের শব্দ (MOD, BA, DA, LA)
    if (len == 2) {
        if (s[0] == 'g') return MOD;
        if (s[0] == 'b') return BA;
        if (s[0] == 'd') return DA;
        if (s[0] == 'l') return LA;
    }
    
    // ৫ অক্ষরের প্রেডিকেট (PREDA)
    if (len == 5) {
        bool c1 = !isVowel(s[0]), c2 = !isVowel(s[1]), v3 = isVowel(s[2]), c4 = !isVowel(s[3]), v5 = isVowel(s[4]);
        bool c_1 = !isVowel(s[0]), v_2 = isVowel(s[1]), c_3 = !isVowel(s[2]), c_4 = !isVowel(s[3]), v_5 = isVowel(s[4]);
        if ((c1 && c2 && v3 && c4 && v5) || (c_1 && v_2 && c_3 && c_4 && v_5)) {
            return PREDA;
        }
    }
    
    return UNKNOWN;
}

// Non-terminals এর আইডি
enum NonTerminal { SENTENCE, STATEMENT, PREDCLAIM, PREDS, PREDNAME, VERBPRED, PREDSTRING };

vector<TokenType> tokens;
int cache[105][105][10]; // DP table for memoization

bool checkGrammar(int L, int R, int type) {
    if (L > R) return false;
    if (cache[L][R][type] != -1) return cache[L][R][type];

    bool res = false;
    
    if (type == PREDSTRING) {
        if (L == R) res = (tokens[L] == PREDA);
        else res = (tokens[R] == PREDA && checkGrammar(L, R - 1, PREDSTRING));
    }
    else if (type == PREDNAME) {
        if (L == R) res = (tokens[L] == NAM);
        else if (tokens[L] == LA) res = checkGrammar(L + 1, R, PREDSTRING);
    }
    else if (type == VERBPRED) {
        if (tokens[L] == MOD) res = checkGrammar(L + 1, R, PREDSTRING);
    }
    else if (type == PREDS) {
        if (checkGrammar(L, R, PREDSTRING)) res = true;
        else {
            for (int i = L; i < R; ++i) {
                if (tokens[i] == A && checkGrammar(L, i - 1, PREDS) && checkGrammar(i + 1, R, PREDSTRING)) {
                    res = true;
                    break;
                }
            }
        }
    }
    else if (type == PREDCLAIM) {
        if (tokens[L] == DA && checkGrammar(L + 1, R, PREDS)) res = true;
        else {
            for (int i = L; i < R; ++i) {
                if (tokens[i] == BA && checkGrammar(L, i - 1, PREDNAME) && checkGrammar(i + 1, R, PREDS)) {
                    res = true;
                    break;
                }
            }
        }
    }
    else if (type == STATEMENT) {
        if (checkGrammar(L, R, PREDNAME)) return cache[L][R][type] = false; // statement must have verbpred
        for (int i = L; i < R; ++i) {
            if (checkGrammar(L, i, PREDNAME)) {
                if (checkGrammar(i + 1, R, VERBPRED)) { res = true; break; }
                for (int j = i + 1; j < R; ++j) {
                    if (checkGrammar(i + 1, j, VERBPRED) && checkGrammar(j + 1, R, PREDNAME)) {
                        res = true;
                        break;
                    }
                }
                if (res) break;
            }
        }
    }
    else if (type == SENTENCE) {
        res = checkGrammar(L, R, STATEMENT) || checkGrammar(L, R, PREDCLAIM);
    }

    return cache[L][R][type] = res;
}

void processSentence(const string& fullSentence) {
    tokens.clear();
    stringstream ss(fullSentence);
    string word;
    bool hasUnknown = false;

    while (ss >> word) {
        TokenType t = getTokenType(word);
        if (t == UNKNOWN) hasUnknown = true;
        tokens.push_back(t);
    }

    if (hasUnknown || tokens.empty()) {
        cout << "Bad!\n";
        return;
    }

    // Initialize memoization cache
    for (int i = 0; i < tokens.size(); ++i)
        for (int j = 0; j < tokens.size(); ++j)
            for (int k = 0; k < 8; ++k)
                cache[i][j][k] = -1;

    if (checkGrammar(0, tokens.size() - 1, SENTENCE)) {
        cout << "Good\n";
    } else {
        cout << "Bad!\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word, currentSentence = "";
    while (cin >> word && word != "#") {
        if (word.back() == '.') {
            word.pop_back(); // পিরিয়ড (.) মুছে ফেলা
            if (!word.empty()) currentSentence += word + " ";
            processSentence(currentSentence);
            currentSentence = "";
        } else {
            currentSentence += word + " ";
        }
    }
    return 0;
}
