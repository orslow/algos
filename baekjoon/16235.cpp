// simulation (better than before?)
#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int sd[11][11];
vector<int> tree[11][11];
int yang[11][11];

void year() {

    // spring and summer
    int d;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sort(tree[i][j].begin(), tree[i][j].end());
            d=tree[i][j].size();

            for(int k=0; k<tree[i][j].size(); k++) {

                // 양분 가능
                if(yang[i][j] >= tree[i][j][k]) {
                    yang[i][j] -= tree[i][j][k];
                    tree[i][j][k]++;
                }
                else {
                    // yang[i][j] += tree[i][j][k]/2;
                    d=k;
                    break;
                }
            }

            for(int k=d; k<tree[i][j].size(); k++) {
                yang[i][j] += tree[i][j][k]/2;
            }
            tree[i][j].erase(tree[i][j].begin()+d, tree[i][j].end());
        }
    }

    // fall
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            for(int k=0; k<tree[i][j].size(); k++) {

                if(tree[i][j][k] % 5 == 0) {

                    if(i-1>=0 && j-1>=0) tree[i-1][j-1].push_back(1);
                    if(i-1>=0) tree[i-1][j].push_back(1);
                    if(i-1>=0 && j+1<n) tree[i-1][j+1].push_back(1);
                    if(j-1>=0) tree[i][j-1].push_back(1);
                    if(j+1<n) tree[i][j+1].push_back(1);
                    if(i+1<n && j-1>=0) tree[i+1][j-1].push_back(1);
                    if(i+1<n) tree[i+1][j].push_back(1);
                    if(i+1<n && j+1<n) tree[i+1][j+1].push_back(1);
                }
            }
        }
    }

    // winter
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            yang[i][j] += sd[i][j];
        }
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> sd[i][j];
        }
    }

    int x, y, z;
    for(int i=0; i<m; i++) {
        cin >> x >> y >> z;
        tree[x-1][y-1].push_back(z);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            yang[i][j]=5;
        }
    }

    while(k--) {
        year();
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans+=tree[i][j].size();
        }
    }

    cout << ans << '\n';

}

