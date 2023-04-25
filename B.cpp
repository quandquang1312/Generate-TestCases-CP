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

void solve()
{
    cin >> n;
    vector<ll> neg, pos;
    FOR(i,0,n) {
        cin >> a[i];
        if (a[i] < 0) neg.push_back(a[i]);
        else pos.push_back(a[i]);
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<ll>());

    ll rs=LONG_LONG_MIN;
    if (neg.size() >= 2)
        rs = max(rs, neg[0]*neg[1]);

    if (pos.size() >= 2)
        rs = max(rs, pos[0]*pos[1]);

    if (pos.size() && neg.size())
        rs = max(rs, pos[0] * neg[neg.size()-1]);

    LOG(rs);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("in.in", "r", stdin);
	freopen("rs.out", "w", stdout);
    
    cin >> t;
    while (t--)
        solve();
    return 0;
}