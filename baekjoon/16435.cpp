// easy -> faster needs
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,l,h;
    cin >> n >> l;

    vector <int> v;
    for(int i=0; i<n; i++) {
        cin >> h;
        v.push_back(h);
    }

    sort(v.begin(), v.end());

    for(int h: v) {
        if(h<=l) l++;
        else break;
    }

    cout << l;


}

