#include <bits/stdc++.h>

using namespace std;

int so1[100001];
int err[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q,x,y;
    cin >> n;

    int r=0, bef=0;
    for(int i=1; i<=n; i++) {
        cin >> so1[i];
        if(bef>so1[i]) {
            r++;
        }
        err[i-1]=r;
        bef=so1[i];
    }
    err[n]=r;

    /*
    for(int i=1; i<=n; i++) {
        cout << err[i] << ' ';
    }
    cout << '\n';
    */

    cin >> q;
    while(q--) {
        cin >> x >> y;
        cout << err[y-1]-err[x-1] << '\n';
    }
}
