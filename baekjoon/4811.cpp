// dp - should review
#include <bits/stdc++.h>

using namespace std;

long long so1[31][31]; // w, h

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<=30; i++) {
        so1[0][i]=1;
    }

    for(int i=1; i<=30; i++) {
        for(int j=0; j<=30; j++) {
            if(j==0) {
                so1[i][j]=so1[i-1][1];
            } else {
                so1[i][j]=so1[i-1][j+1]+so1[i][j-1];
            }
        }
    }

    int n;
    while(true) {
        cin >> n;
        if(n==0) break;
        cout << so1[n-1][1] << '\n';
    }
}
