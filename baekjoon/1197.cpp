// minimum spanning tree - kruskal/union find
#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> ver[100001];
int g[100001];

int fg(int n) {
    if(g[n] == n) return n;
    g[n] = fg(g[n]);
    return g[n];
}

bool sg(int a, int b) {
    a=fg(a); b=fg(b);
    if(a==b) return 1;
    g[b]=g[a];
    return 0;
}

int main() {

    int v, e, a, b, c;
    cin >> v >> e;

    for(int i=0; i<e; i++) {
        cin >> a >> b >> c;
        ver[i] = make_tuple(c, a, b);
    }

    sort(ver, ver+e);

    for(int i=1; i<=v; i++) {
        g[i]=i;
    }

    int cnt=0, cost=0;
    for(int i=0; i<e; i++) {
        tie(a, b, c) = ver[i];
        if(!sg(b, c)) {
            cost+=a;
            cnt++;
        }
        if(cnt==v-1) {
            cout << cost << '\n';
            return 0;
        }
    }
}

