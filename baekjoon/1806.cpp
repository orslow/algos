// basic two pointers #2
#include <bits/stdc++.h>

using namespace std;

int so1[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    int l=0, r=0, len=100001, cur=so1[0];
    while(l!=n && r!=n) {
        if(cur>=s) {
            // cout << cur << '\n';
            if(r-l<len) len=r-l;
            if(len==0) break;
            cur-=so1[l++];
        }
        else {
            cur+=so1[++r];
        }
    }

    if(len==100001) cout << 0 << '\n';
    else cout << len+1 << '\n';
}

