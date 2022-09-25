#include <bits/stdc++.h>

using namespace std;

vector <int> so1;
vector <int> so2;

int main() {

    int n,m;
    cin >> n >> m;

    int a,t,s,ansj0;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a>0) so1.push_back(a);
        else so2.push_back(-a);
    }

    if(so1.size()>0) {
        sort(so1.begin(), so1.end());
        if(so1.size()%m == 0) {
            s=m-1;
        } else {
            s=so1.size()%m-1;
        }

        while(s<so1.size()) {
            ans+=so1[s]*2;
            s+=m;
        }
    }

    if(so2.size()>0) {
        sort(so2.begin(), so2.end());

        if(so2.size()%m == 0) {
            s=m-1;
        } else {
            s=so2.size()%m-1;
        }

        while(s<so2.size()) {
            ans+=so2[s]*2;
            s+=m;
        }
    }

    if(so1.size() == 0) {
        ans -= so2[so2.size()-1];
    } else if (so2.size() == 0) {
        ans -= so1[so1.size()-1];
    } else {
        ans -= max(so1[so1.size()-1], so2[so2.size()-1]);
    }

    cout << ans << '\n';
}
