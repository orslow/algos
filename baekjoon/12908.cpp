// backtracking apply(wonderous)
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

vector <tuple<int, int, int, int>> tp;

ll xs, ys, xe, ye, shortest;

bool vis[3];

void bt(ll curx, ll cury, ll cost) {

    if(cost+abs(curx-xe)+abs(cury-ye) < shortest) shortest = cost+abs(curx-xe)+abs(cury-ye);

    ll x1, x2, y1, y2;
    for(int i=0; i<3; i++) {
        if(vis[i]==0) {
            tie(x1, y1, x2, y2) = tp[i];
            vis[i]=1;
            bt(x2, y2, cost+abs(x1-curx)+abs(y1-cury)+10);
            bt(x1, y1, cost+abs(x2-curx)+abs(y2-cury)+10);
            vis[i]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> xs >> ys >> xe >> ye;

    int x1, x2, y1, y2;
    for(int i=0; i<3; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        tp.push_back(make_tuple(x1, y1, x2, y2));
    }

    shortest=abs(xs-xe)+abs(ys-ye);

    bt(xs, ys, 0);

    cout << shortest << '\n';
    
}
