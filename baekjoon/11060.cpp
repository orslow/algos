// dp exercise
#include <bits/stdc++.h>

using namespace std;

int so1[1004];
int so2[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
      cin >> so1[i];
    }

    for(int i=1; i<n; i++) {
      so2[i]=-1;
    }

    for(int i=0; i<n; i++) {
      if(so2[i]==-1) continue;
      for(int j=1; j<=so1[i]; j++) {
        if(i+j>=n) break;
        if(so2[i+j]==-1) so2[i+j]=so2[i]+1;
        else so2[i+j]=min(so2[i+j], so2[i]+1);
      }
    }

    cout << so2[n-1];
}
