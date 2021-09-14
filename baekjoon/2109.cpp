// priority queue / 10000 loop faster than i thought
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, d;
    cin >> n;

    for(int i=1; i<=10000; i++) {
        so1[i]=i;
    }

    priority_queue <pair<int, int>> pq;
    for(int i=0; i<n; i++) {
        cin >> p >> d;
        pq.push({p, d});
    }

    ll ans=0;
    while(!pq.empty()) {
        // cout << pq.top().first << ' ' << pq.top().second << '\n';
        int p=pq.top().first, d=pq.top().second;pq.pop();
        if(so1[d]>0) {
            bool pl=true;
            for(int i=d; i<=10000; i++) {
                if(so1[i]==0) {
                    pl=false;
                    break;
                }
            }
            if(pl) {
                ans+=p;
                for(int i=d; i<=10000; i++) {
                    so1[i]--;
                }
            }
        } else {
            continue;
        }
    }
    cout << ans;

}

