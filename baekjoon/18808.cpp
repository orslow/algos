#include <bits/stdc++.h>

using namespace std;

int mac[101][101];

int stk[11][11];

int n, m, k, r, c, a, b;

void stick() {
    a=0;b=0;
    int i1=0, j1=0;
    bool done=0;

    bool avail;
    // 0
    while(true) {
        i1=0; j1=0;

        avail = 1;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if (i+a>=n || j+b>=m) {
                    avail = 0;
                    break;
                }
                if (stk[i][j] == 1 && i+a<n && j+b<m && mac[i+a][j+b] == 1) { 
                    avail = 0;
                    break;
                }

            }
        }
        if (avail) {
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if(stk[i][j] == 1) mac[i+a][j+b] = 1 ;
                }
            }
            done = 1;
            break;
        } else {
            b++;
            if(b == m) {
                a++;
                b=0;
            }
            if(a==n)
                break;
        }

    }

    if(done) return;

    a=0; b=0;

    // 90
    while(true) {
        i1=0, j1=0;
        avail = 1;
        for(int j=0; j<c; j++) {
            for(int i=r-1; i>=0; i--) {
                if (i1+a>=n || j1+b>=m) {
                    avail = 0;
                    break;
                }
                if (stk[i][j] == 1 && i1+a<n && j1+b<m && mac[i1+a][j1+b] == 1) { 
                    avail = 0;
                    break;
                }

                j1++;
            }
            i1++;
            j1=0;

        }
        if (avail) {
            i1=0; j1=0;
            for(int j=0; j<c; j++) {
                for(int i=r-1; i>=0; i--) {
                    if(stk[i][j] == 1) mac[i1+a][j1+b] = 1 ;
                    j1++;
                }
                i1++;
                j1=0;
            }
            done=1;
            break;
        } else {
            b++;
            if(b == m) {
                a++;
                b=0;
            }
            if(a==n)
                break;
        }

    }

    if(done) return;

    a=0;b=0;
    // 180
    while(true) {
        i1=0; j1=0;
        avail = 1;
        for(int i=r-1; i>=0; i--) {
            for(int j=c-1; j>=0; j--) {
                if (i1+a>=n || j1+b>=m) {
                    avail = 0;
                    break;
                }
                if (stk[i][j] == 1 && i1+a<n && j1+b<m && mac[i1+a][j1+b] == 1) {
                    avail = 0;
                    break;
                }
                j1++;
            }
            i1++;
            j1=0;
        }

        if (avail) {
            i1=0;j1=0;
            for(int i=r-1; i>=0; i--) {
                for(int j=c-1; j>=0; j--) {
                    if(stk[i][j] == 1) mac[i1+a][j1+b] = 1;
                    j1++;
                }
                i1++;
                j1=0;
            }
            done = 1;
            break;
        } else {
            b++;
            if(b == m) {
                a++;
                b=0;
            }
            if(a==n)
                break;
        }
    }

    if(done) return;

    a=0;b=0;
    // 270 
    while(true) {
        i1=0;j1=0;
        avail = 1;
        for(int j=c-1; j>=0; j--) {
            for(int i=0; i<r; i++) {
                if (i1+a>=n || j1+b>=m) {
                    avail = 0;
                    break;
                }
                if (stk[i][j] == 1 && i1+a<n && j1+b<m && mac[i1+a][j1+b] == 1) {
                    avail = 0;
                    break;
                }
                j1++;
            }
            i1++;
            j1=0;
        }

        if (avail) {
            i1=0; j1=0;
            for(int j=c-1; j>=0; j--) {
                for(int i=0; i<r; i++) {
                    if(stk[i][j] == 1) mac[i1+a][j1+b] = 1;
                    j1++;
                }
                i1++;
                j1=0;
            }
            break;
        } else {
            b++;
            if(b == m) {
                a++;
                b=0;
            }
            if(a==n)
                break;
        }
    }


}

int main() {

    cin >> n >> m >> k;

    for(int i=0; i<k; i++) {
        cin >> r >> c;

        for(int j=0; j<r; j++) {
            for(int l=0; l<c; l++) {
                cin >> stk[j][l];
            }
        }

        stick();
        for(int j=0; j<r; j++) {
            for(int l=0; l<c; l++) {
                stk[j][l] = 0;
            }
        }


        /*
        cout << "\n\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << mac[i][j] << ' ';
            }
            cout << "\n";
        }
        */


    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (mac[i][j] == 1) ans++;
        }
    }
    cout << ans << '\n';

}

