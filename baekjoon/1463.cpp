// basic dp concept
#include <bits/stdc++.h>

using namespace std;

int d[1000001];

void dp(int n) {

    if(n<=1) return;

    if (n%3 == 0) { 
        if(d[n/3] == 0 || d[n/3] > d[n] + 1) {
            d[n/3] = d[n] + 1;
            dp(n/3);
        }
    }
    if (n%2 == 0) {
        if(d[n/2] == 0 || d[n/2] > d[n] + 1) {
            d[n/2] = d[n] + 1;
            dp(n/2);
        }
    }
    if(n-1>=0 && d[n-1] == 0 || d[n-1] > d[n] + 1) {
        d[n-1] = d[n] + 1;
        dp(n-1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp(n);

    cout << d[1] << '\n';
}

