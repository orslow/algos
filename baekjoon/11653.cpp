// 소인수 분해(에라토스테네스 관련)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n;

    s=n;
    for(int i=2; i*i<=n; i++) {
        if(s==1) break;
        while(s%i==0) {
            cout << i << '\n';
            s/=i;
        }
    }
    if(s!=1) cout << s << '\n';

}
