// union-find exercise
#include <bits/stdc++.h>

using namespace std;

int so1[100005];
int so2[100005];
int so3[100005];

int _find(int a) {

    if(so1[a]==a) return a;

    return so1[a]=_find(so1[a]);
}

void _union(int a, int b) {
    int c=_find(a);
    int d=_find(b);

    if(c==d) return;

    if(so2[c]<so2[d]) swap(c, d);
    so1[d]=c;

    if(so2[c]==so2[d]) so2[c]++;

}

int main() {

    int n,m,a,b;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        so1[i]=i;
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        _union(a, b);
    }

    for(int i=0; i<n; i++) {
        cin >> so3[i];
    }

    int c=so3[0];
    int ans=0;
    for(int i=1; i<n; i++) {
        if(_find(c) != _find(so3[i])) ans++;
        c=so3[i];
    }

    cout << ans;
}

