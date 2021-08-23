// not easy dp
#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > so1;

int dis[505][505];
int dp[505][505];

int cal(int n, int k) {
    if(dp[n][k] != -1) return dp[n][k];
    if(n==0) return 0;
    dp[n][k] = 987654321;
    for(int i=0; i<=k; i++) {
        if(n-i-1>=0) dp[n][k] = min( cal(n-i-1, k-i) + dis[n-i-1][n], dp[n][k]);
    }
    return dp[n][k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        so1.push_back({x, y});
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            dis[i][j] = abs(so1[i].first-so1[j].first) + abs(so1[i].second-so1[j].second);
        }
    }


    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            dp[i][j]=-1;
        }
    }

    cout << cal(n-1, k) << '\n';


}

