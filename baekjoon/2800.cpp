#include <bits/stdc++.h>

using namespace std;

int gh[11];
int cnt, cur, cur2;

set<string> stt;
stack<bool> stk;

string sik, sup, bf;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sik;

    for(int i=0; i<sik.length(); i++) {
        if(sik[i] == '(') cnt++;
    }

    int ku, su;
    for(int i=1; i<int(pow(2, cnt)); i++) {
        ku = i;
        su=0;
        for(int j=cnt-1; j>=0; j--) {
            gh[su++]= int(ku / pow(2, j));
            ku = ku % int(pow(2, j));
        }
        /*
        for (int i=0; i<cnt; i++) {
            cout << gh[i] << ' ';
        }
        cout << '\n';
        */

        cur=0;

        string sup="";

        for(int j=0; j<sik.length(); j++) {
            if (sik[j] == '(' && gh[cur]==0) {
                sup+=sik[j];
                stk.push(0);
                cur++;
            }
            else if (sik[j] == '(' && gh[cur]==1) {
                cur++;
                stk.push(1);
                continue;
            }
            else if (sik[j] == ')' && stk.top()==0) {
                stk.pop();
                sup+=sik[j];
            }
            else if (sik[j] == ')' && stk.top()==1) {
                stk.pop();
                continue;
            }
            else {
                sup+=sik[j];
            }
        }

        stt.insert(sup);

    }

    for(auto k: stt) cout << k << '\n'; 
}


