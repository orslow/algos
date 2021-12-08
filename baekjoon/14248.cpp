// bfs
#include <bits/stdc++.h>

using namespace std;

int so1[100003];

bool vis[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,c;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> so1[i];
    }

    cin >> c;

    queue <int> qu;
    qu.push(c);
    vis[c]=1;

    while(!qu.empty()) {
        int cur=qu.front();qu.pop();

        if(cur+so1[cur]<=n && cur+so1[cur]>=1 && vis[cur+so1[cur]]!=1) {
            vis[cur+so1[cur]]=1;
            qu.push(cur+so1[cur]);
        }

        if(cur-so1[cur]<=n && cur-so1[cur]>=1 && vis[cur-so1[cur]]!=1) {
            vis[cur-so1[cur]]=1;
            qu.push(cur-so1[cur]);
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++) {
        if(vis[i]==1) ans++;
    }

    cout << ans;


}
