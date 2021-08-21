// sort and make rule
#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > works;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, du, dl;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> du >> dl;
        works.push_back({dl, du});
    }

    sort(works.begin(), works.end(), greater<>());

    // for(auto w: works) cout << w.first << ' ' << w.second << '\n';

    dl=10000000;
    int cnt=0;
    for(auto w: works) {
        cnt++;
        int curt=w.first; int curu=w.second;

        // cout << curt << ' ' << curu << '\n';

        if(dl > curt) {
            dl = curt - curu;
        } else {
            dl = dl - curu;
        }

        // cout << dl << '\n';

        if(dl<0) break;
    }
    if(cnt==n && dl>=0) cout << dl << '\n';
    else cout << -1 << '\n';
}

