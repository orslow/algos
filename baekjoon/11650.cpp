// sort
#include <bits/stdc++.h>

using namespace std;

pair<int, int> so1[100003];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i].first >> so1[i].second;
    }

    sort(so1, so1+n);

    for(int i=0; i<n; i++) {
        cout << so1[i].first << ' ' << so1[i].second;
        cout << '\n';
    }
}
