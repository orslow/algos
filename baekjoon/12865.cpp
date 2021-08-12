// knapsack review
#include <bits/stdc++.h>

using namespace std;

int dp[101][100001];

int th[101][2];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, w, v;
    cin >> n >> k;


    for(int i=1; i<=n; i++) {
        cin >> th[i][0] >> th[i][1];
    }

    for(int i=1; i<=n; i++) {
        w = th[i][0]; v = th[i][1];
        for(int j=1; j<=k; j++) {

            if(j >= w ) {
                dp[i][j] = max(dp[i-1][j-w] + v, dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][k] << '\n';
}

