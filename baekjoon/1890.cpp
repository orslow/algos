// not bfs but dp
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[103][103];
ll vis[103][103];

int mx[2]={1, 0};
int my[2]={0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> so1[i][j];
        }
    }

    vis[0][0]=1;

    int cx,cy;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]==0 || (i == n-1 && j == n-1)) continue;

            for(int k=0; k<2; k++) {
                cx=i+mx[k]*so1[i][j];cy=j+my[k]*so1[i][j];
                if(cx<0 || cy<0 || cx>=n || cy>=n) continue;
                vis[cx][cy]+=vis[i][j];
            }
        }
    }

    cout << vis[n-1][n-1];

}
