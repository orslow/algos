// easy but wrong || / && condition
#include <bits/stdc++.h>

using namespace std;

int arr[305][305];

vector <int> so1[180];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }


    int x1=0, x2=n-1, y1=0, y2=m-1, cnt=0;
    while(x1<x2 && y1<y2) {

        for(int i=x1; i<=x2; i++) {
            so1[cnt].push_back(arr[i][y1]);
        }

        for(int i=y1+1; i<=y2; i++) {
            so1[cnt].push_back(arr[x2][i]);
        }

        for(int i=x2-1; i>=x1; i--) {
            so1[cnt].push_back(arr[i][y2]);
        }

        for(int i=y2-1; i>=y1+1; i--) {
            so1[cnt].push_back(arr[x1][i]);
        }


        // for(auto v: so1[cnt]) cout << v << ' ';
        // cout << '\n';


        int div=so1[cnt].size();
        int pu=so1[cnt].size();
        int pip=k%div;
        for(int i=x1; i<=x2; i++) {
            arr[i][y1]=so1[cnt][(pu-pip)%div];
            pu++;
        }

        for(int i=y1+1; i<=y2; i++) {
            arr[x2][i]=so1[cnt][(pu-pip)%div];
            pu++;
        }

        for(int i=x2-1; i>=x1; i--) {
            arr[i][y2]=so1[cnt][(pu-pip)%div];
            pu++;
        }

        for(int i=y2-1; i>=y1+1; i--) {
            arr[x1][i]=so1[cnt][(pu-pip)%div];
            pu++;
        }

        x1++;y1++;x2--;y2--;
        cnt++;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

