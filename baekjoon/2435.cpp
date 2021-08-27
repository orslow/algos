// easy bruteforce
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int temp[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> temp[i];
    }

    int cur=0;
    for(int i=0; i<k; i++) {
        cur+=temp[i];
    }

    int l=0, r=k, ans=cur;
    while(r<n) {
        cur-=temp[l++];
        cur+=temp[r++];
        if(cur>ans) ans=cur;
    }

    cout << ans << '\n';
}
