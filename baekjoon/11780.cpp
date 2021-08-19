// floyd with route (must review sometime)
#include <bits/stdc++.h>

using namespace std;

int so1[101][101];
int so2[101][101];

void floyd(int n) {

    for(int c=1; c<=n; c++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(so1[i][c]+so1[c][j]<so1[i][j]) {
                    so2[i][j]=so2[i][c];
                    so1[i][j] = so1[i][c]+so1[c][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            so1[i][j]=987654321;
        }
    }

    for(int i=1; i<=n; i++) {
        so1[i][i]=0;
    }

    int a, b, c;
    while(m--) {
        cin >> a >> b >> c;
        if(c < so1[a][b]) {
            so1[a][b] = c;
        }
        so2[a][b] = b;
        // so1[a][b] = min(c, so1[a][b]);
        // so2[a][b] = a;
    }

    floyd(n);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(so1[i][j] == 987654321) cout << 0 << ' ';
            else cout << so1[i][j] << ' ';
        }
        cout << '\n';
    }

    /*
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << so2[i][j] << ' ';
        }
        cout << '\n';
    }
    */


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(so2[i][j] == 0) cout << 0;
            else {
                int cur=i;
                vector<int> rt;
                rt.push_back(cur);
                while(so2[cur][j] != j) {
                    cur=so2[cur][j];
                    rt.push_back(cur);
                }
                cout << rt.size() + 1 << ' ';
                for(auto v: rt) cout << v << ' ';
                cout << j;
            }
            cout << '\n';
        }
    }


}

