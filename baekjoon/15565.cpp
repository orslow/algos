// two pointer?
#include <bits/stdc++.h>

using namespace std;

priority_queue <int, vector<int>, greater<int> > pq;

int main() {

    int n, k;
    cin >> n >> k;

    int cur, su, ans=987654321;
    for(int i=0; i<n; i++) {
        cin >> cur;
        if(cur==1) {

            pq.push(i);
            if(pq.size() == k) {
                su=pq.top(); pq.pop();
                if(ans>i-su) ans=i-su;
            }

        }
    }
    if(ans==987654321) cout << -1 << '\n';
    else cout << ans+1 << '\n';
}

