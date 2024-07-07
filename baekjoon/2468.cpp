#include <iostream>

using namespace std;

int n;
int arr[104][104] = {0, };
int flood[104][104] = {0, };

void bfs(int i, int j) {
  if(j+1 < n && flood[i][j+1] == 0) {
    flood[i][j+1] = 2;
    bfs(i, j+1);
  }
  if(i+1 < n && flood[i+1][j] == 0) {
    flood[i+1][j] = 2;
    bfs(i+1, j);
  }
  if(j-1 >= 0 && flood[i][j-1] == 0) {
    flood[i][j-1] = 2;
    bfs(i, j-1);
  }
  if(i-1 >= 0 && flood[i-1][j] == 0) {
    flood[i-1][j] = 2;
    bfs(i-1, j);
  }
}

int main() {
  cin >> n;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> arr[i][j];
    }
  }

  int ans=1;
  for(int k=1; k<=100; k++) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
	if (arr[i][j] <= k) {
	  flood[i][j] = 1;
	}
      }
    }

    int tmp=0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
	if (flood[i][j] == 0) {
	  flood[i][j]=2;
	  bfs(i, j);
	  tmp++;
	}
      }
    }

    if (tmp > ans) {
      ans = tmp;
    }

    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
	flood[i][j] = 0;
      }
    }
  }

  cout << ans << '\n';
}
