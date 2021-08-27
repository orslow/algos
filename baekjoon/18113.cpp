// basic binary search still hard to apply
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int su[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    int gbp;
    int c=0;
    while(n--) {
        cin >> gbp;
        if(gbp>k*2) {
            gbp-=k*2;
            su[c++]=gbp;
        } else if(gbp<k*2 && gbp>k) {
            gbp-=k;
            su[c++]=gbp;
        }
    }

    // sort(su, su+c);

    /*
    for(int i=0; i<c; i++) {
        cout << su[i] << ' ';
    }
    cout << "\n";
    */

    int u=-1, mid, l=1, r=1000000000;
    while(l<=r) {
        mid=(l+r)/2;

        int cnt=0;
        bool big=false;
        for(int i=0; i<c; i++) {
            cnt += su[i]/mid;
        }
        if(cnt>=m) { 
            u=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    cout << u << '\n';

}

