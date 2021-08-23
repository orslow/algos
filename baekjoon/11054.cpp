// basic dp
#include <bits/stdc++.h>

using namespace std;

int so1[1001];
int up[1001];
int down[1001];

int main() {

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(so1[j]<so1[i]) up[i] = max(up[i], up[j]);
        }
        up[i]++;
    }

    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>=i; j--) {
            if(so1[j]<so1[i]) down[i] = max(down[i], down[j]);
        }
        down[i]++;
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        if(up[i]+down[i] > ans) ans = up[i]+down[i];
    }
    cout << ans-1 << '\n';
}

