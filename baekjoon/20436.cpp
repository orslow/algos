// lot work
#include <bits/stdc++.h>

using namespace std;

set <char> la={'q','w','e','r','t','a','s','d','f','g','z','x','c','v'};
set <char> ra={'y','u','i','o','p','h','j','k','l','b','n','m'};

map <char, pair<int, int>> lm={{'q', {0,0}}, {'w', {0,1}}, {'e', {0,2}}, {'r', {0,3}}, {'t', {0,4}}, {'a', {1,0}}, {'s', {1,1}}, {'d', {1,2}}, {'f', {1,3}}, {'g', {1,4}}, {'z', {2,0}}, {'x', {2,1}}, {'c', {2,2}}, {'v', {2,3}}};

map <char, pair<int, int>> rm={{'y', {0,5}}, {'u', {0,6}}, {'i', {0,7}}, {'o', {0,8}}, {'p', {0,9}}, {'h', {1,5}}, {'j', {1,6}}, {'k', {1,7}}, {'l', {1,8}}, {'b', {2,4}}, {'n', {2,5}}, {'m', {2,6}}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char a,b;
    cin >> a >> b;

    int x,y,rx,ry,lx,ly;
    lx=lm[a].first;
    ly=lm[a].second;
    rx=rm[b].first;
    ry=rm[b].second;

    string s;
    cin >> s;

    int ans=0;
    for(int i=0; i<s.length(); i++) {
        if(la.find(s[i]) != la.end()) {
            ans+=abs(lx-lm[s[i]].first);
            ans+=abs(ly-lm[s[i]].second);
            lx=lm[s[i]].first;
            ly=lm[s[i]].second;
        } else {
            ans+=abs(rx-rm[s[i]].first);
            ans+=abs(ry-rm[s[i]].second);
            rx=rm[s[i]].first;
            ry=rm[s[i]].second;
        }
        ans+=1;
    }
    cout << ans;

}
