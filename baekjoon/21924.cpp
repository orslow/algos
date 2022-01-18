// MST(kruskal)
#include <bits/stdc++.h>

using namespace std;

int vis[100001];

int find(int a) {
    if(vis[a]==0) return a;
    return vis[a]=find(vis[a]);
}

vector <tuple<int, int, int>> so1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int a,b,c;
    long long ans=0;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        so1.push_back(make_tuple(c,a,b));
        ans+=c;
    }

    sort(so1.begin(), so1.end());

    /*
    cout << '\n';
    for(int i=0; i<m; i++) {
        tie(c, a, b)=so1[i];
        cout << c << ' ' << a << ' ' << b << '\n';
    }
    */

    int cnt=0;
    for(int i=0; i<m; i++) {
        tie(c, a, b)=so1[i];
        int ac=find(a), bc=find(b);
        if(ac==bc) continue;
        vis[bc]=ac;
        ans-=c;
        cnt++;
        if(cnt==n-1) {
            cout << ans;
            return 0;
        }
    }

    cout << -1;
}
