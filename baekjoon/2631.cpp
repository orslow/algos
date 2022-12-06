// Sense LIS
#include <bits/stdc++.h>

using namespace std;

int so1[203];
int so2[203];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        so2[i]=1;

        for(int j=0; j<i; j++) {
            if(so1[i]>so1[j] && so2[i]<so2[j]+1) {
                so2[i]=so2[j]+1;
            }
        }
        if(so2[i]>ans) ans=so2[i];
    }

    cout << n-ans;
}
