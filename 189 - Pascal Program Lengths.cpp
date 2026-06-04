#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// The list of reserved words specified by the standard Turbo Pascal layout
const vector<string> reservedWords = {
    "and", "array", "begin", "case", "const", "div", "do", "downto", "else", "end",
    "file", "for", "forward", "function", "goto", "if", "in", "label", "mod", "nil",
    "not", "of", "or", "packed", "procedure", "program", "record", "repeat", 
    "set", "then", "to", "type", "until", "var", "while", "with"
};

// Check if a word is an official Pascal reserved word
bool isReserved(string s) {
    for (char &c : s) c = tolower(c);
    return find(reservedWords.begin(), reservedWords.end(), s) != reservedWords.end();
}

void processProgram(const string& code, const string& author) {
    int units = 0;
    int i = 0;
    int n = code.length();

    while (i < n) {
        // 1. Skip whitespace
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // 2. Skip Comments {...}
        if (code[i] == '{') {
            while (i < n && code[i] != '}') i++;
            if (i < n) i++; // skip the closing brace '}'
            continue;
        }

        // 3. Skip String Constants '...' (Handling escaped internal quotes '')
        if (code[i] == '\'') {
            i++; // skip initial quote
            while (i < n) {
                if (code[i] == '\'') {
                    // Check if it's an escaped quote ''
                    if (i + 1 < n && code[i + 1] == '\'') {
                        i += 2;
                    } else {
                        i++; // closing quote
                        break;
                    }
                } else {
                    i++;
                }
            }
            // A string constant counts as exactly ONE constant unit
            units++;
            continue;
        }

        // 4. Handle Identifiers and Reserved Words
        if (isalpha(code[i]) || code[i] == '_') {
            string token = "";
            while (i < n && (isalnum(code[i]) || code[i] == '_')) {
                token += code[i];
                i++;
            }
            // Identifiers or Reserved Words count as exactly one unit
            units++;
            continue;
        }

        // 5. Handle Constants (Numerical: Hex, Real/Scientific, Integers)
        if (isdigit(code[i]) || code[i] == '$') {
            // Hexadecimal Constants: $a9F
            if (code[i] == '$') {
                i++;
                while (i < n && isxdigit(code[i])) i++;
                units++;
                continue;
            }

            // Read base number sequence
            while (i < n && isdigit(code[i])) i++;

            // Handle Decimal and Real Subranges Safely (e.g., 1..10 vs 5.0)
            if (i < n && code[i] == '.') {
                if (i + 1 < n && code[i + 1] == '.') {
                    // This is a subrange marker '..' -> Treat left digits as a standalone unit
                    units++;
                    continue;
                } else {
                    // It is a real number dot fraction segment
                    i++;
                    while (i < n && isdigit(code[i])) i++;
                }
            }

            // Handle Scientific Exponential Notation: 5.0E-2 or 10E+5
            if (i < n && (code[i] == 'E' || code[i] == 'e')) {
                int next = i + 1;
                if (next < n && (code[next] == '+' || code[next] == '-')) next++;
                if (next < n && isdigit(code[next])) {
                    i = next;
                    while (i < n && isdigit(code[i])) i++;
                }
            }

            units++;
            continue;
        }

        // 6. Handle Operators (Multi-character priority matched first)
        if (i + 1 < n) {
            string compound = code.substr(i, 2);
            if (compound == ":=" || compound == "<=" || compound == ">=" || compound == "<>") {
                units++;
                i += 2;
                continue;
            }
        }

        // Single Character Operators and Structural Tokens
        char symbol = code[i];
        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
            symbol == '=' || symbol == '<' || symbol == '>' || symbol == '@' || 
            symbol == '^' || symbol == '(' || symbol == '[') {
            units++;
            i++;
            continue;
        }

        // 7. Ignore structural characters not belonging to instructions (., ;, ), ], etc.)
        i++;
    }

    // Output formatted directly according to requirements
    cout << "Program by " << author << " contains " << units << " units.\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    string currentProgram = "";
    string authorName = "";

    while (getline(cin, line)) {
        // Boundary validation checks for submission block termination via "~~"
        if (line.length() >= 2 && line[0] == '~' && line[1] == '~') {
            authorName = line.substr(2);
            processProgram(currentProgram, authorName);
            currentProgram = ""; // Reset parsing window buffer for the next block
        } else {
            currentProgram += line + "\n";
        }
    }

    return 0;
}
