// dp exercise still hard
#include <bits/stdc++.h>

using namespace std;

int vis[10001][500];
bool nav[10001];

bool can;

int n,m;

int go(int l, int s) {

    if(l==n) {
        can=1;
        return 0;
    }

    if(vis[l][s]!=-1) return vis[l][s];

    vis[l][s]=987654321;

    for(int i=-1; i<=1; i++) {

        if(s+i>0 && l+s+i<=n && nav[l+s+i]==0) {
            vis[l][s]=min(vis[l][s], go(l+s+i, s+i)+1);
        }
    }

    return vis[l][s];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int a;
    for(int i=0; i<m; i++) {
        cin >> a;
        nav[a]=1;
    }

    memset(vis, -1, sizeof(vis));


    int ans=go(1, 0);
    if(can) {
        cout << ans;
    } else {
        cout << -1;
    }
}
