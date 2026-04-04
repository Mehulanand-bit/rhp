#include <bits/stdc++.h>
using namespace std;

class infosys1 {
public:
    int calculateSum(vector<int>& arr, vector<vector<int>>& queries, int minL, int maxR) {
        
        vector<int> ans(arr.size(), -1);
        unordered_set<int> visited;

        for (int i = queries.size() - 1; i >= 0; i--) {

            if (visited.size() == (maxR - minL + 1)) break;

            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            int y = queries[i][3];

            for (int j = l; j <= r; j++) {
                visited.insert(j);

                if (ans[j] == -1) {
                    ans[j] = x + ((j - l) * y);
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == -1) {
                sum += arr[i];
            } else {
                sum += ans[i];
            }
        }

        return sum;
    }
};
