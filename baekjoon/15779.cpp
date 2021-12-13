// think and brute force
#include <bits/stdc++.h>

using namespace std;

int so1[5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> so1[i];
    }

    int l=2, cur=1, s=0;
    for(int i=0; i<n-1; i++) {
        if(so1[i]<so1[i+1]) {
            if(s!=1) {
                cur++;
            } else {
                cur=2;
            }
            if(cur>l) l=cur;
            s=1;
        } else if(so1[i]>so1[i+1]) {
            if(s!=-1) {
                cur++;
            } else {
                cur=2;
            }
            if(cur>l) l=cur;
            s=-1;
        } else {
            s=0;
            cur=1;
        }
    }

    cout << l;
}
