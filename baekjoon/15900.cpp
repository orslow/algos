// tree DFS?
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

vector <int> ways[500005];
int height[500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        ways[a].push_back(b);
        ways[b].push_back(a);
    }

    queue <pair<int, int>> qu;
    for(int w: ways[1]) qu.push({1, w});
    height[1]=0;

    int ans=0;
    pair<int, int> tp;
    while(!qu.empty()) {
        tp=qu.front();qu.pop();
        int pa=tp.first, ch=tp.second;

        if(ways[ch].size()==1) {
            ans+=height[pa]+1;
            continue;
        }
        height[ch]=height[pa]+1;
        for(int w: ways[ch]) {
            if(w!=pa) qu.push({ch, w});
        }
    }
    if(ans%2) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

