// basic dp
#include <bits/stdc++.h>

using namespace std;

int so1[1004];
int vis[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
      cin >> so1[i];
    }

    int ans=0;
    for(int i=0; i<n; i++) {
      int c=vis[i], v=so1[i];
      for(int j=i+1; j<n; j++) {
        if(v<so1[j] && c+1>vis[j]) {
          vis[j]=c+1;
          if(c+1>ans) ans=c+1;
        }
      }
    }

    cout << ans+1;
}
