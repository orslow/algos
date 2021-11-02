// know when to use long long
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> a >> b;

    queue <pair<int, int>> qu;

    qu.push({a, 0});

    while(!qu.empty()) {
        long long cur=qu.front().first, cnt=qu.front().second;
        qu.pop();

        if(cur==b) {
            cout << cnt+1;
            return 0;
        }

        if(cur*10+1 <= b) {
            qu.push({cur*10+1, cnt+1});
        }
        if(cur*2 <= b) {
            qu.push({cur*2, cnt+1});
        }
    }

    cout << -1;
}
