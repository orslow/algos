// 치킨배달(구현)
#include <bits/stdc++.h>

using namespace std;

pair<int, int> home[101];
pair<int, int> chick[14];
int chk[14];

int n, m;

int main() {

    cin >> n >> m;


    int type, hdx=0, cdx=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> type;

            if (type == 1) {
                home[hdx++] = {i, j};
            } else if (type == 2) {
                chk[cdx]=1;
                chick[cdx++] = {i, j};
            }
        }
    }

    for(int i=0; i<cdx-m; i++) {
        chk[i]=0;
    }

    int tot, min=987654321, cur, dis;
    do {
        tot=0;

        for(int i=0; i<hdx; i++) { // each house

            cur=987654321;

            for(int j=0; j<cdx; j++) {
                if (chk[j] == 1) { // each chicken

                    dis = abs(home[i].first - chick[j].first) + abs(home[i].second - chick[j].second);
                    if (dis < cur) cur = dis;
                }
            }
            
            tot += cur;
        }

        if (tot < min) min = tot;

    } while (next_permutation(chk, chk+cdx));


    cout << min << '\n';

}

