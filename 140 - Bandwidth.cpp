#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    string line;
    while (getline(cin, line) && line != "#") {
        vector<pair<char, vector<char>>> adjacencyList;
        bool present[26] = {false};
        vector<char> vertices;
        
        // Parse representation like A:FB;B:GC
        stringstream ss(line);
        string segment;
        while (getline(ss, segment, ';')) {
            if (segment.empty()) continue;
            char u = segment[0];
            present[u - 'A'] = true;
            
            vector<char> neighbors;
            for (size_t i = 2; i < segment.length(); ++i) {
                char v = segment[i];
                neighbors.push_back(v);
                present[v - 'A'] = true;
            }
            adjacencyList.push_back({u, neighbors});
        }
        
        // Collect and sort unique vertices to ensure lexicographical order
        for (int i = 0; i < 26; ++i) {
            if (present[i]) {
                vertices.push_back(i + 'A');
            }
        }
        
        int minBandwidth = 1e9;
        vector<char> bestOrder;
        
        // Brute-force through all permutations of the vertex set
        do {
            // Map each vertex to its index position in the current permutation
            int pos[26];
            for (int i = 0; i < vertices.size(); ++i) {
                pos[vertices[i] - 'A'] = i;
            }
            
            int currentMaxBandwidth = 0;
            for (const auto& edge : adjacencyList) {
                int u_pos = pos[edge.first - 'A'];
                for (char v : edge.second) {
                    int v_pos = pos[v - 'A'];
                    currentMaxBandwidth = max(currentMaxBandwidth, abs(u_pos - v_pos));
                }
            }
            
            // Track the permutation with the lowest maximum bandwidth
            if (currentMaxBandwidth < minBandwidth) {
                minBandwidth = currentMaxBandwidth;
                bestOrder = vertices;
            }
            
        } while (next_permutation(vertices.begin(), vertices.end()));
        
        // Print the result formatted exactly as requested
        for (char c : bestOrder) {
            cout << c << " ";
        }
        cout << "-> " << minBandwidth << "\n";
    }
    return 0;
}
