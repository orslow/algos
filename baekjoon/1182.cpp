#include <bits/stdc++.h>

using namespace std;

int per[20];
bool cont[20];

int n, s, cur=0, ans=0;

void suy(int k) {


    if (k == n) {

        /*
        for(int j=0; j<n; j++) {
            cout << cont[j] << ' ';
        }
        cout << '\n';
        cout << cur << '\n';
        */


        if (cur == s) {
            ans++;
        }
        return;
    }

    suy(k+1);
    cur+=per[k];
    // cont[k] = 1;
    suy(k+1);
    cur-=per[k];
    // cont[k] = 0;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> per[i];
    }

    if (s == 0) ans--;

    suy(0);

    cout << ans << '\n';
}

