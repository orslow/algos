// very little deep topological sort
#include <bits/stdc++.h>

using namespace std;

int in[1001];
vector<int> fd[1001];
int cost[1001];
int st[1001];

void topo(int n, int t) {

    queue <int> qu;
    vector <int> pr;
    int cur;

    for(int i=1; i<=n; i++) {
        if(in[i] == 0) { 
            qu.push(i);
            st[i]=cost[i];
        }
    }
    
    while(!qu.empty()) {
        cur=qu.front();
        qu.pop();

        for(auto v:fd[cur]) {
            st[v]=max(st[v], st[cur]+cost[v]);
            in[v]--;
            if(in[v]==0) {
                if(v==t) {
                    cout << st[v] <<'\n';
                    return;
                }
                qu.push(v);
            }
        }
    }
    cout << st[t] << '\n';
}

int main() {

    int t, n, m, x, y, tf;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        for(int i=1; i<=n; i++) {
            cin >> cost[i];
        }

        for(int i=0; i<m; i++) {
            cin >> x >> y;
            fd[x].push_back(y);
            in[y]++;
        }

        cin >> tf;
        topo(n, tf);

        for(int i=1; i<=n; i++) {
            st[i]=0;
            in[i]=0;
            fd[i].clear();
        }
    }
}


