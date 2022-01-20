// easy ad-hoc
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;


    int a=1;
    for(int i=0; i<n-1; i++) {
        cout << a << ' ';
        if(a==1) a=2;
        else a=1;
    }
    if(n%2==0) {
        cout << 2;
    } else {
        cout << 3;
    }
}
