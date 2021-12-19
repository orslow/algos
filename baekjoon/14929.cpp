// consider time complexity
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

    long long ans=0, cur=0;
    for(int i=n-1; i>0; i--) {
        cur+=so1[i];
        ans+=so1[i-1]*cur;
    }

    cout << ans;
}
