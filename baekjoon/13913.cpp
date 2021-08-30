// graph(BFS)
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool vis[100001];
int wal[100001];

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    // wonder(n, 0);

    queue <pair<int, int>> qu;
    qu.push({n, 0});
    wal[n]=-1;
    vis[n]=1;

    pair<int, int> tmp;
    while(!qu.empty()) {
        tmp=qu.front();qu.pop();
        int cur=tmp.first, w=tmp.second;

        // cout << cur << '\n';

        if(cur==k) {
            cout << w << '\n';
            stack <int> tmp;
            tmp.push(k);
            int fd=cur;
            while(wal[fd]!=-1) {
                tmp.push(wal[fd]);
                fd=wal[fd];
            }
            while(!tmp.empty()) {
                cout << tmp.top() << ' ';
                tmp.pop();
            }
            cout << '\n';
            break;
        }
        if(cur+1<=100000 && vis[cur+1]==0) {
            vis[cur+1]=1;
            wal[cur+1]=cur;
            qu.push({cur+1, w+1});
        }
        if(cur-1>=0 && vis[cur-1]==0) {
            vis[cur-1]=1;
            wal[cur-1]=cur;
            qu.push({cur-1, w+1});
        }
        if(cur*2<=100000 && vis[cur*2]==0) {
            vis[cur*2]=1;
            wal[cur*2]=cur;
            qu.push({cur*2, w+1});
        }
    }
}
