// math
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

bool isPrime[10000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2; i<=1003001; i++) {
        isPrime[i]=1;
    }

    for(int i=2; i<=1003001; i++) {
        if(isPrime[i]==0) continue;

        // cout << i << '\n';
        for(int j=i*2; j<=1003001; j+=i) {
            isPrime[j]=0;
        }
    }

    int n;
    cin >> n;

    for(int i=n; i<=1003001; i++) {
        if(isPrime[i]) {
            string tmp=to_string(i);

            int st=0, ed=tmp.length()-1;
            bool isPal=true;
            while(st<=ed) {
                if(tmp[st]!=tmp[ed]) {
                    isPal=false;
                    break;
                }
                st++; ed--;
            }
            if(isPal) {
                cout << i << '\n';
                break;
            }
        }
    }

}
