// simulation
#include <bits/stdc++.h>

using namespace std;

vector <char> os={'a', 'e', 'i', 'o', 'u', 'h'};
vector <string> os2={"c", "j", "n", "m", "t", "s", "l", "d", "qu"};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    int ans=1;
    string cur="";
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='-') {
            ans++;
            cur="";
        } else if(s[i]==' ') {
            ans++;
            cur="";
        } else if(s[i]=='\'') {
            if(find(os2.begin(), os2.end(), cur) != os2.end()) {
                if(find(os.begin(), os.end(), s[i+1]) != os.end()) {
                    ans++;
                    cur="";
                }
            }
        } else {
            cur+=s[i];
        }
    }
    cout << ans;
}
