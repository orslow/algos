// simulation
#include <bits/stdc++.h>

using namespace std;

int so1[10];
int res[10];

int ans;

void go(int a) {

    if(a==10) {
        int sc=0;
        for(int i=0; i<10; i++) {
            if(so1[i]==res[i]) sc++;
        }
        if(sc>=5) ans++;

        return;
    }

    for(int i=1; i<=5; i++) {
        res[a]=i;
        if(a>=2 && res[a-1]==res[a] && res[a-2]==res[a]) continue;
        go(a+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<10; i++) {
        cin >> so1[i];
    }

    go(0);

    cout << ans;
}
