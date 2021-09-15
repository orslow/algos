// knapsack
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int c[103];
int p[103];
int so1[103][303][303][1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) {
        cin >> c[i] >> p[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int s=1; s<=k; s++) {
                if(j-c[i]>=0 && s-p[i]>=0) {
                    so1[i][j][s][0]=max(so1[i-1][j][s][0], so1[i-1][j-c[i]][s-p[i]][0]+1);
                } else {
                    so1[i][j][s][0]=so1[i-1][j][s][0];
                }
            }
        }
    }

    cout << so1[n][m][k][0];
}

