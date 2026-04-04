#include <bits/stdc++.h>
using namespace std;

vector<int> p, s;

int find_set(int x) {
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]); 
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;

    
    if (s[a] < s[b]) {
        swap(a, b);
    }
    p[b] = a;
    s[a] += s[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    p.resize(n + 1);
    s.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        s[i] = 1;
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find_set(i) == i) {
            ans = max(ans, s[i]);
        }
    }

    cout << ans << "\n";

    return 0;
}
