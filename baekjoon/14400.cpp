// sort/distance
#include <bits/stdc++.h>

using namespace std;

int so1[100003];
int so2[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
      cin >> so1[i] >> so2[i];
    }

    sort(so1, so1+n);
    sort(so2, so2+n);

    int x=so1[n/2];
    int y=so2[n/2];

    long long ans=0;
    for(int i=0; i<n; i++) {
      ans+=abs(x-so1[i]);
      ans+=abs(y-so2[i]);
    }

    cout << ans;
}
