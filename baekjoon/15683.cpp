#include <bits/stdc++.h>

using namespace std;
int ar[10][10];
int vis[10][10];
int ca[10];

int n, m, ans=64, tmp;
// int x=0, y=0;
int cnt=0, cur=0;

void a12(int x, int y) {
    for(int j=x-1; j>=0; j--) {
        if (ar[j][y] == 6)
            break;
        else if (ar[j][y] <= 0)
            ar[j][y]--;
    }
}

void b12(int x, int y) {
    for(int j=x-1; j>=0; j--) {
        if (ar[j][y] == 6)
            break;
        else if (ar[j][y] < 0)
            ar[j][y]++;
    }
}

void a3(int x, int y) {
    for(int j=y+1; j<m; j++) {
        if (ar[x][j] == 6)
            break;
        else if (ar[x][j] <= 0)
            ar[x][j]--;
    }
}

void b3(int x, int y) {
    for(int j=y+1; j<m; j++) {
        if (ar[x][j] == 6)
            break;
        else if (ar[x][j] < 0)
            ar[x][j]++;
    }
}

void a6(int x, int y) {
    for(int j=x+1; j<n; j++) {
        if (ar[j][y] == 6)
            break;
        else if (ar[j][y] <= 0)
            ar[j][y]--;
    }
}

void b6(int x, int y) {
    for(int j=x+1; j<n; j++) {
        if (ar[j][y] == 6)
            break;
        else if (ar[j][y] < 0)
            ar[j][y]++;
    }
}

void a9(int x, int y) {
    for(int j=y-1; j>=0; j--) {
        if (ar[x][j] == 6)
            break;
        else if (ar[x][j] <= 0)
            ar[x][j]--;
    }
}

void b9(int x, int y) {
    for(int j=y-1; j>=0; j--) {
        if (ar[x][j] == 6)
            break;
        else if (ar[x][j] < 0)
            ar[x][j]++;
    }
}




void bf(int k, int t) {

    if(k==cnt) {
        tmp=0;
        // 0 개수 구하기
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // cout << ar[i][j] << ' ';
                if (ar[i][j] == 0) {
                    tmp++;
                }
            }
            // cout << '\n';
        }
        if (tmp < ans)
            ans = tmp;
        // cout << ans << '\n';
        return;
    }

    while(t < n*m) {
        int x = t/m;
        int y = t%m;
        if (ar[x][y]<=5 && ar[x][y] >= 1 && vis[x][y] == 0) {
            if(ar[x][y] == 1) {
                a12(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b12(x, y);

                a3(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b3(x, y);

                a6(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b6(x, y);

                a9(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b9(x, y);
            } else if (ar[x][y] == 2) {
                a12(x, y);
                a6(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b12(x, y);
                b6(x, y);

                a3(x, y);
                a9(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b3(x, y);
                b9(x, y);
            } else if (ar[x][y] == 3) {
                a12(x, y);
                a3(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b12(x, y);
                b3(x, y);

                a3(x, y);
                a6(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b3(x, y);
                b6(x, y);

                a6(x, y);
                a9(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b6(x, y);
                b9(x, y);

                a9(x, y);
                a12(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b9(x, y);
                b12(x, y);
            } else if (ar[x][y] == 4) {
                a9(x, y);
                a12(x, y);
                a3(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b9(x, y);
                b12(x, y);
                b3(x, y);

                a12(x, y);
                a3(x, y);
                a6(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b12(x, y);
                b3(x, y);
                b6(x, y);

                a3(x, y);
                a6(x, y);
                a9(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b3(x, y);
                b6(x, y);
                b9(x, y);

                a6(x, y);
                a9(x, y);
                a12(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b6(x, y);
                b9(x, y);
                b12(x, y);
            } else if (ar[x][y] == 5) {
                a12(x, y);
                a3(x, y);
                a6(x, y);
                a9(x, y);
                vis[x][y] = 1;
                bf(k+1, t+1);
                vis[x][y] = 0;
                b12(x, y);
                b3(x, y);
                b6(x, y);
                b9(x, y);
            }
        }
        t++;
    }
    /*
    for(int x=0; x<n; x++) {
        for(int y=0; y<m; y++) {

            if (ar[x][y]<=5 && ar[x][y] >= 1 && vis[x][y] == 0) {
                if(ar[x][y] == 1) {
                    a12(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b12(x, y);

                    a3(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b3(x, y);

                    a6(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b6(x, y);

                    a9(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b9(x, y);
                } else if (ar[x][y] == 2) {
                    a12(x, y);
                    a6(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b12(x, y);
                    b6(x, y);

                    a3(x, y);
                    a9(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b3(x, y);
                    b9(x, y);
                } else if (ar[x][y] == 3) {
                    a12(x, y);
                    a3(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b12(x, y);
                    b3(x, y);

                    a3(x, y);
                    a6(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b3(x, y);
                    b6(x, y);

                    a6(x, y);
                    a9(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b6(x, y);
                    b9(x, y);

                    a9(x, y);
                    a12(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b9(x, y);
                    b12(x, y);
                } else if (ar[x][y] == 4) {
                    a9(x, y);
                    a12(x, y);
                    a3(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b9(x, y);
                    b12(x, y);
                    b3(x, y);

                    a12(x, y);
                    a3(x, y);
                    a6(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b12(x, y);
                    b3(x, y);
                    b6(x, y);

                    a3(x, y);
                    a6(x, y);
                    a9(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b3(x, y);
                    b6(x, y);
                    b9(x, y);

                    a6(x, y);
                    a9(x, y);
                    a12(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b6(x, y);
                    b9(x, y);
                    b12(x, y);
                } else if (ar[x][y] == 5) {
                    a12(x, y);
                    a3(x, y);
                    a6(x, y);
                    a9(x, y);
                    vis[x][y] = 1;
                    bf(k+1, t+1);
                    vis[x][y] = 0;
                    b12(x, y);
                    b3(x, y);
                    b6(x, y);
                    b9(x, y);
                }
                // vis[x][y] = 1;
                break;
            }

        }
    }
    */

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ar[i][j];
            if (ar[i][j] != 0 && ar[i][j] != 6) ca[cnt++] = ar[i][j];
        }
    }
    bf(0, 0);


    cout << ans << '\n';


}

