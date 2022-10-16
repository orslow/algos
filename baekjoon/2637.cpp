// graph? exercise
#include <bits/stdc++.h>

using namespace std;

vector <tuple<int, int>> so1[103];
int so2[103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int x,y,k;
    for(int i=0; i<m; i++) {
        cin >> x >> y >> k;
        so1[x].push_back(make_tuple(y, k));
    }

    so2[n]=1;
    int a,b;
    bool go=1;
    while(go) {
        go=0;
        for(int i=1; i<=n; i++) {
            if(so2[i] && !so1[i].empty()) {
                go=1;
                int g=so2[i];
                for(auto s: so1[i]) {
                    tie(a, b)=s;
                    so2[a]+=g*b;
                }
                so2[i]=0;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(so2[i]) {
            cout << i << ' ' << so2[i] << '\n';
        }
    }
}

