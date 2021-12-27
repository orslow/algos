// binary search
#include <bits/stdc++.h>

using namespace std;

int so1[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    long long l=0, r=2147483647;
    while(l<=r) {
        int m=(l+r)/2, cnt=0;

        if(m==0) break;

        for(int i=0; i<n; i++) {
            cnt+=so1[i]/m;
        }

        if(cnt<k) {
            r=m-1;
        } else {
            l=m+1;
        }
    }

    cout << r;
}
