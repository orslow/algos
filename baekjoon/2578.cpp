#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool so1[5][5];

map<int, pair<int, int>> bing;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> n;
            bing[n]={i, j};
        }
    }

    pair<int, int> tmp;
    for(int p=0; p<25; p++) {
        cin >> n;
        tmp=bing[n];
        so1[tmp.first][tmp.second]=1;

        bool bi;
        int cnt=0;
        for(int i=0; i<5; i++) {
            bi=true;
            for(int j=0; j<5; j++) {
                if(so1[i][j]==0) {
                    bi=false;
                    break;
                }
            }
            if(bi) cnt+=1;
        }

        for(int i=0; i<5; i++) {
            bi=true;
            for(int j=0; j<5; j++) {
                if(so1[j][i]==0) {
                    bi=false;
                    break;
                }
            }
            if(bi) cnt+=1;
        }

        bi=true;
        for(int i=0; i<5; i++) {
            if(so1[i][i]==0) {
                bi=false;
                break;
            }
        }
        if(bi) cnt+=1;

        bi=true;
        for(int i=0; i<5; i++) {
            if(so1[i][4-i]==0) {
                bi=false;
                break;
            }
        }
        if(bi) cnt+=1;

        if(cnt>=3) {
            cout << p+1 << '\n';
            return 0;
        }


    }
}

