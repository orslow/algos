// two pointers
#include <bits/stdc++.h>

using namespace std;

string sol;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b, w;
    cin >> n >> b >> w;

    cin.ignore();

    getline(cin, sol);

    int l=0, r=0, wc=0, bc=0, way=0;
    while(l!=n && r!=n) {
        if(bc<=b) {
            if(sol[r++]=='W') {
                wc++; 
            }
            else {
                bc++;
            }
        }
        else {
            if(sol[l++]=='W') wc--; else bc--;
        }

        if(bc<=b && wc>=w && wc+bc>way) way=wc+bc;
    }

    cout << way << '\n';
}

