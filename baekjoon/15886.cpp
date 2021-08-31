// math but graph problem
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string gol;
    cin >> gol;

    char cur=gol[0];
    int ans=0;
    for(int i=1; i<n; i++) {
        if(cur!=gol[i]) {
            if(cur=='E') ans++;
        }
        cur=gol[i];
    }
    if(gol[0]=='W') ans++;
    if(gol[n-1]=='E') ans++;

    cout << ans << '\n';
}

