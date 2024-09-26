//https://atcoder.jp/contests/abc360/tasks/abc360_d
#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    freopen("gen.txt", "r", stdin);
    freopen("solve.ans", "w", stdout);
    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> index_pos, index_neg, second_neg;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        if (s[i] == '1') index_pos.push_back(x);
        else {
            index_neg.push_back(x);
            second_neg.push_back(x - 2 * t);
        }
    }

    sort(index_pos.begin(), index_pos.end());
    sort(index_neg.begin(), index_neg.end());

    int cnt = 0;
    vector<int> ans(index_pos.size(), 0);
    for (int i = 0; i < index_pos.size(); i++) {

        // lesser than ith, will be excluded
        int pos = upper_bound(index_neg.begin(), index_neg.end(), index_pos[i]) - index_neg.begin();
        if (pos == index_neg.size()) pos -= 1;
        // pos = index_neg.size() - pos;

        // less or eq than i-th, count to the ans
        int pos2 = lower_bound(second_neg.begin(), second_neg.end(), index_pos[i]) - second_neg.begin();
        // if (pos2 == index_neg.size()) pos2 -= 1;
        pos2 = index_neg.size() - pos2 + 1;

        cout << index_pos[i] << " - " << pos << " | " << pos2 << endl;

        ans[i] = pos2 - pos;
        cnt += max(0LL, ans[i]);
    }

    cout << cnt << endl;
}