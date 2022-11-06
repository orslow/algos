// basic sort
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,c,d,u;
    cin >> n >> m >> c;

    vector <int> a, b;
    for(int i=0; i<c; i++) {
        cin >> d >> u;
        if(d==0) {
            a.push_back(u);
        } else {
            b.push_back(u);
        }
    }

    a.push_back(0);
    a.push_back(m);
    b.push_back(0);
    b.push_back(n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans=0;
    for(int i=0; i<a.size()-1; i++) {
        int cx=a[i+1]-a[i];
        for(int j=0; j<b.size()-1; j++) {
            int cy=b[j+1]-b[j];
            if(cx*cy>ans) ans=cx*cy;
        }
    }
    cout << ans;
}
