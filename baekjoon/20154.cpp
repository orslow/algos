// simulation
#include <bits/stdc++.h>

using namespace std;

int so1[26]={3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int c=0;
    for(int i=0; i<s.length(); i++) {
        c+=so1[int(s[i])-65];
    }
    c%=10;
    if(c%2==0) {
        cout << "You're the winner?";
    } else {
        cout << "I'm a winner!";
    }
}
