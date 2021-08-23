// DFS review needs
#include <bits/stdc++.h>

using namespace std;

vector <int> dd[1001];

stack <int> pat;
vector <int> vec;

bool visited[1001][15];

int n;
bool done, nod;

void dup(int ls, int k) {
    if(done) return;
    if(k==n) {
        for(auto v: vec) cout << v << '\n';
        done=true;
        return;
    }
    for(int i=0; i<dd[k].size(); i++) {
        if(ls!=dd[k][i] && !visited[k][dd[k][i]]) {

            visited[k][dd[k][i]]=1;
            vec.push_back(dd[k][i]);
            dup(dd[k][i], k+1);
            vec.pop_back();
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, s;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> m;

        while(m--) {
            cin >> s;
            dd[i].push_back(s);
        }
    }

    done=false;

    dup(0, 0);

    if(!done) cout << -1 << '\n';
}

