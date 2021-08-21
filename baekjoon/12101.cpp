// backtracking?
#include <bits/stdc++.h>

using namespace std;

vector <string> su[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    su[1].push_back("1");

    su[2].push_back("1+1");
    su[2].push_back("2");

    su[3].push_back("1+1+1");
    su[3].push_back("1+2");
    su[3].push_back("2+1");
    su[3].push_back("3");

    for(int i=4; i<=n; i++) {
        for(string p: su[i-3]) su[i].push_back(p+"+3");
        for(string p: su[i-2]) su[i].push_back(p+"+2");
        for(string p: su[i-1]) su[i].push_back(p+"+1");
    }

    sort(su[n].begin(), su[n].end());

    // for(string p:su[n]) cout << p << ' ';
    // cout << '\n';
    if(k<=su[n].size()) cout << su[n][k-1] << '\n';
    else cout << "-1" << '\n';
    
}
