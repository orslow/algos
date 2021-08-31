// brute force
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int maxi=0;
    vector <int> soo;
    vector <int> ans;
    for(int i=n/2; i<=n; i++) {
        int cur=n, k=i, cand=0;
        soo.push_back(n);
        while(cur-k>=0) {
            int tmp=k;
            k=cur-k;
            cur=tmp;
            soo.push_back(cur);
        }
        soo.push_back(k);
        if(soo.size()>maxi) { 
            ans=soo;
            maxi=soo.size();
        }
        soo.clear();
    }

    cout << maxi << '\n';
    for(auto v: ans) cout << v << ' ';
    cout << '\n';
}

