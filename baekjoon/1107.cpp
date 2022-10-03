// basic brute force
#include <bits/stdc++.h>

using namespace std;

set <int> so1;

string n;
int ans;

void go(string c) {
    for(int i=0; i<10; i++) {
        if(so1.find(i) == so1.end()) {
            string d = c + to_string(i);
            int r = abs(stoi(d) - stoi(n)) + d.length();
            if(r<ans) ans=r;
            if(d.length() == n.length() + 1) {
                break;
            } else {
                go(d);
            }
        }
    }
}

int main() {

    int m,a;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> a;
        so1.insert(a);
    }
    ans = abs(stoi(n) - 100);

    go("");

    cout << ans;
}
