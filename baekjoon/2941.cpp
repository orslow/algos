// easy realization
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n=s.size();

    int ans=0;
    for(int i=0; i<n; i++) {
        if(i+1<n && s[i]=='c' && (s[i+1]=='=' || s[i+1]=='-')) {
            ans+=1;
            i+=1;
        } else if(s[i]=='d') {
                if(i+2<n && s[i+1]=='z' && s[i+2]=='=') {
                    ans+=1;
                    i+=2;
                } else if(i+1<n && s[i+1]=='-') {
                    ans+=1;
                    i+=1;
                } else {
                    ans+=1;
                }
        } else if(i+1<n && s[i]=='l' && s[i+1]=='j') {
            ans+=1;
            i+=1;
        } else if(i+1<n && s[i]=='n' && s[i+1]=='j') {
            ans+=1;
            i+=1;
        } else if(i+1<n && s[i]=='s' && s[i+1]=='=') {
            ans+=1;
            i+=1;
        } else if(i+1<n && s[i]=='z' && s[i+1]=='=') {
            ans+=1;
            i+=1;
        } else {
            ans+=1;
        }
    }
    cout << ans << '\n';
}
