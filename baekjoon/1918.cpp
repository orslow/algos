// understand rule
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string fa;
    cin >> fa;

    string ans="";
    stack <char> ops;
    for(char c: fa) {
        int ci=c;
        if(ci>=65 && ci<=90) {
            ans+=c;
        } else {
            if(c=='(') {
                ops.push(c);
            } else if(c==')') {
                while(ops.top()!='(') {
                    ans+=ops.top();ops.pop();
                }
                ops.pop();
            } else if(c=='*' || c=='/') {
                while(!ops.empty() && (ops.top()=='*' || ops.top()=='/')) {
                    ans+=ops.top();ops.pop();
                }
                ops.push(c);
            } else  {
                while(!ops.empty() && ops.top()!='(') {
                    ans+=ops.top();ops.pop();
                }
                ops.push(c);
            }
        }
    }
    while(!ops.empty()) {
        ans+=ops.top();ops.pop();
    }
    cout << ans;
}
