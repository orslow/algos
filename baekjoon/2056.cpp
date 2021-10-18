// dp? array?
#include <bits/stdc++.h>

using namespace std;

int so1[10003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t,b,a;
    cin >> n;

    int ans=0;
    for(int i=1; i<=n; i++) {
        cin >> t >> b;

        int cm=0;
        for(int j=0; j<b; j++) {
            cin >> a;
            if(so1[a]>cm) cm=so1[a];
        }
        so1[i]=cm+t;
        if(so1[i]>ans) ans=so1[i];
    }

    cout << ans;
}
