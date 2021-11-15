// greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int red=0, blue=0;
    char c;
    if(s[0]==s[n-1]) {
        c=s[0];
        int i=1,l=1,r=1;
        while(i<n) {
            if(c==s[i]) {
                l++;
                i++;
            } else {
                break;
            }
        }
        i=n-2;
        while(i>=0) {
            if(c==s[i]) {
                r++;
                i--;
            } else {
                break;
            }
        }
        if(c=='R') {
            red-=max(l, r);
        } else {
            blue-=max(l, r);
        }
    } else {
        c=s[0];
        int i=1,l=1,r=1;
        while(i<n) {
            if(c==s[i]) {
                l++;
                i++;
            } else {
                break;
            }
        }
        c=s[n-1];
        i=n-2;
        while(i>=0) {
            if(c==s[i]) {
                r++;
                i--;
            } else {
                break;
            }
        }
        if(c=='R') {
            red-=r;
            blue-=l;
        } else {
            red-=l;
            blue-=r;
        }
    }

    // cout << red << ' ' << blue << '\n';

    char cur=s[0];
    int cun=1;
    for(int i=1; i<n; i++) {
        if(s[i]!=cur) {
            if(cur=='R') {
                red+=cun;
                cur='B';
            } else {
                blue+=cun;
                cur='R';
            }
            cun=1;
        } else {
            cun++;
        }
    }
    if(cur=='R') {
        red+=cun;
    } else {
        blue+=cun;
    }
    cout << min(red, blue);
}
