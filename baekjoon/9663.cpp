#include <iostream>
#include <cstring>

using namespace std;

bool id0[15];
bool id1[28];
bool id2[28];

int n, ans=0;

void bt(int k) {
    // cout << "K: " << k << '\n';
    if(k==n) {
        ans++;
        return;
    }

    for(int i=0; i<n; i++) {
        if(id0[i] || id1[i+k] || id2[i-k+n-1]) continue;
        id0[i] = 1;
        id1[i+k] = 1;
        id2[i-k+n-1] = 1;
        // cout << i << " " << k << '\n';
        bt(k+1);
        id0[i] = 0;
        id1[i+k] = 0;
        id2[i-k+n-1] = 0;
    }
}


int main() {

    cin >> n;

    bt(0);

    cout << ans << '\n';

}
