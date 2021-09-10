// union-find
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int vis[500003];

pair<int, int> line[1000003];

int find_(int a) {
    if(vis[a]==a) return a;
    return find_(vis[a]);
}

void union_(int a, int b) {
    int x=find_(a);
    int y=find_(b);

    if(x>y) vis[x]=y;
    else vis[y]=x;
}

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        vis[i]=i;
    }

    int a, b;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        line[i]={a, b};
    }

    for(int i=1; i<=m; i++) {
        a=line[i].first;b=line[i].second;

        if(find_(a) == find_(b)) {
            cout << i;
            return 0;
        }
        union_(a, b);
        for(int j=0; j<=n; j++) {
            cout << vis[j] << ' ';
        }
        cout << '\n';
    }

    cout << 0;


}

