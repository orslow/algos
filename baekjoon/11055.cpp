// basic dp
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int soo[1005];
int hab[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> soo[i];
    }

    int ans=soo[0];
    for(int i=0; i<n; i++) {
        hab[i]=soo[i];
        for(int j=0; j<i; j++) {
            if(soo[i]>soo[j]) {
                hab[i]=max(hab[i], hab[j]+soo[i]);
                if(hab[i]>ans) ans = hab[i];
            }
        }
    }

    /*
    for(int i=0; i<n; i++) {
        cout << hab[i] << ' ';
    }
    cout << '\n';
    */

    cout << ans << '\n';
}
