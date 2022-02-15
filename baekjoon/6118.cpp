// basic bfs
#include <bits/stdc++.h>

using namespace std;

vector <int> so1[20005];
int vis[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int a,b;
    for(int i=0; i<m; i++) {
      cin >> a >> b;
      so1[a].push_back(b);
      so1[b].push_back(a);
    }

    queue <pair<int, int>> qu;
    qu.push({1, 0});
    vis[1]=-1;

    int ans=0;
    while(!qu.empty()) {
      int cur=qu.front().first, dis=qu.front().second; qu.pop();

      for(int v: so1[cur]) {
        if(vis[v]!=0) continue;
        vis[v]=dis+1;
        qu.push({v, dis+1});
        if(dis+1>ans) ans=dis+1;
      }
    }

    int cnt=0, num=0;
    for(int i=1; i<=n; i++) {
      if(vis[i]==ans) {
        cnt++;
        if(num==0) num=i;
      }
    }

    cout << num << ' ' << ans << ' ' << cnt;
}
