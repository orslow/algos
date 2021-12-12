// not easy to get idea
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    cin >> n;

    int n2=0, sum=0;
    for(int i=0; i<n; i++) {
        cin >> a;
        sum+=a;
        n2+=a/2;
    }

    if(sum%3==0 && n2>= sum/3) {
        cout << "YES";
    } else {
        cout << "NO";
    }


}
