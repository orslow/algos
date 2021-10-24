// simulation
#include <bits/stdc++.h>

using namespace std;

pair<char, int> so1[201][201];

int mx[4]={1, 0, -1, 0};
int my[4]={0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r,c,n;
    cin >> r >> c >> n;

    string inp;
    for(int i=0; i<r; i++) {
        cin >> inp;
        for(int j=0; j<c; j++) {
            so1[i][j].first=inp[j];
            so1[i][j].second=0;
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            so1[i][j].second++;
        }
    }
    n--;

    while(n) {

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(so1[i][j].first=='.') {
                    so1[i][j].first='O';
                    so1[i][j].second=0;
                } else {
                    so1[i][j].second++;
                }
            }
        }
        n--;

        if(!n) break;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(so1[i][j].second==2) {
                    so1[i][j].first='.';
                    so1[i][j].second=0;
                    for(int k=0; k<4; k++) {
                        int x=i+mx[k], y=j+my[k];
                        if(x<0 || y<0 || x>=r || y>=c) continue;
                        so1[x][y].first='.';
                    }
                } else if(so1[i][j].first=='O') {
                    so1[i][j].second++;
                }
            }
        }

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(so1[i][j].first=='.') so1[i][j].second=0;
            }
        }

        n--;

        if(!n) break;
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) { 
            cout << so1[i][j].first;
        }
        cout << '\n';
    }
}
