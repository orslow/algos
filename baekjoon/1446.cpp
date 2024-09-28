#include <bits/stdc++.h>

using namespace std;

int n,d;

vector <pair<int, int> > road[10001];
int ans[10001];

int main() {
  cin >> n >> d;

  int a,b,c;
  for(int i=0; i<n; i++) {
    cin >> a >> b >> c;
    road[a].push_back(make_pair(b, c));
  }

  for(int i=0; i<d; i++)  {
    for(int j=0; j<road[i].size(); j++) {
      tie(b, c) = road[i][j];
      if (b>d) continue;
      if(ans[b]==0) {
	ans[b] = ans[i]+c;
      } else {
	ans[b] = min(ans[b], ans[i]+c);
      }
    }
    if(ans[i+1]==0) {
      ans[i+1]=ans[i]+1;
    } else {
      ans[i+1]=min(ans[i+1], ans[i]+1);
    }
  }

  cout << ans[d];
}
