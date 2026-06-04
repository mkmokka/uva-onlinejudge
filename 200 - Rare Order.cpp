#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Graph state tracking matrices and arrays
bool adjMatrix[26][26];
bool isPresent[26];
bool visited[26];
vector<char> sortedResult;

// Depth-First Search for Topological Sorting
void dfs(int u) {
    visited[u] = true;
    for (int v = 0; v < 26; ++v) {
        if (adjMatrix[u][v] && !visited[v]) {
            dfs(v);
        }
    }
    // Post-order processing ensures independent nodes get pushed onto the stack layout last
    sortedResult.push_back(static_cast<char>('A' + u));
}

int main() {
    // Optimize standard I/O streams for fast execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> wordList;
    string word;

    // Phase 1: Read all incoming strings until hitting the sentinel '#' token
    while (cin >> word && word != "#") {
        wordList.push_back(word);
    }

    // Phase 2: Compare adjacent words to build directed edge graphs
    for (size_t i = 0; i + 1 < wordList.size(); ++i) {
        const string& currentWord = wordList[i];
        const string& nextWord = wordList[i + 1];
        
        size_t minLength = min(currentWord.length(), nextWord.length());
        for (size_t j = 0; j < minLength; ++j) {
            if (currentWord[j] != nextWord[j]) {
                int u = currentWord[j] - 'A';
                int v = nextWord[j] - 'A';
                
                // Add a directed edge from character u to character v
                adjMatrix[u][v] = true;
                
                // Mark characters as active in the current alphabet sequence
                isPresent[u] = true;
                isPresent[v] = true;
                break; // Only the first differing character provides an ordering rule
            }
        }
    }

    // Phase 3: Perform Topological Sort over all active alphabet characters
    for (int i = 0; i < 26; ++i) {
        if (isPresent[i] && !visited[i]) {
            dfs(i);
        }
    }

    // Phase 4: Output characters in order (reverse of the DFS finish times)
    for (int i = static_cast<int>(sortedResult.size()) - 1; i >= 0; --i) {
        cout << sortedResult[i];
    }
    cout << "\n";

    return 0;
}
