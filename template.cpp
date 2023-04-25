#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MOD (ll)1e9+7
#define MAXN 200100

#define FOR(i,a,b) for (int i=a; i<b; i++) 
#define LOG(x) cout << x << "\n";

int t, n, ti, k;
ll a[MAXN], b[MAXN];
vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(3,0)));
string str;

void solve()
{
    cin >> n;
	cin >> str;
	int g=0,p=0;
	for (auto e : str) {
		if (e == 'o') g++;
		if (e == 'x') p++;
	}

	cout << (g && !p ? "Yes\n" : "No\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	#ifdef LOCAL
		freopen("in.in", "r", stdin);
		freopen("rs.out", "w", stdout);
    #endif
    
    t = 1;
    #ifdef LOCAL
    	cin >> t;
    #endif
    
    while (t--)
        solve();
    return 0;
}
