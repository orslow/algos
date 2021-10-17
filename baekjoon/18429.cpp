// simulation, backtracking
#include <bits/stdc++.h>

using namespace std;

int n,k,ans;

int so1[10];
bool vis[10];

void go(int idx, int cur) {

    if(cur<500) return;

    if(idx==n) {
        ans++;
        return;
    }

    for(int i=0; i<n; i++) {
        if(vis[i]==1) continue;
        vis[i]=1;
        go(idx+1, cur+so1[i]-k);
        vis[i]=0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    go(0, 500);

    cout << ans;
}
