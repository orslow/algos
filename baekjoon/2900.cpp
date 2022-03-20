// prefix sum and little trick
#include <bits/stdc++.h>

using namespace std;

int so1[1000001];
int sop[1000001];
long long so2[1000001];

int n;

void something(int jump, int k) {
    int i = 0;
    while (i < n) {
        so1[i] = so1[i] + k;
        i = i + jump;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k,q,l,r,x;
    cin >> n >> k;

    for(int i=0; i<k; i++) {
        cin >> x;
        sop[x]++;
    }
    for(int i=0; i<n; i++) {
        if(sop[i]) {
            something(i, sop[i]);
        }
    }

    long long cur=0;
    for(int i=0; i<n; i++) {
        cur+=so1[i];
        so2[i]=cur;
    }

    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> l >> r;
        if(l!=0) {
            cout << so2[r] - so2[l-1] << '\n';
        } else {
            cout << so2[r] << '\n';
        }
    }

}
