// distinguish cycle
#include <bits/stdc++.h>

using namespace std;

bool vis[501];
vector <int> so1[501];


bool go(int cur, int par) {
  vis[cur]=1;

  for(int v: so1[cur]) {
    if(v==par) continue;
    if(vis[v]==1) return 0;
    if(go(v, cur)==0) return 0;
  }
  return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t=1;
    while(1) {
      int n,m;
      cin >> n >> m;

      if(n==0 && m==0) return 0;

      int a,b;
      for(int i=0; i<m; i++) {
        cin >> a >> b;
        so1[a].push_back(b);
        so1[b].push_back(a);
      }

      int ans=0;
      for(int i=1; i<=n; i++) {
        if(vis[i]==0) {
          if(go(i, 0)) ans++;
        }
      }

      cout << "Case " << t << ": ";
      if(ans==0) {
        cout << "No trees.";
      } else if(ans==1) {
        cout << "There is one tree.";
      } else {
        cout << "A forest of " << ans << " trees.";
      }
      cout << '\n';

      for(int i=1; i<=n; i++) {
        so1[i].clear();
        vis[i]=0;
      }

      t++;
    }
}
