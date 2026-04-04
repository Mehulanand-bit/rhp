#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> one; // max heap
    priority_queue<int, vector<int>, greater<int>> zero; // min heap

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        one.push(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        zero.push(x);
    }

    long long ans = 0;
    int mod = 1e7; 

    for (int i = 0; i < n; i++) {
        int a = one.top(); one.pop();
        int b = zero.top(); zero.pop();

        while (a-- > 0) {
            ans = (ans * 2 + 1) % mod;
        }
        while (b-- > 0) {
            ans = (ans * 2) % mod;
        }
    }

    cout << ans << "\n";

    return 0;
}
