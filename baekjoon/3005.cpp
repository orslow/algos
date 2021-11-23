// simulation/string
#include <bits/stdc++.h>

using namespace std;

int r,c;
char so1[21][21];
bool vis[21][21][2];

vector <string> w;

void down(int x, int y) {
    string s="";
    for(int i=x; i<r; i++) {
        if(so1[i][y]=='#') break;
        s+=so1[i][y];
        vis[i][y][0]=1;
    }
    if(s.length()>=2) w.push_back(s);
}

void right(int x, int y) {
    string s="";
    for(int i=y; i<c; i++) {
        if(so1[x][i]=='#') break;
        s+=so1[x][i];
        vis[x][i][1]=1;
    }
    if(s.length()>=2) w.push_back(s);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

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
            if(so1[i][j]!='#') {
                if(vis[i][j][0]==0)
                    down(i, j);
                if(vis[i][j][1]==0)
                    right(i, j);
            }
        }
    }

    sort(w.begin(), w.end());

    cout << w[0];
}
