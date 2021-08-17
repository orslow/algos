// basic BFS(DFS)
#include <bits/stdc++.h>

using namespace std;

vector <int> cc[1001];
bool vis[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u, v, cur;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> u >> v;
        cc[u].push_back(v);
        cc[v].push_back(u);
    }

    queue <int> qu;
    int ans=0;
    for(int i=1; i<=n; i++) {

        if (vis[i]) continue;

        ans+=1;

        qu.push(i);
        vis[i]=1;
        while(!qu.empty()) {
            cur=qu.front();
            qu.pop();
            for(auto c: cc[cur]) {
                if(!vis[c]) {
                    qu.push(c);
                    vis[c]=1;
                }
            }
        }
    }

    cout << ans << '\n';
}

