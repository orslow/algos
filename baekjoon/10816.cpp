#include <bits/stdc++.h>

using namespace std;

int su[500001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cand;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> su[i];
    }

    sort(su, su+n);

    /*
    for(int i=0; i<n; i++) {
        cout << su[i] << ' ';
    }
    cout << '\n';
    */

    cin >> m;

    int st, ed, mid, li, ri;

    for(int i=0; i<m; i++) {

        cin >> cand;

        st=0; ed=n;
        while(st<ed) {
            // cout << st << ' ' << ed << '\n';
            mid = (st+ed)/2;

            if(cand <= su[mid]) {
                ed = mid;
            }
            else {
                st = mid+1;
            }
        }
        li=st;

        st=0; ed=n;
        while(st<ed) {
            // cout << st << ' ' << ed << '\n';
            mid = (st+ed)/2;

            if(cand < su[mid]) {
                ed = mid;
            }
            else {
                st = mid+1;
            }
        }
        ri=ed;

        // cout << ri << ' ' << li << '\n';

        cout << ri - li << '\n';

    }

}

