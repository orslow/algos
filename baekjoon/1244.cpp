// simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int sh[103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,g,w;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> sh[i];
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> g >> w;

        if(g==1) {
            int s=w;
            while(s<=n) {
                if(sh[s]==0) {
                    sh[s]=1;
                } else {
                    sh[s]=0;
                }
                s+=w;
            }
        } else {
            int st=w, ed=w;
            while(st>0 && ed<=n && sh[st]==sh[ed]) {
                if(sh[st]==0) {
                    sh[st]=1;
                    sh[ed]=1;
                } else {
                    sh[st]=0;
                    sh[ed]=0;
                }
                st--;
                ed++;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << sh[i] << ' ';
        if(i%20==0) {
            cout << '\n';
        }
    }

}
