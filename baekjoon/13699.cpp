// easy dp
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

ll nums[36];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    nums[0]=1;
    int s, e;
    for(int i=1; i<=n; i++) {
        s=0; e=i-1;

        ll tmp=0;
        while(s<i) {
            tmp+=nums[s]*nums[e];
            s++; e--;
        }
        nums[i]=tmp;
    }

    cout << nums[n] << '\n';
}
