// basic tree traverse
#include <bits/stdc++.h>

using namespace std;

int lc[27];
int rc[27];

void pre(int k) {
    cout << char(k+64);
    if(lc[k]>0) pre(lc[k]);
    if(rc[k]>0) pre(rc[k]);
}

void mid(int k) {
    if(lc[k]>0) mid(lc[k]);
    cout << char(k+64);
    if(rc[k]>0) mid(rc[k]);
}

void post(int k) {
    if(lc[k]>0) post(lc[k]);
    if(rc[k]>0) post(rc[k]);
    cout << char(k+64);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char p, l, r;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> p >> l >> r;
        lc[p-64]=l-64;
        rc[p-64]=r-64;
    }

    pre(1);
    cout << '\n';
    mid(1);
    cout << '\n';
    post(1);
    cout << '\n';


}

