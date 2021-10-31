// simulation with think
#include <bits/stdc++.h>

using namespace std;

set <int> s;

int so1[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
        s.insert(so1[i]);
    }

    int ans=1;
    for(int c: s) {
        int b=-1, cur=1;
        for(int i=0; i<n; i++) {
            if(so1[i]==c) continue;
            if(b==so1[i]) cur++;
            else {
                if(cur>ans) ans=cur;
                cur=1;
                b=so1[i];
            }
        }
        if(cur>ans) ans=cur;
    }

    cout << ans;

}
