// dp exercise
#include <bits/stdc++.h>

using namespace std;

int so1[31][31];
long long so2[31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h,n;
    cin >> h >> n;

    for(int i=0; i<=30; i++) {
        for(int j=0; j<=30; j++) {
            if(j>i) so1[i][j]=1;
        }
    }

    if(h>n) swap(h, n);

    for(int i=h; i<=n; i++) {
        if(so1[i][h]==0) so2[i][h]=1;
        if(so1[h][i]==0) so2[h][i]=1;
    }

    for(int i=h+1; i<=n; i++) {
        for(int j=h+1; j<=n; j++) {
            if(so1[i][j]==1) continue;
            if(i-1>=0) so2[i][j]+=so2[i-1][j];
            if(j-1>=0) so2[i][j]+=so2[i][j-1];
        }
    }

    cout << so2[n][n];
}
