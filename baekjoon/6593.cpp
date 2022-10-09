// basic BFS
#include <bits/stdc++.h>

using namespace std;

char so1[33][33][33];
bool vis[33][33][33];

int main() {

    int l,r,c,x,y,z,u,a,b;

    while(true) {
        cin >> l >> r >> c;

        if(l==0 && r==0 && c==0) break;

        string inp;
        for(int i=0; i<l; i++) {
            for(int j=0; j<r; j++) {
                cin >> inp;
                for(int k=0; k<c; k++) {
                    so1[i][j][k]=inp[k];
                    if(so1[i][j][k] == 'S') {
                        x=i;
                        y=j;
                        z=k;
                    }
                    else if(so1[i][j][k] == 'E') {
                        u=i;
                        a=j;
                        b=k;
                    }
                }
            }
        }


        for(int i=0; i<l; i++) {
            for(int j=0; j<r; j++) {
                for(int k=0; k<c; k++) {
                    vis[i][j][k]=0;
                }
            }
        }


        queue <tuple<int,int,int,int>> qu;
        qu.push(make_tuple(x,y,z,0));
        vis[x][y][z]=1;

        int sx,sy,sz,ss;
        bool ans=0;
        while(qu.size()) {
            tie(sx, sy, sz, ss) = qu.front();
            qu.pop();

            if(sx==u && sy==a && sz==b) {
                cout << "Escaped in " << ss << " minute(s)." << '\n';
                ans=1;
                break;
            }

            if(sx-1>=0 && so1[sx-1][sy][sz]!='#' && vis[sx-1][sy][sz]==0) {
                qu.push(make_tuple(sx-1, sy, sz, ss+1));
                vis[sx-1][sy][sz]=1;
            }

            if(sx+1<l && so1[sx+1][sy][sz]!='#' && vis[sx+1][sy][sz]==0) {
                qu.push(make_tuple(sx+1, sy, sz, ss+1));
                vis[sx+1][sy][sz]=1;
            }

            if(sy-1>=0 && so1[sx][sy-1][sz]!='#' && vis[sx][sy-1][sz]==0) {
                qu.push(make_tuple(sx, sy-1, sz, ss+1));
                vis[sx][sy-1][sz]=1;
            }

            if(sy+1<r && so1[sx][sy+1][sz]!='#' && vis[sx][sy+1][sz]==0) {
                qu.push(make_tuple(sx, sy+1, sz, ss+1));
                vis[sx][sy+1][sz]=1;
            }


            if(sz-1>=0 && so1[sx][sy][sz-1]!='#' && vis[sx][sy][sz-1]==0) {
                qu.push(make_tuple(sx, sy, sz-1, ss+1));
                vis[sx][sy][sz-1]=1;
            }

            if(sz+1<c && so1[sx][sy][sz+1]!='#' && vis[sx][sy][sz+1]==0) {
                qu.push(make_tuple(sx, sy, sz+1, ss+1));
                vis[sx][sy][sz+1]=1;
            }
        }

        if(ans==0) {
            cout << "Trapped!" << '\n';
        }
    }
}

