// prefix sum / sync_with_stdio, should think more
#include <bits/stdc++.h>

using namespace std;

char so1[1003][1003];
int so2[1003][1003][3];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m,n,k;
    cin >> n >> m >> k;

    string a;
    for(int i=1; i<=n; i++) {
        cin >> a;
        for(int j=1; j<=m; j++) {
            so1[i][j]=a[j-1];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int k=0; k<3; k++) {
                so2[i][j][k]+=so2[i][j-1][k];
                so2[i][j][k]+=so2[i-1][j][k];
                so2[i][j][k]-=so2[i-1][j-1][k];
            }

            if(so1[i][j] == 'J') {
                so2[i][j][0]++;
            }
            else if(so1[i][j] == 'O') {
                so2[i][j][1]++;
            }
            else {
                so2[i][j][2]++;
            }
        }
    }

    int x,y,z,w;
    for(int i=0; i<k; i++) {
        cin >> x >> y >> z >> w;
        for(int j=0; j<3; j++) {
            cout << so2[z][w][j]-so2[x-1][w][j]-so2[z][y-1][j]+so2[x-1][y-1][j] << ' ';
        }
        cout << '\n';
    }

}

