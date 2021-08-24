// basic two pointers
#include <bits/stdc++.h>

using namespace std;

int so1[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    sort(so1, so1+n);

    int l=0, r=0, mini=2000000001;
    while(l!=n && r!=n) {
        int chai=abs(so1[r]-so1[l]);
        if(chai>=m) {
            if(chai<mini) mini=chai;
            l++;
        } else { 
            r++;
        }
    }

    cout << mini << '\n';
}

