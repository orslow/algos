// basic dp
#include <bits/stdc++.h>

using namespace std;

int coins[4]={1,2,5,7};
bool vis[100001];

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    queue<pair<int, int>> qu;
    qu.push({0, 0});

    while(1) {
        int w=qu.front().first, c=qu.front().second; qu.pop();
        if(w==n) {
            cout << c;
            return 0;
        }
        for(int i=0; i<4; i++) {
            int cur=w+coins[i];
            if(vis[cur]==0) {
                vis[cur]=1;
                qu.push({cur, c+1});
            }
        }
    }
}
