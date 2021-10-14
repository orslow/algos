// simulation
#include <bits/stdc++.h>

using namespace std;

int th[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u;
    cin >> n >> m;
    
    int ans=0;
    for(int i=0; i<n; i++) {
        cin >> u;
        if(u<m && m-u<=100000) {
            if(th[m-u]>0) {
                ans++;
            } else {
                th[u]++;
            }
        }
    }

    cout << ans;
}
