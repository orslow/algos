#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool su[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, b;
    cin >> n;

    for(int i=123; i<=987; i++) {
        su[i]=true;
        string tmp = to_string(i);
        if(tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) su[i]=false;
        if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') su[i]=false;
    }

    string t;
    for(int i=0; i<n; i++) {
        cin >> t >> s >> b;

        for(int i=123; i<=987; i++) {

            if(su[i]==true) {
                string tmp = to_string(i);

                int strike=0, ball=0;
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {

                        if(t[i]==tmp[j] && i==j) strike++;
                        if(t[i]==tmp[j] && i!=j) ball++;
                    }
                }
                if(strike!=s || ball!=b) su[i]=false;
            }

        }
    }

    int ans=0;
    for(int i=123; i<=987; i++) {
        if(su[i]==true) ans++;
    }

    cout << ans << '\n';
}

