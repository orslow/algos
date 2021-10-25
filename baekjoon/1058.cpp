// graph, simulation
#include <bits/stdc++.h>

using namespace std;

char so1[51][51];
bool so2[51][51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            so1[i][j]=s[j];
        }
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(so1[i][j]=='Y') {
                so2[i][j]=1;
                for(int k=0; k<n; k++) {
                    if(so1[j][k]=='Y') so2[i][k]=1;
                }
            }
        }
        int cur=0;
        for(int j=0; j<n; j++) {
            if(so2[i][j]==1) cur++;
        }
        if(cur-1>ans) ans=cur-1;
    }

    cout << ans;
}
