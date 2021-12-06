// easy simulation
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,t,k;
    cin >> a >> t >> k;

    int b=0, d=0, g=2;
    while(1) {
        if(++b == t && k==0) {
            cout << (b+d-1)%a;
            return 0;
        }
        if(++d == t && k==1) {
            cout << (b+d-1)%a;
            return 0;
        }
        if(++b == t && k==0) {
            cout << (b+d-1)%a;
            return 0;
        }
        if(++d == t && k==1) {
            cout << (b+d-1)%a;
            return 0;
        }

        for(int i=0; i<g; i++) {
            if(++b == t && k==0) {
                cout << (b+d-1)%a;
                return 0;
            }
        }
        for(int i=0; i<g; i++) {
            if(++d == t && k==1) {
                cout << (b+d-1)%a;
                return 0;
            }
        }
        g++;
    }
}
