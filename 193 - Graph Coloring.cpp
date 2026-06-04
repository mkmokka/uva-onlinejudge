#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Node color states
enum Color { UNCOLORED, WHITE, BLACK };

int numVertices, numEdges;
int maxBlackCount;
vector<vector<int>> adjList;
vector<Color> currentColors;
vector<int> optimalBlackNodes;

// Backtracking DFS Function
void backtrack(int node, int currentBlackCount) {
    // Base case: If we have processed all nodes, check if this path is better
    if (node > numVertices) {
        if (currentBlackCount > maxBlackCount) {
            maxBlackCount = currentBlackCount;
            optimalBlackNodes.clear();
            for (int i = 1; i <= numVertices; ++i) {
                if (currentColors[i] == BLACK) {
                    optimalBlackNodes.push_back(i);
                }
            }
        }
        return;
    }

    // Pruning optimization: Check if it's theoretically possible to beat maxBlackCount
    if (currentBlackCount + (numVertices - node + 1) <= maxBlackCount) {
        return;
    }

    // Choice 1: Try coloring the current node BLACK
    bool canBeBlack = true;
    for (int neighbor : adjList[node]) {
        if (currentColors[neighbor] == BLACK) {
            canBeBlack = false;
            break;
        }
    }

    if (canBeBlack) {
        currentColors[node] = BLACK;
        backtrack(node + 1, currentBlackCount + 1);
        currentColors[node] = UNCOLORED; // Backtrack state reversion
    }

    // Choice 2: Try coloring the current node WHITE
    currentColors[node] = WHITE;
    backtrack(node + 1, currentBlackCount);
    currentColors[node] = UNCOLORED; // Backtrack state reversion
}

int main() {
    // Optimize standard I/O streams for competitive programming speeds
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    if (cin >> testCases) {
        while (testCases--) {
            cin >> numVertices >> numEdges;

            // Reset data structures for the current graph workspace
            adjList.assign(numVertices + 1, vector<int>());
            currentColors.assign(numVertices + 1, UNCOLORED);
            optimalBlackNodes.clear();
            maxBlackCount = -1;

            // Read edge configurations
            for (int i = 0; i < numEdges; ++i) {
                int u, v;
                cin >> u >> v;
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }

            // Start backtracking from the first node (1-indexed)
            backtrack(1, 0);

            // Print the total maximum black node count
            cout << maxBlackCount << "\n";

            // Print the sequence of black node identifiers
            for (size_t i = 0; i < optimalBlackNodes.size(); ++i) {
                cout << optimalBlackNodes[i] << (i + 1 == optimalBlackNodes.size() ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}
