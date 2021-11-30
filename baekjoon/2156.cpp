// dp still hard
#include <bits/stdc++.h>

using namespace std;

int so1[10003];
int so2[10003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> so1[i];
    }

    so2[1]=so1[1];
    so2[2]=so1[1]+so1[2];

    for(int i=3; i<=n; i++) {
        so2[i]=max(so2[i-3]+so1[i-1]+so1[i], so2[i-2]+so1[i]);
        so2[i]=max(so2[i-1], so2[i]);
    }

    cout << so2[n];

}
