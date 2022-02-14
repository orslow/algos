// bfs
#include <bits/stdc++.h>

using namespace std;

bool vis[1000003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    queue <pair<int, int>> qu;
    qu.push({s, 0});
    vis[s]=1;

    while(!qu.empty()) {
      int cur=qu.front().first, p=qu.front().second; qu.pop();
      if(cur==g) {
        cout << p;
        return 0;
      }
      if(cur+u<=f && vis[cur+u]==0) {
        if(cur+u==g) {
          cout << p+1;
          return 0;
        }
        qu.push({cur+u, p+1});
        vis[cur+u]=1;
      }
      if(cur-d>=1 && vis[cur-d]==0) {
        if(cur-d==g) {
          cout << p+1;
          return 0;
        }
        qu.push({cur-d, p+1});
        vis[cur-d]=1;
      }
    }
    cout << "use the stairs";
}
