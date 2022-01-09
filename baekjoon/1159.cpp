// rest
#include <bits/stdc++.h>

using namespace std;

int so1[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        so1[s[0]-97]++;
    }

    string ans="";
    for(int i=0; i<26; i++) {
        if(so1[i]>=5) ans+=char(i+97);
    }
    
    if(ans=="") {
        cout << "PREDAJA";
    } else {
        cout << ans;
    }
}
