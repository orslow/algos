// recursive simulation
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int n,ans;

void so1(vector <int> vec, int cur) {

    if(vec.size()==2) {
        if(cur>ans) ans=cur;
        return;
    }

    for(int i=1; i<vec.size()-1; i++) {
        vector <int> tmp;
        for(int j=0; j<vec.size(); j++) {
            if(j==i) continue;
            tmp.push_back(vec[j]);
        }
        so1(tmp, cur+vec[i-1]*vec[i+1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector <int> s;

    int a;
    for(int i=0; i<n; i++) {
        cin >> a;
        s.push_back(a);
    }

    so1(s, 0);

    cout << ans;
}
