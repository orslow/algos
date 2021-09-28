// union-find more practice need
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int br[300003];

int find(int a) {
    if(br[a]==a) return a;

    return find(br[a]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin >> n;

    for(int i=1; i<=n; i++) {
        br[i]=i;
    }

    for(int i=0; i<n-2; i++) {
        cin >> a >> b;
        int x=find(a);
        int y=find(b);
        if(x!=y) {
            if(x<y) {
                br[x]=y;
            }
            else {
                br[y]=x;
            }
        }
    }

    /*
    for(int i=1; i<=n; i++) {
        cout << br[i] << ' ';
    }
    cout << '\n';
    */

    for(int i=1; i<=n; i++) {
        if(br[i]==i) {
            cout << br[i] << ' ';
        }
    }
}

