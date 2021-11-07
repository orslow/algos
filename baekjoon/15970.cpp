// sort
#include <bits/stdc++.h>

using namespace std;

vector <int> so1[5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> x >> y;
        so1[y].push_back(x);
    }

    for(int i=1; i<=5000; i++) {
        sort(so1[i].begin(), so1[i].end());
    }

    long long l=0;
    for(int i=1; i<=5000; i++) {
        if(so1[i].size()>1) {
            l+=so1[i][1]-so1[i][0];

            for(int j=1; j<so1[i].size()-1; j++) {
                if(so1[i][j]-so1[i][j-1]<so1[i][j+1]-so1[i][j]) {
                    l+=so1[i][j]-so1[i][j-1];
                } else {
                    l+=so1[i][j+1]-so1[i][j];
                }
            }
            l+=so1[i][so1[i].size()-1]-so1[i][so1[i].size()-2];
        }
    }

    cout << l;
}
