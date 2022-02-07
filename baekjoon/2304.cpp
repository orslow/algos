// silver but not easy..
#include <bits/stdc++.h>

using namespace std;

int so1[1001];
int so2[1001];
int so3[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int l,h;
    for(int i=0; i<n; i++) {
      cin >> l >> h;
      so1[l]=h;
    }

    int cur=0;
    for(int i=1; i<=1000; i++) {
      if(so1[i]>cur) cur=so1[i];
      so2[i]=cur;
    }

    cur=0;
    for(int i=1000; i>0; i--) {
      if(so1[i]>cur) cur=so1[i];
      so3[i]=cur;
    }

    int ans=0;
    for(int i=1; i<=1000; i++) {
      ans+=min(so2[i], so3[i]);
    }

    cout << ans;
}
