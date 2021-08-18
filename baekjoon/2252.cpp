// basic topological sort
#include <bits/stdc++.h>

using namespace std;

int in[32001];
vector<int> fd[32001];

void topo(int n) {

    queue <int> qu;
    int cur;

    for(int i=1; i<=n; i++) {
        if(in[i] == 0) { 
            qu.push(i);
            cout << i << ' ';
        }
    }
    
    while(!qu.empty()) {
        cur=qu.front();
        qu.pop();

        for(auto v:fd[cur]) {
            in[v]--;
            if(in[v]==0) {
                qu.push(v);
                cout << v << ' ';
            }
        }
    }
    cout << '\n';

}

int main() {

    int n, m, a, b;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> a >> b;

        fd[a].push_back(b);
        in[b]+=1;
    }

    topo(n);
}
