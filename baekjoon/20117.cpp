// get idea
#include <bits/stdc++.h>

using namespace std;

int so1[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    sort(so1, so1+n);

    int l=0, r=n-1, ans=0;
    while(l<r) {
        ans+=so1[r]*2;
        l++; r--;
    }
    if(l==r) ans+=so1[l];

    cout << ans;
}
