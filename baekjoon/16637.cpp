// brute force(simulation) still hard
#include <bits/stdc++.h>

using namespace std;

vector <string> su;
vector <string> op;

const int INF=2147483647;

bool per[19];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string form;
    cin >> form;

    if(form.size()==1) {
        cout << form << '\n';
        return 0;
    }
    if(form.size()==3) {
        if(form[1]=='+')
            cout << (form[0] - '0') + (form[2] -'0') << '\n';
        else if(form[1]=='-')
            cout << (form[0] - '0') - (form[2] -'0') << '\n';
        else
            cout << (form[0] - '0') * (form[2] -'0') << '\n';
        return 0;
    }

    op.push_back("#");
    su.push_back("#");
    for(int i=0; i<n; i++) {
        if(i%2) op.push_back(form.substr(i, 1));
        else su.push_back(form.substr(i, 1));
    }

    int ans=-INF;
    int fur=n/2;
    for(int i=0; i<n/4; i++) {

        per[fur--]=1;

        do {

            bool sec=0, dond=0;
            for(int i=1; i<n/2+1; i++) {
                if(per[i]==1 && sec) {
                    dond=1;
                    break;
                }
                else if(per[i]==1) sec=1;
                else if(per[i]==0) sec=0;
            }

            if(dond) continue;


            /*
            for(int i=0; i<n/2+1; i++) {
                cout << per[i] << ' ';
            }
            cout << '\n';
            */


            vector <string> tempo;
            for(int i=1; i<n/2+1; i++) {
                if(per[i-1] != 1 && per[i] == 0) {
                    tempo.push_back(su[i]);
                    tempo.push_back(op[i]);
                } else if(per[i] == 0) {
                    tempo.push_back(op[i]);
                } else if(per[i] == 1) {
                    if(op[i] == "+") {
                        tempo.push_back(to_string(stoi(su[i])+stoi(su[i+1])));
                    } else if (op[i] == "-") {
                        tempo.push_back(to_string(stoi(su[i])-stoi(su[i+1])));
                    } else if (op[i] == "*") {
                        tempo.push_back(to_string(stoi(su[i])*stoi(su[i+1])));
                    }
                }
            }
            if(per[n/2]==0) tempo.push_back(su[n/2+1]);

            // for(auto k: tempo) cout << k << ' ';
            string op1;
            int tum;
            for(int p=0; p<tempo.size(); p++) {
                if(p==0) tum=stoi(tempo[p]);
                else if(p%2==1) op1=tempo[p];
                else if(p%2==0) {
                    if(op1=="+") tum+=stoi(tempo[p]);
                    else if(op1=="-") tum-=stoi(tempo[p]);
                    else tum*=stoi(tempo[p]);
                }
            }
            // cout << tum << '\n';
            if(tum>ans) ans=tum;
            tempo.clear();

        } while(next_permutation(per+1, per+(n/2)+1));
    }

    cout << ans << '\n';

}

