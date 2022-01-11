// rest
#include <bits/stdc++.h>

using namespace std;

int so1[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    int c=0, a=0, b=0;
    for(int i=0; i<n; i++) {
        if(so1[i]>c) {
            a++;
            c=so1[i];
        }
    }

    c=0;
    for(int i=n-1; i>=0; i--) {
        if(so1[i]>c) {
            b++;
            c=so1[i];
        }
    }

    cout << a << '\n' << b;
}
