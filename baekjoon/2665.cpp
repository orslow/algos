// bfs
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int ro[53][53];
int vis[53][53];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    string s;
    for(int i=0; i<n; i++) {
        getline(cin, s);

        for(int j=0; j<n; j++) {
            ro[i][j]=s[j]-'0';
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            vis[i][j]=25000;
        }
    }

    queue <tuple<int,int,int>> qu;
    qu.push(make_tuple(0, 0, 0));

    int x,y,t,cx,cy // ,ans=2505;
    while(!qu.empty()) {
        tie(x, y, t)=qu.front();qu.pop();

        /*
        if(x==n-1 && y==n-1) {
            if(t<ans) ans=t;
            continue;
        }
        */

        for(int i=0; i<4; i++) {
            cx=x+mx[i];cy=y+my[i];

            if(cx<0 || cy<0 || cx>=n || cy>=n) continue;

            if(ro[cx][cy]==1) {
                if(t<vis[cx][cy]) {
                    vis[cx][cy]=t;
                    qu.push(make_tuple(cx, cy, t));
                }
            } else {
                if(t+1<vis[cx][cy]) {
                    vis[cx][cy]=t+1;
                    qu.push(make_tuple(cx, cy, t+1));
                }
            }
        }
    }
    cout << vis[n-1][n-1];
}
