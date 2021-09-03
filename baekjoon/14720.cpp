#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cur, ans=0;
    cin >> n;

    cin >> m;
    n--;
    while(n && m!=0) {
        cin >> m;
        n--;
    }
    if(n==0) {
        cout << 0;
        return 0;
    }
    ans++;

    while(n--) {
        cin >> cur;
        if(m==0 && cur==1) {
            m=1;
            ans++;
        } else if(m==1 && cur==2) {
            m=2;
            ans++;
        } else if(m==2 && cur==0) {
            m=0;
            ans++;
        }
    }
    cout << ans;
}

