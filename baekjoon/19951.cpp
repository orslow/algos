// prefix sum
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int gr[100003];
int job[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b,k;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        cin >> gr[i];
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b >> k;
        job[a]+=k;
        job[b+1]-=k;
    }

    int cur=0;
    for(int i=1; i<=n; i++) {
        cur+=job[i];
        gr[i]+=cur;
        cout << gr[i] << ' ';
    }
}
