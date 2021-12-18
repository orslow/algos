// dp?
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    while(1) {
        cin >> n;
        if(n==0) return 0;

        int p=-987654321;
        int cur=0;
        for(int i=0; i<n; i++) {
            cin >> a;
            cur+=a;
            if(cur>p) p=cur;
            if(cur<0) cur=0;
        }
        cout << p << '\n';
    }

}
