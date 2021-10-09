// simulation exercise
#include <bits/stdc++.h>

using namespace std;


int so1[43][43];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> so1[i][j];
        }
    }

    cin >> t;

    int ans=0;
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-2; j++) {

            vector <int> su;
            for(int k=i; k<i+3; k++) {
                for(int l=j; l<j+3; l++) {
                    su.push_back(so1[k][l]);
                }
            }
            sort(su.begin(), su.end());

            if(su[4]>=t) ans+=1;
        }
    }

    cout << ans;
}
