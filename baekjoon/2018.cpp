// not two pointer method but solved
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int i=1, j=1, cur, ans=0;
    while(i<=n/2) {
        cur=i;
        j=1;
        while(cur<n) {
            cur=cur+i+j;
            j++;
        }
        if(cur==n) {
            ans++;
        }
        i++;
    }

    cout << ans+1 << '\n';
}

