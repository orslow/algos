// backtracking(check visit)
#include <bits/stdc++.h>

using namespace std;

int n;

set <int> su;

bool vis[21][1001];

int so[4]={1, 5, 10, 50};

void go(int c, int s) {
    if(c==n) {
        su.insert(s);
        return;
    }

    for(int i=0; i<4; i++) {
        if(!vis[c+1][s+so[i]]) {
            vis[c+1][s+so[i]]=1;
            go(c+1, s+so[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    go(0, 0);

    cout << su.size();
}
