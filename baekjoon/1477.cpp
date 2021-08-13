// help from https://kau-algorithm.tistory.com/136 => try again someday
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
set <int> hg;
priority_queue<pair<double, int> > pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, l, h, cur, div;
    cin >> n >> m >> l;

    for(int i=0; i<n; i++) {
        cin >> h;
        hg.insert(h);
    }

    cur=0;
    for(auto a: hg) {
        pq.push({a - cur, 1});
        cur = a;
    }
    pq.push({l - cur, 1});

    pair<double, int> tmp;
    double dis;
    while(m--) {
        tmp = pq.top();
        dis = tmp.first; div = tmp.second;
        pq.pop();

        pq.push({ dis*div / (div+1), div+1});
    }

    cout << ceil(pq.top().first) << '\n';

}

