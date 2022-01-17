// cover all cases?
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int i=0;
    while(i<s.length()) {
        int n=0;
        while(i<s.length() && s[i]=='w') {
            n++;
            i++;
        }
        if(n==0) {
            cout << 0;
            return 0;
        }
        int cnt=0;
        while(i<s.length() && s[i]=='o') {
            cnt++;
            i++;
        }
        if(cnt!=n) {
            cout << 0;
            return 0;
        }
        cnt=0;
        while(i<s.length() && s[i]=='l') {
            cnt++;
            i++;
        }
        if(cnt!=n) {
            cout << 0;
            return 0;
        }
        cnt=0;
        while(i<s.length() && s[i]=='f') {
            cnt++;
            i++;
        }
        if(cnt!=n) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
