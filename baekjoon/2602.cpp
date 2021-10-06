// dp resolve need
#include <bits/stdc++.h>

using namespace std;

string r,b[2];

int dp[2][23][103];

int m,n,ans;

int dfs(int d, int t, int e) {

    if(d==m) return 1;

    int &cur=dp[t][d][e];
    if(cur!=-1) return cur;

    cur=0;
    for(int i=e; i<n; i++) {
        if(b[t][i]==r[d]) {
            cur+=dfs(d+1, 1-t, i+1);
        }
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> b[0] >> b[1];
    m=r.length();
    n=b[0].length();

    memset(dp, -1, sizeof(dp));

    int ans=0;
    ans+=dfs(0, 0, 0); // 두루마리 인덱스, 다리 차례, 어디 이상부터
    ans+=dfs(0, 1, 0);

    cout << ans;
}
