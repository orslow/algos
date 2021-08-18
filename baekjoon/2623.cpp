// basic topological sort #2
#include <bits/stdc++.h>

using namespace std;

int in[1001];
vector<int> fd[1001];

void topo(int n) {

    queue <int> qu;
    vector <int> pr;
    int cur;

    for(int i=1; i<=n; i++) {
        if(in[i] == 0) { 
            qu.push(i);
            pr.push_back(i);
            // cout << i << ' ';
        }
    }
    
    while(!qu.empty()) {
        cur=qu.front();
        qu.pop();

        for(auto v:fd[cur]) {
            in[v]--;
            if(in[v]==0) {
                qu.push(v);
                pr.push_back(v);
                // cout << v << ' ';
            }
        }
    }
    /*
    for(int i=1; i<=n; i++) {
        if(in[i] != 0) { 
            cout << 0 << '\n';
            return;
        }
    }
    */
    if(pr.size()!=n) {
        cout << 0 << '\n';
        return;
    }
    for(auto v: pr) cout << v << '\n';
}

int main() {

    int n, m, s, t;
    cin >> n >> m;

    vector <int> tmp;
    while(m--) {
        cin >> s;
        for(int i=0; i<s; i++) {
            cin >> t;
            tmp.push_back(t);
        }
        for(int i=0; i<tmp.size()-1; i++) {
            for(int j=i+1; j<tmp.size(); j++) {
                fd[tmp[i]].push_back(tmp[j]);
                in[tmp[j]]++;
            }
        }
        tmp.clear();
    }

    /*
    for(int i=1; i<=n; i++) {
        cout << i << ": ";
        for(auto u: fd[i]) cout << u << ' ';
        cout << '\n';
    }
    */

    topo(n);
}


