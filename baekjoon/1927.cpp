// basic min queue
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

priority_queue<int, vector<int>, greater<int> > minq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cmd;
    cin >> n;

    while(n--) {
        cin >> cmd;

        if(cmd==0) {
            if(!minq.empty()) {
                cout << minq.top() << '\n';
                minq.pop();
            }
            else cout << 0 << '\n';
        }
        else {
            minq.push(cmd);
        }
    }
}

