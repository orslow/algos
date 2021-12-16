// brute force
#include <bits/stdc++.h>

using namespace std;

char so1[11][11];
char so2[11][11];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r,c;
    cin >> r >> c;

    string s;
    for(int i=0; i<r; i++) {
        cin >> s;
        for(int j=0; j<c; j++) {
            so1[i][j]=s[j];
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(so1[i][j]=='X') {
                int cnt=0;
                for(int k=0; k<4; k++) {
                    int x=i+mx[k], y=j+my[k];
                    if(x<0 || y<0 || x>=r || y>=c) {
                        cnt++;
                        continue;
                    }
                    if(so1[x][y]=='.') cnt++;
                }
                if(cnt>=3) {
                    so2[i][j]='.';
                } else {
                    so2[i][j]='X';
                }
            } else {
                so2[i][j]='.';
            }
        }
    }

    int x1=0, x2=r-1, y1=0, y2=c-1;
    for(int i=0; i<r; i++) {
        bool a=1;
        for(int j=0; j<c; j++) {
            if(so2[i][j]=='X') {
                a=0;
                break;
            }
        }
        if(a==0) {
            x1=i;
            break;
        }
    }
    for(int i=r-1; i>=0; i--) {
        bool a=1;
        for(int j=0; j<c; j++) {
            if(so2[i][j]=='X') {
                a=0;
                break;
            }
        }
        if(a==0) {
            x2=i;
            break;
        }
    }

    for(int i=0; i<c; i++) {
        bool a=1;
        for(int j=0; j<r; j++) {
            if(so2[j][i]=='X') {
                a=0;
                break;
            }
        }
        if(a==0) {
            y1=i;
            break;
        }
    }

    for(int i=c-1; i>=0; i--) {
        bool a=1;
        for(int j=0; j<c; j++) {
            if(so2[j][i]=='X') {
                a=0;
                break;
            }
        }
        if(a==0) {
            y2=i;
            break;
        }
    }

    for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
            cout << so2[i][j];
        }
        cout << '\n';
    }

}
