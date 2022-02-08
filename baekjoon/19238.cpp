// complex bfs
#include <bits/stdc++.h>

using namespace std;

int so1[22][22];
bool vis[22][22];

int mx[4]={1, 0, -1, 0};
int my[4]={0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,f;
    cin >> n >> m >> f;

    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        cin >> so1[i][j];
      }
    }

    int ux,uy,sx,sy,ex,ey;
    cin >> ux >> uy;

    multimap <pair<int, int>, pair<int, int>> mp;

    for(int i=0; i<m; i++) {
      cin >> sx >> sy >> ex >> ey;
      mp.insert ( pair<pair<int, int>, pair<int,int>>({sx, sy}, {ex, ey}) );
    }


    while(mp.size()) {

      queue <tuple<int, int, int>> qu;
      qu.push(make_tuple(ux, uy, 0));

      for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
          vis[i][j]=0;
        }
      }
      vis[ux][uy]=1;

      vector <tuple<int, int, int>> rs;
      while(!qu.empty()) {

        int x,y,dis;
        tie(x, y, dis)=qu.front(); qu.pop();

        if(mp.find({x, y}) != mp.end()) {
          rs.push_back(make_tuple(dis, x, y));
        }
        
        for(int i=0; i<4; i++) {

          int cx=x+mx[i], cy=y+my[i];

          if(cx<1 || cy<1 || cx>n || cy>n) continue;
          if(vis[cx][cy]==1 || so1[cx][cy]==1) continue;

          qu.push(make_tuple(cx, cy, dis+1));
          vis[cx][cy]=1;
        }
      }

      if(!rs.size()) {
        cout << -1;
        return 0;
      }

      sort(rs.begin(), rs.end());
      int dx,dy,dis;

      tie(dis, dx, dy)=rs[0];

      // int fx=mp[{dx, dy}].first, fy=mp[{dx, dy}].second;
      int fx=mp.find({dx, dy})->second.first, fy=mp.find({dx, dy})->second.second;

      if(dis>f) {
        cout << -1;
        return 0;
      }
      f-=dis;

      for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
          vis[i][j]=0;
        }
      }

      qu.push(make_tuple(dx, dy, 0));
      vis[dx][dy]=1;
      int cu=-1;
      while(!qu.empty() && cu==-1) {
        int x,y,dis;
        tie(x, y, dis)=qu.front(); qu.pop();

        if(x==fx && y==fy) {
          cu=dis;
          break;
        }
        
        for(int i=0; i<4; i++) {

          int cx=x+mx[i], cy=y+my[i];

          if(cx<1 || cy<1 || cx>n || cy>n) continue;
          if(vis[cx][cy]==1 || so1[cx][cy]==1) continue;

          qu.push(make_tuple(cx, cy, dis+1));
          vis[cx][cy]=1;
        }
      }

      if(cu==-1 || cu>f) {
        cout << -1;
        return 0;
      }
      mp.erase({dx, dy});
      f+=cu;

      ux=fx, uy=fy;
    }

    cout << f;
}
