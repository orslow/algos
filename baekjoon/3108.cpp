#include <bits/stdc++.h>

using namespace std;

using ll=long long;

pair<tuple<int, int, int, int>, int> rec[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int x1, x2, y1, y2;
    bool uf=0;
    for(int i=1; i<=n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1==0 || x2==0) {
            if(y1<=0 && y2>=0) uf=1;
        }
        if(y1==0 || y2==0) {
            if(0>=x1 && 0<=x2) uf=1;
        }

        rec[i]={make_tuple(x1, y1, x2, y2), 0};
    }

    queue<pair<int, tuple<int, int, int, int>>> qu;
    int idx, cx1, cx2, cy1, cy2;
    bool cont;
    for(int i=1; i<=n; i++) {
        if(rec[i].second!=0) continue;

        qu.push({i, rec[i].first});
        rec[i].second=i;
        while(!qu.empty()) {
            tie(x1, y1, x2, y2)=qu.front().second; idx=qu.front().first;qu.pop();

            for(int j=1; j<=n; j++) {
                if(rec[j].second!=0) continue;
                tie(cx1, cy1, cx2, cy2)=rec[j].first;

                cont=1;
                if((x1<cx1 && x2<cx1) || (x1>cx2 && x2>cx2)) {
                    cont=0;
                } else if(x1>cx1 && x2<cx2) {
                    if((y1<cy1 && y2<cy1) || (y1>cy2 && y2>cy2) || (y1>cy1 && y2<cy2)) {
                        cont=0;
                    }
                } 

                if((y1<cy1 && y2<cy1) || (y1>cy2 && y2>cy2)) {
                    cont=0;
                } else if(y1>cy1 && y2<cy2) {
                    if((x1<cx1 && x2<cx1) || (x1>cx2 && x2>cx2) || (x1>cx1 && x2<cx2)) {
                        cont=0;
                    }
                } 

                if(x1 < cx1 && x2 > cx2 && y1 < cy1 && y2 > cy2) cont=0;

                if(cont) {
                    rec[j].second=idx;
                    qu.push({idx, rec[j].first});
                    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
                    // cout << cx1 << ' ' << cy1 << ' ' << cx2 << ' ' << cy2 << '\n';
                    // cout << "\n\n";
                }

            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++) {
        if(rec[i].second==i) ans++;
    }
    // cout << uf << '\n';
    cout << ans-uf << '\n';
}

