// two pointer exercise
#include <bits/stdc++.h>

using namespace std;

int so1[3000003];
int so2[3003];

int main() {

    int n,d,k,c;
    cin >> n >> d >> k >> c;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    int u=0;
    for(int i=0; i<k; i++) {
        so2[so1[i]]++;
        if(so2[so1[i]]==1) u++;
    }

    int ans=0;
    for(int i=0; i<n-1; i++) {
        if(so2[c]) {
            if(u>ans) ans=u;
        } else {
            if(u+1>ans) ans=u+1;
        }
        so2[so1[i]]--;
        if(so2[so1[i]]==0) u--;
        so2[so1[(k+i)%n]]++;
        if(so2[so1[(k+i)%n]]==1) u++;
    }

    cout << ans;
}

