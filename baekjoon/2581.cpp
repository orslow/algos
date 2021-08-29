// prime number(eratostenes)
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool so1[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, q;
    cin >> m >> n;


    so1[1]=1;
    for(int i=2; i<=n; i++) {
        if(so1[i]) continue;

        q=2;
        while(i*q<=n) {
            so1[i*q]=true;
            q+=1;
        }
    }

    int tot=0;
    int sml=0;
    for(int i=m; i<=n; i++) {
        if(!so1[i]) { 
            tot+=i;
            if(sml==0) sml=i;
        }
    }

    if(sml!=0) {
        cout << tot << '\n';
        cout << sml << '\n';
    }
    else cout << -1 << '\n';
}

