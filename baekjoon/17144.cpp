// simulation exercise
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int r,c,t;

int ac[2];

int so1[53][53];
int so2[53][53];

void dust() {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            so2[i][j]=0;
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {

            if(so1[i][j]>0) {

                int cnt=0;
                for(int k=0; k<4; k++) {
                    int cx=i+mx[k], cy=j+my[k];

                    if(cx<0 || cy<0 || cx>=r || cy>=c || so1[cx][cy]==-1) continue;
                    cnt++;
                    so2[cx][cy]+=so1[i][j]/5;
                }
                so2[i][j]+=so1[i][j]-so1[i][j]/5*cnt;
            } else if(so1[i][j]==-1) {
                so2[i][j]=-1;
            }
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            so1[i][j]=so2[i][j];
        }
    }

    /*
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << so1[i][j] << ' ';
        }
        cout << '\n';
    }
    */
}

void cir() {
    int x=ac[0];
    for(int i=x-1; i>0; i--) {
        so1[i][0]=so1[i-1][0];
    }
    for(int i=0; i<c-1; i++) {
        so1[0][i]=so1[0][i+1];
    }
    for(int i=0; i<x; i++) {
        so1[i][c-1]=so1[i+1][c-1];
    }
    for(int i=c-1; i>1; i--) {
        so1[x][i]=so1[x][i-1];
    }
    so1[x][0]=-1;
    so1[x][1]=0;

    x=ac[1];
    for(int i=x+1; i<r-1; i++) {
        so1[i][0]=so1[i+1][0];
    }
    for(int i=0; i<c-1; i++) {
        so1[r-1][i]=so1[r-1][i+1];
    }
    for(int i=r-1; i>x; i--) {
        so1[i][c-1]=so1[i-1][c-1];
    }
    for(int i=c-1; i>0; i--) {
        so1[x][i]=so1[x][i-1];
    }
    so1[x][0]=-1;
    so1[x][1]=0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;

    int cnt=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> so1[i][j];
            if(so1[i][j]==-1) {
                ac[cnt++]=i;
            }
        }
    }

    while(t--) {
        dust();
        cir();
    }

    int ans=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            ans+=so1[i][j];
        }
    }

    cout << ans+2;
}

