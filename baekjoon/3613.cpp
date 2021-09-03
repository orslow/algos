// picky conditions
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string var;
    cin >> var;

    bool isJava=true, isCpp=true;

    int n=var.length(), ch;

    ch=var[0]-0;
    if(ch>=97 && ch<=122) { // 첫 알파벳 소문자
        for(int i=1; i<n; i++) {
            ch=var[i]-0;
            if(ch==95) {
                isJava=0;
                break;
            }
        }
    } else {
        isJava=false;
    }

    ch=var[0]-0;
    if(var[0]!='_' && var[n-1]!='_') {
        for(int i=0; i<n; i++) {
            ch=var[i]-0;
            if(ch==95 && var[i+1]-0==95) {
                isCpp=0;
                break;
            }
            if(ch>=65 && ch<=90) {
                isCpp=0;
                break;
            }
        }
    } else {
        isCpp=0;
    }

    // cout << isJava+isCpp << '\n';

    if(isJava+isCpp==0) {
        cout << "Error!";
        return 0;
    } else if(isJava+isCpp==2) {
        cout << var << '\n';
        return 0;
    }

    string ans="";
    if(isJava) {
        for(int i=0; i<n; i++) {
            ch=var[i]-0;
            if(ch>=65 && ch<=90) {
                ans+='_';
                ans+=ch+32;
            }
            else {
                ans+=ch;
            }
        }
    }
    else {
        for(int i=0; i<n; i++) {
            ch=var[i]-0;
            if(ch==95) {
                ans+=var[i+1]-32;
                i++;
            }
            else {
                ans+=ch;
            }
        }
    }
    cout << ans;
}
