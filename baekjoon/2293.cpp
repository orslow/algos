// dp 배열 채우기
#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int su[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, t, cur;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> t;
        su[i]=t;
        // dp[t]=1;
    }

    dp[0] = 1;
    for(int i=0; i<n; i++) {
        t = su[i];
        cur = 0;
        for(int j=0; j<k; j++) {
            if(j+t > k) break;
            dp[j+t] = dp[j] + dp[j+t];
        }

        /*
        for(int u=0; u<=k; u++) {
            cout << dp[u] << ' ';
        }
        cout << '\n';
        */
    }

    /*
    for(int i=0; i<=k; i++) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
    */

    cout << dp[k] << '\n';

}


