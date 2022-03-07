// dp solved from search
#include <bits/stdc++.h>

using namespace std;

int so1[102];
int so2[20002];
int so3[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int a;
    for(int i=0; i<m; i++) {
      cin >> so1[i];
    }

    for(int i=0; i<m; i++) {
      so2[so1[i]]=1;
      for(int j=i+1; j<m; j++) {
        so2[so1[i]+so1[j]]=1;
      }
    }

    for(int i=1; i<=n; i++) so3[i]=987654321;

    for(int i=1; i<=n; i++) {
      if(so2[i]==0) continue;
      for(int j=i; j<=n; j++) {
        if(so3[j-i]+1<so3[j]) so3[j]=so3[j-i]+1;
      }
    }

    if(so3[n]!=987654321) cout << so3[n];
    else cout << -1;
}
