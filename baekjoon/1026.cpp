// basic sort
#include <bits/stdc++.h>

using namespace std;

int a[51];
int b[51];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+n, cmp);

    int ans=0;
    for(int i=0; i<n; i++) {
        ans += a[i]*b[i];
    }

    cout << ans << '\n';

}


