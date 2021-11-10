// confusing brute force
#include <bits/stdc++.h>

using namespace std;

int so1[31][31];

int main() {
    int n,m,a;
    cin >> n >> m;

    vector <pair<int, int>> c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> so1[i][j];
        }
    }

    vector <int> ch[n];

    int maxi=0;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            for(int k=j+1; k<m; k++) {
                int cur=0;
                for(int l=0; l<n; l++) {
                     cur+=max(so1[l][i], max(so1[l][j], so1[l][k]));
                }
                if(cur>maxi) maxi=cur;
            }
        }
    }

    cout << maxi;
}
