// binary search
#include <bits/stdc++.h>

using namespace std;

int so1[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int l=1, r=0;
    for(int i=0; i<n; i++) {
        cin >> so1[i];
        r+=so1[i];
    }

    while(l<=r) {
        int mid=(l+r)/2;

        int cur=0, cnt=0;
        for(int i=0; i<n; i++) {
            if(so1[i]>mid) {
                cnt=m+1;
                break;
            }
            if(so1[i]>cur) {
                cur=mid-so1[i];
                cnt++;
            } else {
                cur-=so1[i];
            }
        }
        if(cnt>m) {
            l=mid+1;
        } else {
            r=mid-1;
        }
    }

    cout << l;
}
