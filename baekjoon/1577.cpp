// dp
#include <bits/stdc++.h>

using namespace std;

using ull=unsigned long long;

ull so1[103][103];

set <tuple<int, int, int, int>> wy;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,w;
    cin >> n >> m >> w;

    int a,b,c,d;
    for(int i=0; i<w; i++) {
        cin >> a >> b >> c >> d;
        if(a>c) swap(a,c);
        else if(b>d) swap(b,d);
        wy.insert(make_tuple(a,b,c,d));
    }

    for(int i=0; i<n; i++) {
        if(wy.find(make_tuple(i, 0, i+1, 0))!=wy.end()) break;
        so1[i+1][0]=1;
    }

    for(int i=0; i<m; i++) {
        if(wy.find(make_tuple(0, i, 0, i+1))!=wy.end()) break;
        so1[0][i+1]=1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(wy.find(make_tuple(i-1, j, i, j))==wy.end()) {
                so1[i][j]+=so1[i-1][j];
            }

            if(wy.find(make_tuple(i, j-1, i, j))==wy.end()) {
                so1[i][j]+=so1[i][j-1];
            }
        }
    }

    cout << so1[n][m];
}
