// simple but hard to get idea
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

vector <pair<int, int>> so1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll tot=0;
    int x, a;
    for(int i=0; i<n; i++) {
        cin >> x >> a;
        tot+=a;
        so1.push_back({x, a});
    }

    sort(so1.begin(), so1.end());

    ll ls=0, tu;
    for(int i=0; i<n; i++) {
        ls+=so1[i].second;
        tot-=so1[i].second;

        if(ls>=tot) {
            tu=i;
            break;
        }
    }

    cout << so1[tu].first << '\n';

}
