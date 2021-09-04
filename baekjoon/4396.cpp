// simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;


int n;

char g[13][13];
char ans[13][13];

bool chk(int x, int y) {
    if(g[x][y]=='*') {
        ans[x][y]='*';
        return true;
    }
    int k=0;
    if(x-1>=0 && g[x-1][y]=='*') k++;
    if(x+1<n && g[x+1][y]=='*') k++;
    if(y-1>=0 && g[x][y-1]=='*') k++;
    if(y+1<n && g[x][y+1]=='*') k++;
    if(x-1>=0 && y-1>=0 && g[x-1][y-1]=='*') k++;
    if(x-1>=0 && y+1<n && g[x-1][y+1]=='*') k++;
    if(x+1<n && y+1<n && g[x+1][y+1]=='*') k++;
    if(x+1<n && y-1>=0 && g[x+1][y-1]=='*') k++;
    ans[x][y]=char(k+48);

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string l;
    for(int i=0; i<n; i++) {
        cin >> l;
        for(int j=0; j<n; j++) {
            g[i][j]=l[j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans[i][j]='.';
        }
    }

    bool bombed=false;
    for(int i=0; i<n; i++) {
        cin >> l;
        for(int j=0; j<n; j++) {
            if(l[j]=='x') {
                if(chk(i, j)) {
                    bombed=true;
                }
            }
        }
    }

    if(bombed) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(g[i][j]=='*') ans[i][j]='*';
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

