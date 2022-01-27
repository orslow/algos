// basic TSP
#include <bits/stdc++.h>

using namespace std;

int ans=987654321;

int so1[11][11];

int n;

void st(int cur, int end, int cost, vector <bool> vis) {

    if(cur==end && cost!=0) {
        bool done=1;
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                done=0;
                break;
            }
        }
        if(done && ans>cost) ans=cost;
        return;
    }

    for(int i=0; i<n; i++) {
        if(so1[cur][i]==0) continue;
        if(vis[i]==0) {
            vis[i]=1;
            st(i, end, cost+so1[cur][i], vis);
            vis[i]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> so1[i][j];
        }
    }

    vector <bool> vis(11);

    for(int i=0; i<n; i++) {
        for(int i=0; i<n; i++) {
            vis[i]=0;
        }
        st(i, i, 0, vis);
    }

    cout << ans;
}
