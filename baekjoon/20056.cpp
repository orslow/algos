// simulation still hard
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

vector <tuple<int, int, int>> so1[51][51];
vector <tuple<int, int, int>> so2[51][51];

int mx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int my[8]={0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, x, y, mm, s, d;
    cin >> n >> m >> k;

    for(int i=0; i<m; i++) {
        cin >> x >> y >> mm >> s >> d;
        so1[x-1][y-1].push_back(make_tuple(mm, d, s));
    }

    while(k--) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                so2[i][j].clear();
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                for(auto t: so1[i][j]) {
                    tie(m, d, s) = t;

                    x=i+mx[d]*s;
                    y=j+my[d]*s;

                    while(x<0) x+=n;
                    while(y<0) y+=n;

                    // if(x<1 || y<1 || x>n || y>n) continue;

                    so2[x%n][y%n].push_back(make_tuple(m, d, s));
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                so1[i][j].clear();
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(so2[i][j].size()<2)  {
                    for(auto t: so2[i][j]) {
                        tie(m, d, s) = t;
                        so1[i][j].push_back(make_tuple(m, d, s));
                    }
                    continue;
                }

                bool even=0, odd=0;
                int msum=0, ssum=0, mdiv, sdiv;
                for(auto t: so2[i][j]) {
                    tie(m, d, s) = t;
                    if(d%2==0) even=true;
                    else odd=true;

                    msum+=m;
                    ssum+=s;
                }
                if(msum<5) continue;
                mdiv=msum/5;
                sdiv=ssum/so2[i][j].size();

                if(even && odd) {
                    so1[i][j].push_back(make_tuple(mdiv, 1, sdiv));
                    so1[i][j].push_back(make_tuple(mdiv, 3, sdiv));
                    so1[i][j].push_back(make_tuple(mdiv, 5, sdiv));
                    so1[i][j].push_back(make_tuple(mdiv, 7, sdiv));
                } else {
                    so1[i][j].push_back(make_tuple(mdiv, 0, sdiv));
                    so1[i][j].push_back(make_tuple(mdiv, 2, sdiv));
                    so1[i][j].push_back(make_tuple(mdiv, 4, sdiv));
                    so1[i][j].push_back(make_tuple(mdiv, 6, sdiv));
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(auto t: so1[i][j]) {
                tie(m, d, s) = t;
                ans+=m;
            }
        }
    }

    cout << ans;
}
