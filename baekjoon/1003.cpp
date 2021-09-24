// easy dp / fib
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

pair<ll, ll> so1[43];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    so1[0]={1, 0};
    so1[1]={0, 1};

    for(int i=2; i<=40; i++) {
        so1[i]={so1[i-1].first+so1[i-2].first, so1[i-1].second+so1[i-2].second};
    }

    int t,n;
    cin >> t;

    while(t--) {
        cin >> n;
        cout << so1[n].first << ' ' << so1[n].second << '\n';
    }

}
