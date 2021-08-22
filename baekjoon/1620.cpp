// basic hash
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

string pk1[100001];
map <string, int> pk2;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cin.ignore();

    string s;
    for(int i=1; i<=n; i++) {
        getline(cin, s);
        pk1[i]=s;

        pk2[s] = i;
        // cout << s << ' ' << pk2[s] << '\n';
    }

    for(int i=0; i<m; i++) {
        getline(cin, s);

        int fc = s[0]-0;
        if(fc >=49 && fc <= 57) {
            cout << pk1[stoi(s)] << '\n';
        }
        else {
            cout << pk2[s] << '\n';
        }
    }
}
