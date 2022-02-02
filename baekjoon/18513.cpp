// all mistakes are from me
#include <bits/stdc++.h>

using namespace std;

bool vis[210100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,t;
    cin >> n >> k;

    // priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> qu;
    queue <tuple<int, int, int>> qu;
    for(int i=0; i<n; i++) {
      cin >> t;
      int loc=t+110000000;
      vis[loc]=1;
      qu.push(make_tuple(1, loc-1, 0));
      qu.push(make_tuple(1, loc+1, 1));
    }

    long long ans=0, loc, dis, dir;
    while(1) {
      tie(dis, loc, dir)=qu.front(); qu.pop();
      // cout << dis << ' ' << ans << '\n';
      // if(loc<0 || loc>200000000) continue;
      if(vis[loc]==1) {
        // if(dir) qu.push(make_tuple(dis+1, loc+1, 1));
        // else qu.push(make_tuple(dis+1, loc-1, 0));
        continue;
      }
      vis[loc]=1;
      ans+=dis;
      k--;
      if(k==0) break;
      if(dir) qu.push(make_tuple(dis+1, loc+1, 1));
      else qu.push(make_tuple(dis+1, loc-1, 0));
    }

    cout << ans;
}
