//https://atcoder.jp/contests/abc360/tasks/abc360_d
#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifdef LOCAL
        freopen("gen.txt", "r", stdin);
        freopen("brute.ans", "w", stdout);
    #endif

    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> index_pos, index_neg;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        if (s[i] == '1') index_pos.push_back(x);
        else index_neg.push_back(x);
    }

    int cnt = 0;
    for (int i = 0; i < index_pos.size(); i++){
        for (int j = 0; j < index_neg.size(); j++) {
            if (index_pos[i] > index_neg[j]) continue;
            double maxi = index_pos[i] + t;
            double maxj = index_neg[j] - t;
            if (maxi >= maxj) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}