// brute force but hard to find rule
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ff,fs,sf,ss;
    cin >> ff >> fs >> sf >> ss;

    if(ff==0 && fs==0) {
        if(sf==0) cout << ss;
        else cout << ss+1;
    } else if(fs==0) {
        cout << ff;
    } else {
        if(sf>=fs) {
            cout << ff+fs*2+ss;
        }
        else {
            cout << ff+sf*2+1+ss;
        }
    }
}
