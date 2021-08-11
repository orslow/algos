// basic dp concept #2
#include <bits/stdc++.h>

using namespace std;

int d[1000001];
int du[1000001];

void dp(int n) {

    if(n<=1) return;

    if (n%3 == 0) { 
        if(d[n/3] == 0 || d[n/3] > d[n] + 1) {
            d[n/3] = d[n] + 1;
            du[n/3] = n;
            dp(n/3);
        }
    }
    if (n%2 == 0) {
        if(d[n/2] == 0 || d[n/2] > d[n] + 1) {
            d[n/2] = d[n] + 1;
            du[n/2] = n;
            dp(n/2);
        }
    }
    if(n-1>=0 && (d[n-1] == 0 || d[n-1] > d[n] + 1)) {
        d[n-1] = d[n] + 1;
        du[n-1] = n;
        dp(n-1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    d[n]=0;
    dp(n);

    cout << d[1] << '\n';

    stack <int> tp;
    int k=1;
    while(k!=n) {
        tp.push(k);
        k = du[k];
    }

    tp.push(n);
    while(!tp.empty()) {
        cout << tp.top() << ' ';
        tp.pop();
    }
    cout << '\n';
}

/*

// good answer

#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int pre[1000005];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 0;
    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + 1;
        pre[i] = i-1;
        if(i%2 == 0 && d[i] > d[i/2] + 1){
            d[i] = d[i/2] + 1;
            pre[i] = i/2;
        }
        if(i%3 == 0 && d[i] > d[i/3] + 1){
            d[i] = d[i/3] + 1;
            pre[i] = i/3;
        }
    }
    cout << d[n] << '\n';
    int cur = n;
    while(true){
        cout << cur << ' ';
        if(cur == 1) break;
        cur = pre[cur];    
    }
}
*/

