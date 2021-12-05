// simulation with idea
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int a,b,ans;

void go(ll num) {

    if(num>b) return;

    if(num>=a) ans++;

    go(num*10+4);
    go(num*10+7);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    
    go(4);
    go(7);

    cout << ans;
}
