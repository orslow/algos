// 소수(에라토스테네스의 체)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> so1(1000001, true);

    int s, e;
    cin >> s >> e;

    so1[1]=0;
    for(int i=2; i*i<=e; i++) {

        if(so1[i] == true) {

            for(int j=i*i; j<=e; j+=i) {
                so1[j] = false;
            }

        }
    }

    int ans=0;
    for(int i=s; i<=e; i++) {
        if (so1[i] == 1) cout << i << '\n';
    }

}

