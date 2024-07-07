#include <iostream>
#include <queue>

using namespace std;

int n, m, a, b;
int arr[103][103];
int dis[103]={0, };

bool vis[103];

void bfs(int s) {
  queue<int> qu;
  qu.push(s);
  vis[s]=1;

  while(!qu.empty()) {
    int u = qu.front();
    qu.pop();

    for(int i=1; i<=n; i++) {
      if(vis[i]==0 && arr[u][i]==1) {
	vis[i]=1;
	qu.push(i);
	dis[i] = dis[u]+1;
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for(int i=0; i<m; i++) {
    cin >> a >> b;
    arr[a][b]=1;
    arr[b][a]=1;
  }

  int md=123456789;
  int p;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      vis[j]=0;
      dis[j]=0;
    }
    bfs(i);
    int t=0;
    for(int j=1; j<=n; j++) {
      t+=dis[j];
    }
    if(t < md) {
      md=t;
      p=i;
    }
  }

  cout << p << '\n';
}
