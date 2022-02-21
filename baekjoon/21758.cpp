// prefix sum
#include <bits/stdc++.h>

using namespace std;

int so1[100001];
int so2[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
      cin >> so1[i];
      so2[i]=so2[i-1]+so1[i];
    }

    int ans=0;

    // o o x
    for(int i=2; i<n; i++) {
      ans=max(ans, so2[n]-so1[1]-so1[i]+so2[n]-so2[i]);
    }

    // o x o
    for(int i=2; i<n; i++) {
      ans=max(ans, so2[i]-so1[1]+so2[n]-so1[n]-so2[i-1]);
    }

    // x o o
    for(int i=2; i<n; i++) {
      ans=max(ans, so2[n]-so1[n]-so1[i]+so2[i]-so1[i]);
    }

    cout << ans;
}
