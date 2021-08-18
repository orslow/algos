// 소인수 분해 복습
#include <bits/stdc++.h>

using namespace std;

multiset <int> so1;
multiset <int> so2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, s1, s2;
    cin >> t;
    while(t--) {
        cin >> s1 >> s2;

        for(int i=2; i*i<=s1; i++) {
            while(s1 % i == 0) { 
                so1.insert(i);
                s1 /= i;
            }
        }
        if (s1 != 1) so1.insert(s1);

        for(int i=2; i*i<=s2; i++) {
            while(s2 % i == 0) { 
                so2.insert(i);
                s2 /= i;
            }
        }
        if (s2 != 1) so2.insert(s2);

        int ans=1;
        for(auto v: so1) {
            if(so2.find(v) != so2.end()) {
                ans*=v;
                so2.erase(so2.find(v));
            }
            else ans*=v;
        }
        for(auto v: so2) ans*=v;

        cout << ans << '\n';

        so1.clear();
        so2.clear();

    }
}

