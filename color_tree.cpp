#include <bits/stdc++.h>
using namespace std;

class ColorTree {
public:

    int dfs(int node,
            unordered_map<int, vector<int>>& graph,
            int& globalSum,
            vector<int>& visitedColors,
            vector<int>& colors) {

        if (node == 0) return 0;

        if (!graph.count(node)) {
            return 0;
        }

        // add current node color
        visitedColors.push_back(colors[node - 1]);

        vector<int>& neighbours = graph[node];

        for (int i = 0; i < neighbours.size(); i++) {
            dfs(neighbours[i], graph, globalSum, visitedColors, colors);

            unordered_set<int> st(visitedColors.begin(), visitedColors.end());
            globalSum = max(globalSum, (int)st.size());

            if (!visitedColors.empty())
                visitedColors.pop_back();
        }

        unordered_set<int> st(visitedColors.begin(), visitedColors.end());
        globalSum = max(globalSum, (int)st.size());

        return globalSum;
    }

    int findMax(vector<int>& nodes, vector<int>& colors, vector<int>& queries) {

        unordered_map<int, vector<int>> graph;

        // build graph
        for (int i = 0; i < nodes.size(); i++) {
            graph[nodes[i]].push_back(i + 1);
        }

        unordered_map<int, int> cache;
        int sum = 0;

        for (int q : queries) {

            if (cache.count(q)) {
                sum += cache[q];
                continue;
            }

            int globalSum = 0;

            if (!graph.count(q)) {
                sum += 1;
                continue;
            }

            vector<int> visitedColors;

            int val = dfs(q, graph, globalSum, visitedColors, colors);

            cache[q] = val;
            sum += val + 1;
        }

        return sum;
    }
};
