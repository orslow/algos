// easy
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c, l;
    cin >> n;

    int cow[11];
    for(int i=1; i<=10; i++) {
        cow[i]=-1;
    }

    int ans=0;
    while(n--) {
        cin >> c >> l;

        if(cow[c] != -1 && cow[c] != l) {
            ans++;
        }
        cow[c]=l;
    }

    cout << ans;

}
