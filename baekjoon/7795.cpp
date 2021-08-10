// sort
#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) { return a > b;}

string guitars[1001];

int sa[20001];
int sb[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, ac, bc, ans;
    cin >> t;

    while(t--) {

        cin >> n >> m;

        for(int i=0; i<n; i++) {
            cin >> sa[i];
        }

        for(int i=0; i<m; i++) {
            cin >> sb[i];
        }

        sort(sa, sa+n, cmp);
        sort(sb, sb+m, cmp);


        ac=0; bc=0; ans=0;
        // for(int i=0; i<n; i++) {
        while(ac<n && bc<m) {

            while(bc < m && sa[ac] <= sb[bc]) {
                bc++;
            }

            ans += m-bc;

            ac++;
        }

        cout << ans << '\n';

    }


}


