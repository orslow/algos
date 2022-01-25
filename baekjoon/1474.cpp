// little bit complex greedy, string
#include <bits/stdc++.h>

using namespace std;

string so1[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int uc=0,lc=0, tl=0;
    string a;
    for(int i=0; i<n; i++) {
        cin >> a;
        so1[i]=a;
        tl+=a.length();
        if(i==0) continue;
        if(a[0]-0>=65 && a[i]-0<=90) uc++;
        else lc++;
    }

    int su=(m-tl)/(n-1), lf=(m-tl)%(n-1);

    string base="";
    for(int i=0; i<su; i++) {
        base+='_';
    }

    for(int i=1; i<n; i++) {
        if(so1[i][0]-0>=97 && so1[i][0]<=122 && lf>0) {
            so1[i]=base+'_'+so1[i];
            lf--;
        }
    }
    for(int i=n-1; i>=0; i--) {
        if(so1[i][0]-0>=65 && so1[i][0]<=90 && lf>0) {
            so1[i]=base+'_'+so1[i];
            lf--;
        }
    }

    cout << so1[0];
    for(int i=1; i<n; i++) {
        if(so1[i][0]!='_') {
            cout << base+so1[i];
        } else {
            cout << so1[i];
        }
    }
}
