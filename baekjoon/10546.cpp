// data structure(map)
#include <bits/stdc++.h>

using namespace std;

map <string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        m[s]+=1;
    }

    for(int i=0; i<n-1; i++) {
        cin >> s;
        m[s]-=1;
    }

    for(auto p: m) {
        if(p.second!=0) {
            cout << p.first;
            return 0;
        }
    }

}
