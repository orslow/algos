// dp hard to get idea (almost copied)
#include <bits/stdc++.h>

using namespace std;

int so1[33];
bool so2[33][15005];

int n;

void go(int i, int w) {
    if(i>n || so2[i][w]) return;
    so2[i][w]=1;
    go(i+1, w+so1[i]);
    go(i+1, abs(w-so1[i]));
    go(i+1, w);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }
    go(0, 0);

    int m,a;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> a;
        if(a>15000) cout << 'N';
        else if(so2[n][a]) cout << 'Y';
        else cout << 'N';
        cout << ' ';
    }
}

