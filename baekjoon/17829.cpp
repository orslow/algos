// simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int so1[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> so1[i][j];
        }
    }

    while(n!=0) {

        int i1=1;
        int j1=1;
        int x1=1;
        int y1=1;
        while(i1<n) {
            vector <int> tmp;
            for(int i=i1; i<=i1+1; i++) {
                for(int j=j1; j<=j1+1; j++) {
                    tmp.push_back(so1[i][j]);
                }
            }
            sort(tmp.begin(), tmp.end());
            so1[x1][y1]=tmp[2];

            j1+=2;
            y1++;
            if(j1>n) {
                i1+=2;
                j1=1;
                x1++;
                y1=1;
            }

        }

        n/=2;

        /*
        cout << '\n';
        for(int i=1; i<=tn; i++) {
            for(int j=1; j<=tn; j++) {
                cout << so1[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << "\n\n";
        */

    }

    cout << so1[1][1] << '\n';
}

