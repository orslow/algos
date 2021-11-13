// simulation
#include <bits/stdc++.h>

using namespace std;

int so1[2002];

vector <int> so2[2002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k,a;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> k;
        for(int j=0; j<k; j++) {
            cin >> a;
            so1[a]++;
            so2[i].push_back(a);
        }
    }

    for(int i=0; i<n; i++) {
        bool q=1;
        for(int j=0; j<so2[i].size(); j++) {
            if(so1[so2[i][j]]==1) {
                q=0;
                break;
            }
        }
        if(q==1) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}
