// floyd-warshall
#include <bits/stdc++.h>

using namespace std;

int vis[251][251];

int ans;

void floyd(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                if(vis[j][i]+vis[i][k]<vis[j][k]) vis[j][k]=vis[j][i]+vis[i][k];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) vis[i][j]=0;
            else vis[i][j]=987654321;
        }
    }

    int u,v,b;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> b;
        if(b==0) {
            vis[u][v]=0;
            if(vis[v][u]>1) vis[v][u]=1;
        } else {
            vis[u][v]=0;
            vis[v][u]=0;
        }
    }

    floyd(n);

    int k,s,e;
    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> s >> e;

        cout << vis[s][e] << '\n';
    }
}
