#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gen.txt", "r", stdin);
    freopen("solve.ans", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a[n - 1] + b[m - 1] << endl;

    return 0;
}