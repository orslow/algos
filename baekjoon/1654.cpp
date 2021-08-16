// 애매하면 long long 쓰자
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int so1[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    int ma=0;
    for(int i=0; i<k; i++) {
        cin >> so1[i];
        // if(so1[i]>ma) ma = so1[i];
    }

    // sort(so1, so1+n);

    ll st=0, ed=2147483647, cad;
    ll mid;
    while(st<ed) {
        mid=(st+ed+1)/2;

        cad=0;
        for(int i=0; i<k; i++) {
            cad+=so1[i]/mid;
        }

        // cout << cad << '\n';

        if(cad>=n) st=mid;
        else ed=mid-1;
    }

    cout << st << '\n';
}

