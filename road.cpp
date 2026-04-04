#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> required(n);
    required[0] = heights[0];

    for (int i = 1; i < n; i++) {
        required[i] = required[i - 1] - 1;
    }

    priority_queue<int, vector<int>, greater<int>> extraDigNee; 

    for (int i = 0; i < n; i++) {
        int diff = heights[i] - required[i];
        if (diff > 0) {
            extraDigNee.push(diff);
        }
    }

    int days = 0;
    int maxDigPossible = 0;

    while (!extraDigNee.empty()) {
        int currentNeed = extraDigNee.top();
        extraDigNee.pop();

        if (maxDigPossible < currentNeed) {
            days++;
            maxDigPossible = 2 * days - 1;
        }
    }

    cout << days << "\n";

    return 0;
}
