// brute force
#include <bits/stdc++.h>

using namespace std;

int so1[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    int ans=n;
    for(int i=0; i<n; i++) {
        int cur=0;
        for(int j=0; j<n; j++) {
            int t=k*(j-i)+so1[i];

            if(t<1) {
                cur=n;
                break;
            }
            if(t!=so1[j]) cur++;
        }
        if(cur<ans) {
            ans=cur;
        }
    }

    cout << ans;
}
