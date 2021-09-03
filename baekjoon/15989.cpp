// dp - hard to get idea
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int dp[10001][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    dp[2][2]=1;
    dp[3][2]=1;
    dp[3][3]=1;

    for(int i=4; i<=10000; i++) {
        dp[i][2]=dp[i-2][2]+1;
        dp[i][3]=+dp[i-3][2]+dp[i-3][3]+1;
    }

    /*
    for(int i=1; i<n; i++) {
        for(int j=1; j<=3; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    while(t--) {
        cin >> n;
        cout << dp[n][2]+dp[n][3]+1 << '\n';
    }


}
