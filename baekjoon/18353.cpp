// longest increasing subsequence (dp)
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[2001];
int dp[2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    dp[0]=1;
    int ans=0;
    for(int i=0; i<n; i++) {
        dp[i]=1;
        for(int j=0; j<i; j++) {
            if(so1[j] > so1[i] && dp[i] < dp[j]+1) dp[i]=dp[j]+1;
        }
        if(dp[i]>ans) ans=dp[i];
    }

    /*
    for(int i=0; i<n; i++) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
    */

    cout << n-ans << '\n';
}

