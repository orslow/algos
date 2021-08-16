// 같은 수 여러번 써도 된다.
#include <bits/stdc++.h>

using namespace std;

int so1[1001];
vector <int> ts;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    sort(so1, so1+n);

    for(int i=0; i<n-1; i++) {
        for(int j=i; j<n-1; j++) {
            ts.push_back(so1[i]+so1[j]);
        }
    }

    sort(ts.begin(), ts.end());

    /*
    for(auto v: ts) cout << v << ' ';
    cout << '\n';
    */

    for(int i=n-1; i>=0; i--) {
        for(int j=i-1; j>=0; j--) {
            if(binary_search(ts.begin(), ts.end(), so1[i]-so1[j])) {
                cout << so1[i] << '\n';
                return 0;
            }
        }
    }

}

