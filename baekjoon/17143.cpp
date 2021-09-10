// hard simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

tuple<int, int, int> shk[103][103];
priority_queue <tuple<int, int, int>> shk_q[103][103];

bool vis[103][103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, m; 
    cin >> r >> c >> m;

    int x, y, s, d, z;
    for(int i=0; i<m; i++) {
        cin >> x >> y >> s >> d >> z;
        shk[x][y]=make_tuple(z, d, s);
    }

    int ans=0;
    for(int i=1; i<=c; i++) {

        /*
        for(int j=1; j<=r; j++) {
            for(int k=1; k<=c; k++) {
                tie(z, d, s) = shk[j][k];
                cout << z << ' ';
            }
            cout << '\n';
        }
        */


        // catch shark
        for(int j=1; j<=r; j++) {
            tie(z, d, s)=shk[j][i];
            if(z>0) {
                shk[j][i]=make_tuple(0, 0, 0);
                ans+=z;
                break;
            }
        }

        for(int j=1; j<=r; j++) {
            for(int k=1; k<=c; k++) {
                shk_q[j][k] = priority_queue<tuple<int, int, int>>();
            }
        }

        // cout << ans << '\n';


        // movement
        for(int j=1; j<=r; j++) {
            for(int k=1; k<=c; k++) {
                tie(z, d, s)=shk[j][k];

                // shark exists
                int bk, s1, s2;
                if(z>0) {
                    if(d==1) {
                        if(j-s<1) {
                            bk=r-j;
                            s1=(bk+s)/(r-1);
                            s2=(bk+s)%(r-1);

                            if(s1%2==0) { // 방향 유지
                                shk_q[r-s2][k].push({z, d, s});
                            } else {
                                shk_q[s2+1][k].push({z, 2, s});
                            }
                        } else {
                            shk_q[j-s][k].push({z, d, s});
                        }
                    } else if(d==2) {
                        if(j+s>r) {
                            bk=j-1;
                            s1=(bk+s)/(r-1);
                            s2=(bk+s)%(r-1);

                            if(s1%2==0) { // 방향 유지
                                shk_q[s2+1][k].push({z, d, s});
                            } else {
                                shk_q[r-s2][k].push({z, 1, s});
                            }
                        } else {
                            shk_q[j+s][k].push({z, d, s});
                        }
                    } else if(d==3) {
                        if(k+s>c) {
                            bk=k-1;
                            s1=(bk+s)/(c-1);
                            s2=(bk+s)%(c-1);

                            if(s1%2==0) { // 방향 유지
                                shk_q[j][s2+1].push({z, d, s});
                            } else {
                                shk_q[j][c-s2].push({z, 4, s});
                            }
                        } else {
                            shk_q[j][k+s].push({z, d, s});
                        }
                    } else {
                        if(k-s<1) {
                            bk=c-k;
                            s1=(bk+s)/(c-1);
                            s2=(bk+s)%(c-1);

                            if(s1%2==0) { // 방향 유지
                                shk_q[j][c-s2].push({z, d, s});
                            } else {
                                shk_q[j][s2+1].push({z, 3, s});
                            }
                        } else {
                            shk_q[j][k-s].push({z, d, s});
                        }
                    }
                }
            }
        }

        /*
        for(int j=1; j<=r; j++) {
            for(int k=1; j<=c; k++) {
                shk[i][j]=make_tuple(0, 0, 0);
            }
        }
        */
        for(int j=1; j<=r; j++) {
            for(int k=1; k<=c; k++) {
                if(!shk_q[j][k].empty()) {
                    tie(z, d, s)=shk_q[j][k].top();
                    shk[j][k]=make_tuple(z, d, s);
                } else {
                    shk[j][k]=make_tuple(0, 0, 0);
                }
            }
        }

    }

    cout << ans;

}

