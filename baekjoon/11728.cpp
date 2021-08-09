// merge sort
#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int b[1000001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    int ad=0, bd=0;

    while(ad<n || bd<m) {
        if (a[ad] < b[bd]) cout << a[ad++] << ' ';
        else if (b[bd] < a[ad]) cout << b[bd++] << ' ';
        else cout << a[ad++] << ' ' << b[bd++] << ' ';

        if(ad==n) {
            while(bd<m) cout << b[bd++] << ' ';
        }
        if(bd==m) {
            while(ad<n) cout << a[ad++] << ' ';
        }
    }
    cout << '\n';
}


