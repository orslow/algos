// need more tree exercise
#include <bits/stdc++.h>

using namespace std;

vector <int> so1[100001];
int so2[100001];

void dfs(int c) {
    for(int v: so1[c]) {
        if(so2[c]==v) continue;
        so2[v]=c;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        so1[a].push_back(b);
        so1[b].push_back(a);
    }
    dfs(1);

    for(int i=2; i<=n; i++) {
        cout << so2[i] << '\n';
    }
}
