#include <iostream>
#include <algorithm>

using namespace std;

int arr[505][505] = {0, };

int main() {
  int n;
  cin >> n;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<i+1; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<i+1; j++) {
      arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
    }
  }

  int ans=0;
  for(int i=1; i<=n; i++) {
    if(arr[n][i] > ans) {
      ans = arr[n][i];
    }
  }

  cout << ans;
}
