#include <bits/stdc++.h>
using namespace std;

template<typename ... Args>
void debug(Args ... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9+7;
#define MAXN 200100

#define FOR(i,a,b) for (int i=a; i<b; i++) 
#define LOG(x) cout << x << "\n"

int t, n, k;
ll arr[MAXN];
vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(3,0)));

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    #ifdef LOCAL
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    t = 1;
    #ifdef LOCAL
        cin >> t;
    #endif
    while (t--)
        solve();
    return 0;
}