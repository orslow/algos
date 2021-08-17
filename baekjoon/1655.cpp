// min/max priority queue
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int> > minq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, cur, ch;
    cin >> n;

    cin >> cur;
    cout << cur << '\n';

    for(int i=1; i<n; i++) {
        cin >> s;

        if (s >= cur) minq.push(s);
        else maxq.push(s);


        ch=minq.size() - maxq.size();
        if (ch >= 2) {
            maxq.push(cur);
            cur = minq.top();
            minq.pop();
            cout << cur << '\n';
        }
        else if(ch <= 1 and ch >= 0) {
            cout << cur << '\n';
        }
        else {
            minq.push(cur);
            cur = maxq.top();
            maxq.pop();
            cout << cur << '\n';
        }

    }
}
