// LRU
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,p;
    cin >> n >> m;

    list <int> pid;
    unordered_map <int, list<int>::iterator> sp;

    for(int i=0; i<n; i++) {
        cin >> p;
        if(sp.find(p)==sp.end()) {
            if(sp.size()==m) {
                int q=pid.back();
                pid.pop_back();
                sp.erase(q);
            }
        }
        else {
            pid.erase(sp.find(p)->second);
        }
        pid.push_front(p);
        sp[p]=pid.begin();
    }

    for(auto p: pid) cout << p << '\n';


}
