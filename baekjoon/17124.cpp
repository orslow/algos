// binary search
#include <bits/stdc++.h>

using namespace std;

int so1[1000003];
int so2[1000003];


int sbs(int l, int r, int a) {
    int m=(l+r)/2;

    if(so2[m]==a) return so2[m];

    if(so2[m]<a) {
        if(m==r) return so2[m];
        return max(so2[m], sbs(m+1, r, a));
    } else {
        if(l==m) return so2[0];
        return sbs(l, m-1, a);
    }
}

int lbs(int l, int r, int a) {
    int m=(l+r)/2;

    if(so2[m]==a) return so2[m];

    if(so2[m]>a) {
        if(m==l) return so2[m];
        return min(so2[m], lbs(l, m-1, a));
    } else {
        if(m==r) return 1000000004;
        return lbs(m+1, r, a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n,m;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        for(int i=0; i<n; i++) {
            cin >> so1[i];
        }

        for(int i=0; i<m; i++) {
            cin >> so2[i];
        }

        sort(so2, so2+m);

        long long ans=0;
        for(int i=0; i<n; i++) {
            int c1=sbs(0, m-1, so1[i]);
            int c2=lbs(0, m-1, so1[i]);

            if(abs(so1[i]-c1) <= abs(so1[i]-c2)) {
                ans+=c1;
            } else {
                ans+=c2;
            }
        }

        cout << ans << '\n';
    }
}
