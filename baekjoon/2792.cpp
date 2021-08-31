// binary search
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int jew[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> jew[i];
    }

    sort(jew, jew+m);

    int l=1, r=jew[m-1], mid;
    while(l<=r) {
        mid=(l+r)/2;

        int cnt=0;
        for(int i=0; i<m; i++) {
            cnt+=jew[i]/mid;
            if(jew[i]%mid!=0) cnt++;
        }

        if(cnt>n) l=mid+1;
        else r=mid-1;
    }

    cout << l << '\n';
}

