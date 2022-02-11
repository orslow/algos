// easy bfs
#include <bits/stdc++.h>

using namespace std;

vector <int> so1[100003];
bool vis[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int a,b;
    for(int i=0; i<m; i++) {
      cin >> a >> b;
      so1[b].push_back(a);
    }

    int c;
    cin >> c;

    queue <int> qu;
    qu.push(c);
    vis[c]=1;

    int ans=0;
    while(!qu.empty()) {
      int cur=qu.front(); qu.pop();

      for(auto v: so1[cur]) {
        if(vis[v]==1) continue;
        vis[v]=1;
        ans++;
        qu.push(v);
      }
    }

    cout << ans;
}
