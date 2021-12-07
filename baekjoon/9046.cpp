// easy simulation
#include <bits/stdc++.h>

using namespace std;

int so1[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    cin.ignore();

    string s;
    while(t--) {
        getline(cin, s);

        for(int i=0; i<26; i++) {
            so1[i]=0;
        }

        for(int i=0; i<s.length(); i++) {
            if(s[i]-97>=0)
                so1[s[i]-97]++;
        }

        int m=0, alp;
        for(int i=0; i<26; i++) {
            if(so1[i]>m) {
                m=so1[i];
                alp=i;
            }
        }

        int cnt=0;
        for(int i=0; i<26; i++) {
            if(so1[i]==m) cnt++;
        }

        if(cnt>1) {
            cout << '?' << '\n';
        } else {
            cout << char(alp+97) << '\n';
        }
    }
}
