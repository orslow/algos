// binary search with side case
#include <bits/stdc++.h>

using namespace std;

int so1[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    long long l=1, r=1000000000;

    int cur=0, cnt=0;
    while(l<=r) {
        int mid=(l+r)/2;

        int cur=0, cnt=1;
        bool bi=0;
        for(int i=0; i<n; i++) {
            if(so1[i]>mid) {
                bi=1;
                break;
            }
            if(cur+so1[i]<=mid) {
                cur+=so1[i];
            } else {
                cur=so1[i];
                cnt++;
                if(cnt>m) {
                    bi=1;
                    break;
                }
            }
        }
        if(bi) l=mid+1;
        else r=mid-1;
    }

    cout << l;
}
