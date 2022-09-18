#include <bits/stdc++.h>

using namespace std;

int so1[13];

int main() {

    int n, a;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a;
        int c=0;
        for(int j=0; j<n; j++) {
            if(so1[j] == 0) {
                if(c==a) {
                    so1[j]=i+1;
                    break;
                }
                c++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << so1[i] << ' ';
    }
}

