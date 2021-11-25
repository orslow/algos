// brute force / sort
#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,w,s;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> w >> s;
        m.push_back({w,s});
    }

    sort(m.begin(), m.end());

    int ans=0, ee=0;
    for(int i=0; i<n; i++) {
        int cur=m[i].first, np=0;
        for(int j=0; j<n; j++) {
            if(m[j].first>=cur) {
                if(cur-m[j].second>0) {
                    np+=(cur-m[j].second);
                }
            }
        }
        if(np>ee) {
            ee=np;
            ans=cur;
        }
    }

    cout << ans;
}
