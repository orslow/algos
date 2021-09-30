// simulation more practice need
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

tuple<int,int,int> cand[23];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a;
    cin >> n >> m;

    int cnt=0;
    while(m--) {
        cin >> a;

        bool sup=0;
        int id, idx, bal, old;
        for(int i=0; i<cnt; i++) {
            tie(id, bal, old)=cand[i];
            if(id==a) {
                sup=1;
                cand[i]=make_tuple(id, bal+1, old);
                break;
            }
        }
        if(!sup) {
            if(cnt!=n) {
                cand[cnt]=make_tuple(a, 1, 0);
                cnt++;
            }
            else {
                int min=3000, mina=1005;
                for(int i=0; i<n; i++) {
                    tie(id, bal, old)=cand[i];
                    if(bal<min) {
                        idx=i;
                        min=bal;
                        mina=old;
                    } else if(bal==min && old>mina) {
                        idx=i;
                        min=bal;
                        mina=old;
                    }
                }
                cand[idx]=make_tuple(a, 1, 0);
            }
        }
        int s1,s2,s3;
        for(int i=0; i<cnt; i++) {
            tie(s1,s2,s3)=cand[i];
            cand[i]=make_tuple(s1,s2,s3+1);
        }

        /*
        for(int i=0; i<cnt; i++) {
            tie(s1,s2,s3)=cand[i];
            cout << s1 << ' ';
        }
        cout << "\n";

        for(int i=0; i<cnt; i++) {
            tie(s1,s2,s3)=cand[i];
            cout << s3 << ' ';
        }
        cout << "\n\n";
        */
    }

    sort(cand, cand+cnt);

    int s1,s2,s3;
    for(int i=0; i<cnt; i++) {
        tie(s1,s2,s3)=cand[i];
        cout << s1 << ' ';
    }
}
