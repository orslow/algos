// simulation(two pointer?)
#include <bits/stdc++.h>

using namespace std;

int so1[200001];
int so2[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,a;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    int c=0, ans=0;
    for(int i=0; i<n; i++) {
        so2[so1[i]]++;
        if(so2[so1[i]]>k) {
            if(ans<i-c) ans=i-c;
            for(int j=c; j<=i; j++) {
                so2[so1[j]]--;
                if(so1[j]==so1[i]) {
                    c=j+1;
                    break;
                }
            }
        }
    }
    if(ans<n-c) ans=n-c;

    cout << ans;
}
