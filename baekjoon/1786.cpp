// KMP. pi 배열 만드는 것 -> 틀렸을 때 처리 다음에 보면 또 까먹을 것 같다.
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t, p;

    getline(cin, t);
    getline(cin, p);

    // cout << t << '\n';
    // cout << p << '\n';

    int ps=p.size(), ts=t.size();
    vector <int> pi(ps, 0);
    int j=0;
    for(int i=1; i<ps; i++) {
        while(j>0 && p[i] != p[j]) j = pi[j-1];
        if (p[i] == p[j]) pi[i] = ++j;
    }

    /*
    for(auto a: pi) cout << a << ' ';
    cout << '\n';
    */

    j=0;
    vector <int> ans;
    for(int i=0; i<ts; i++) {
        while(j>0 && t[i] != p[j]) j = pi[j-1];
        if(t[i] == p[j]) {
            if(j == ps-1) { 
                ans.push_back(i-j+1); 
                j=pi[j];
                // cout << i << ' ' << j << '\n';
            }
            else j++;
        }
    }

    cout << ans.size() << '\n';
    for(auto a: ans) cout << a << ' ';
    cout << '\n';
}

