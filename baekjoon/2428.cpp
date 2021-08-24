// binary search idea..
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int n;

double so1[100001];

int bs(int i, double val) {
    int l=0;
    int r=i-1;

    while(l<=r) {
        int mid=(l+r)/2;

        if(so1[mid] < val*0.9) {
            l=mid+1;
        } else {
            r=mid-1;
        }
    }

    return i-l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    sort(so1, so1+n);

    ll ans=0;
    for(int i=0; i<n; i++) ans+=bs(i, so1[i]);
    cout << ans << '\n';

}

