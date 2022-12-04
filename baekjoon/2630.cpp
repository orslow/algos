// basic recursive function
#include <bits/stdc++.h>

using namespace std;

int so1[130][130];

int blue=0;
int white=0;

void go(int x, int y, int n) {

    bool b=false, w=false;
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(so1[i][j]==1) {
                b=true;
            } else {
                w=true;
            }
        }
    }

    if(b && w) {
        n/=2;
        go(x, y, n);
        go(x+n, y, n);
        go(x, y+n, n);
        go(x+n, y+n, n);
    } else if (b){
        blue++;
    } else {
        white++;
    }
}


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

    go(0, 0, n);

    cout << white << '\n' << blue;
}
