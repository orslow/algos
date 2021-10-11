// binary search
#include <bits/stdc++.h>

using namespace std;

int so1[200003];

int n,m;

void bins(int a) {
    int l=0, r=n;

    while(l<=r) {
        int m=(l+r)/2;

        if(so1[m]>=a) {
            r=m-1;
        } else {
            l=m+1;
        }
    }

    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    set <int> s;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
        s.insert(so1[i]);
    }

    sort(so1, so1+n);

    int a;
    for(int i=0; i<m; i++) {
        cin >> a;
        if(s.find(a)==s.end()) {
            cout << -1 << '\n';
            continue;
        }
        bins(a);
    }
}
