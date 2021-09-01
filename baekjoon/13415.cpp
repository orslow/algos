// not fully understood yet
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[100005];
int ans[100005];

deque <pair<int, bool>> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l, r;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
        ans[i]=so1[i];
    }

    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> l >> r;
        while(!dq.empty() && dq.back().first <= l) dq.pop_back();
        if(l!=1) dq.push_back({l, 1});

        while(!dq.empty() && dq.back().first <= r) dq.pop_back();
        if(r!=1) dq.push_back({r, 0});
    }

    sort(so1, so1+dq.front().first);

    /*
    for(auto u: dq) {
        cout << u.first << ' ' << u.second << '\n';
    }

    for(int i=0; i<n; i++) {
        cout << so1[i] << ' ';
    }
    cout << '\n';
    */

    pair <int, bool> tmp;
    int len; bool dir;
    tmp=dq.front();dq.pop_front();
    int curl=tmp.first, curd=tmp.second;
    int ldx=0, rdx=curl-1;
    while(!dq.empty()) {
        tmp=dq.front();dq.pop_front();
        len=tmp.first; dir=tmp.second;

        // cout << curl << ' ' << curd << '\n';

        if(curd) { // 오름차순
            for(int i=curl-1; i>=len; i--) {
                ans[i]=so1[rdx--];
            }
        } else {
            for(int i=curl-1; i>=len; i--) {
                ans[i]=so1[ldx++];
            }
        }
        curd=dir;
        curl=len;
        /*
        for(int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        */

    }
    if(curd) { // 오름차순
        for(int i=curl-1; i>=0; i--) {
            ans[i]=so1[rdx--];
        }
    } else {
        for(int i=curl-1; i>=0; i--) {
            ans[i]=so1[ldx++];
        }
    }

    for(int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

}
