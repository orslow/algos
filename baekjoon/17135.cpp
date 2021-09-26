// realization practice
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[18][18];
int so2[18][18];
int arc[18];

int mx[3]={0, -1, 0};
int my[3]={-1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,d;
    cin >> n >> m >> d;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> so1[i][j];
        }
    }

    for(int i=0; i<3; i++) {
        arc[i]=1;
    }

    int cnt,ans=0;
	do {
        cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                so2[i][j]=so1[i][j];
            }
        }

        vector <pair<int, int>> as;
		for (int i=0; i<m; i++) {
			if (arc[i]==1) as.push_back({n,i});
		}

        // 적들을 한칸씩 아래로 이동
        for(int i=0; i<n; i++) {

            /*
            cout << i << '\n';
            for(int u=0; u<n; u++) {
                for(int v=0; v<m; v++) {
                    cout << so2[u][v];
                }
                cout << '\n';
            }
            cout << "\n\n";
            */

            set <pair<int,int>> tt;

            // 세 궁수 공격
            for(int j=0; j<3; j++) {
                int x=as[j].first, y=as[j].second, s;

                queue <tuple<int, int, int>> qu;
                qu.push({x-1, y, 1});

                while(!qu.empty()) {
                    tie(x, y, s)=qu.front();qu.pop();
                    if(so2[x][y]==1) {
                        tt.insert({x,y});
                        break;
                    }

                    if(s==d) continue;

                    for(int k=0; k<3; k++) {
                        int cx=x+mx[k], cy=y+my[k];

                        if(cx<0 || cy<0 || cy>=m) continue;
                        qu.push({cx, cy, s+1});
                    }
                }
            }
            cnt+=tt.size();
            /*
            cout << cnt << '\n';
            for(auto e: tt) {
                cout << e.first << ' ' << e.second << '\n';
            }
            cout << "\n\n";
            */

            for(auto e: tt) {
                so2[e.first][e.second]=0;
            }

            // 아래로 이동
            for(int u=n-1; u>0; u--) {
                for(int v=0; v<m; v++) {
                    so2[u][v]=so2[u-1][v];
                }
            }
            for(int u=0; u<m; u++) {
                so2[i][u]=0;
            }
        }
        if(cnt>ans) ans=cnt;
        // cout << ans << '\n';

	} while(prev_permutation(arc, arc+m));

    cout << ans;
}

