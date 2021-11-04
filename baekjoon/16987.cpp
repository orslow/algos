// little tricky backtracking
#include <bits/stdc++.h>

using namespace std;

pair<int, int> so1[10];

int n, ans;

void go(int k, int b) {

    if(b>ans) ans=b;

    if(k==n) {
        return;
    }

    if(so1[k].first<=0)  {
        go(k+1, b);
    }
    else {

        for(int i=0; i<n; i++) {
            if(i==k) continue;
            if(so1[i].first>0) {
                int d=0;
                so1[i].first-=so1[k].second;
                so1[k].first-=so1[i].second;
                if(so1[i].first<=0) d++;
                if(so1[k].first<=0) d++;
                go(k+1, b+d);
                so1[i].first+=so1[k].second;
                so1[k].first+=so1[i].second;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i].first >> so1[i].second;
    }

    go(0, 0);

    cout << ans;
}
