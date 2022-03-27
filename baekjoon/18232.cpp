// BFS exercise
#include <bits/stdc++.h>

using namespace std;

vector <int> so1[300005];
bool vis[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,s,e,x,y;
    cin >> n >> m >> s >> e;

    for(int i=0; i<m; i++) {
        cin >> x >> y;
        so1[x].push_back(y);
        so1[y].push_back(x);
    }

    queue <pair<int, int>> qu;
    qu.push(make_pair(s, 0));
    vis[s]=1;

    int pos, stp;
    while(1) {
        tie(pos, stp)=qu.front(); qu.pop();

        if(pos-1>0 && vis[pos-1]==0) {
            vis[pos-1]=1;
            if(pos-1==e) {
                cout << stp+1;
                return 0;
            }
            qu.push({pos-1, stp+1});
        }

        if(pos+1<=n && vis[pos+1]==0) {
            vis[pos+1]=1;
            if(pos+1==e) {
                cout << stp+1;
                return 0;
            }
            qu.push({pos+1, stp+1});
        }

        for(auto v: so1[pos]) {
            if(vis[v]==0) {
                vis[v]=1;
                if(v==e) {
                    cout << stp+1;
                    return 0;
                }
                qu.push({v, stp+1});
            }
        }
    }
}
