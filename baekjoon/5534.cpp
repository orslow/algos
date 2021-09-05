// simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

string w, g;
bool tt;

void fd(int ni, int wi, int gap) {
    // cout << ni << ' ' << wi << ' ' << gap << '\n';
    bool ans=false;
    if(wi==w.length()) {
        tt=true;
    }
    for(int i=ni+1; i<g.length(); i++) {
        if(g[i]==w[wi]) {
            if(gap==-1 || gap==i-ni) {
                fd(i, wi+1, i-ni);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans=0;
    cin >> n;

    cin >> w;
    while(n--) {
        cin >> g;

        tt=false;
        for(int i=0; i<g.length(); i++) {
            if(g[i]==w[0]) {
                fd(i, 1, -1);
            }
        }
        if(tt) ans++;

    }

    cout << ans << '\n';
}
