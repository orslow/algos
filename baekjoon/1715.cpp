// easy but wrong
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> pq;
    int c, d;
    for(int i=0; i<n; i++) {
        cin >> c;
        pq.push(c);
    }

    ll ans=0, cur;
    while(pq.size()!=1) {
        c=pq.top();pq.pop();
        d=pq.top();pq.pop();
        pq.push(c+d);
        ans+=c+d;
    }
    cout << ans;
}
