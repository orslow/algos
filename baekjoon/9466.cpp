// DFS without recursive
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int soo[100005];
bool vis[100005];
bool vis2[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;

        for(int i=1; i<=n; i++) {
            cin >> soo[i];
        }

        for(int i=1; i<=n; i++) {
            vis[i]=0;
        }

        int ans=n, lo;
        for(int i=1; i<=n; i++) {
            vector <int> his;
            if(vis[i]==0) {
                int cur=i;
                while(vis[cur]==0) {
                    his.push_back(cur);
                    vis[cur]=1;
                    cur=soo[cur];
                }
                /*
                cout << "i: " << i << ' ';
                for(int i=0; i<his.size(); i++) {
                    cout << his[i] << ' ';
                }
                cout << '\n';
                */
                int d=cur;

                bool dh=0;
                lo=0;
                for(int i=0; i<his.size(); i++) {
                    if(his[i]==cur) dh=1;
                    if(dh) lo++;
                    vis2[his[i]]=1;
                }

                ans-=lo;

                // cout << i << ' ' << lo << '\n';
            }
        }
        cout << ans << '\n';
    }
}

