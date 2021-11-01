// sort
#include <bits/stdc++.h>

using namespace std;

int so1[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,s;
    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    sort(so1, so1+n);

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(so1[i]+so1[j]<=s) ans++;
            else break;
        }
    }
    cout << ans;
}
