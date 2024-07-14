#include <bits/stdc++.h>

using namespace std;

int n,m,gx,gy;
int arr[1005][1005];
int vis[1005][1005];

void bfs() {
    queue<tuple<int, int, int>> qu;
    qu.push(make_tuple(gx, gy, 0));

    while(!qu.empty()) {
	int x,y,z;
	tie(x, y, z) = qu.front();
	qu.pop();
	if(vis[x][y]!=-1) continue;

	vis[x][y] = z;

	if(x+1<n && arr[x+1][y]!=0 && vis[x+1][y]==-1) {
	    qu.push(make_tuple(x+1, y, z+1));
	}
	if(y+1<m && arr[x][y+1]!=0 && vis[x][y+1]==-1) {
	    qu.push(make_tuple(x, y+1, z+1));
	}
	if(x-1>=0 && arr[x-1][y]!=0 && vis[x-1][y]==-1) {
	    qu.push(make_tuple(x-1, y, z+1));
	}
	if(y-1>=0 && arr[x][y-1]!=0 && vis[x][y-1]==-1) {
	    qu.push(make_tuple(x, y-1, z+1));
	}
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	    cin >> arr[i][j];
	    if(arr[i][j]==2) {
		gx=i;
		gy=j;
	    }
	}
    }

    for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	    vis[i][j] = -1;
	}
    }

    bfs();

    for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	    if(arr[i][j]==0) vis[i][j]=0;
	}
    }

    for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	    cout << vis[i][j] << " ";
	}
	cout << '\n';
    }
}
