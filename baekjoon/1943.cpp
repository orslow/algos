// knapsack - hard to get idea
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

pair<int, int> so1[50005];
int ab[50005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=3;
    while(t--) {
        int n;
        cin >> n;

        int tsum=0;
        for(int i=0; i<n; i++) {
            cin >> so1[i].first >> so1[i].second;
            tsum+=so1[i].first*so1[i].second;
        }

        if(tsum%2!=0) {
            cout << 0 << '\n';
            continue;
        }

        ab[0]=1;
        int w,c;
        for(int j=0; j<n; j++) {
            for(int i=50000; i>=0; i--) {
                if(ab[i]==1) {
                    w=so1[j].first;c=so1[j].second;
                    for(int k=1; k<=c; k++) {
                        if(i+w*k<=50000) {
                            ab[i+w*k]=1;
                            // cout << i+w*k << ": " << ab[i+w*k] << '\n';
                        }
                    }
                }
            }
        }
        cout << ab[tsum/2] << '\n';
        for(int i=0; i<=50000; i++) {
            ab[i]=0;
        }
    }

}
