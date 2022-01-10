// hard to get idea
#include <bits/stdc++.h>

using namespace std;

int so1[1001];
int so2[1001];
int po1[1000001];
int po2[1000001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,k,n;
    cin >> t;

    while(t--) {

        cin >> k >> n;
        for(int i=0; i<n; i++) {
            cin >> so1[i];
        }
        for(int i=0; i<n; i++) {
            cin >> so2[i];
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                po1[i*n+j]=so1[i]+so2[j];
            }
        }

        for(int i=0; i<n; i++) {
            cin >> so1[i];
        }
        for(int i=0; i<n; i++) {
            cin >> so2[i];
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                po2[i*n+j]=so1[i]+so2[j];
            }
        }

        sort(po1, po1+n*n);
        sort(po2, po2+n*n);

        int ans=987654321, gap=987654321;
        for(int i=0; i<n*n; i++) {
            int f=k-po1[i];
            int idx=lower_bound(po2, po2+n*n, f)-po2;
            if(idx==n*n) idx--;
            int cand=po1[i]+po2[idx];
            int cc=abs(k-cand);
            if(cc==gap && cand<ans) {
                ans=cand;
            } else if(cc<gap) {
                ans=cand;
                gap=cc;
            }

            if(idx!=0) {
                int cand=po1[i]+po2[idx-1];
                int cc=abs(k-cand);
                if(cc==gap && cand<ans) {
                    ans=cand;
                } else if(cc<gap) {
                    ans=cand;
                    gap=cc;
                }
            }
        }

        cout << ans << '\n';
    }
}
