#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[4005][4005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin >> a >> b;

    int n=a.length(), m=b.length(), ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i]==b[j]) so1[i+1][j+1]=so1[i][j]+1;
            if(so1[i+1][j+1]>ans) ans=so1[i+1][j+1];
        }
    }
    cout << ans;
}

