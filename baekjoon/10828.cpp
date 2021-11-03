// stack
#include <bits/stdc++.h>

using namespace std;

stack <int> kef;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cin.ignore();

    string p;
    for(int i=0; i<n; i++) {
        getline(cin, p);
        if(p[0]=='p') {
            if(p[1]=='u') {
                kef.push(stoi(p.substr(5, p.length()-1)));
            } else {
                if(kef.size()==0) {
                    cout << -1 << '\n';
                } else {
                    cout << kef.top() << '\n';
                    kef.pop();
                }
            }
        } else if(p[0]=='s') {
            cout << kef.size() << '\n';
        } else if(p[0]=='e') {
            if(kef.size()) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        } else { // t
            if(kef.size()) {
                cout << kef.top() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}
