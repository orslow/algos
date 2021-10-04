// easy sort
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[100003];

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    sort(so1, so1+n, cmp);

    ll ans=0;
    for(int i=0; i<n; i++) {
        if(so1[i]-i<0) break;
        ans+=so1[i]-i;
    }
    cout << ans;
}
