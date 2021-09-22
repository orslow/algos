// realization with string
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

string s;

void doj(string p) {
    int i=2;
    if(p[0]=='I') {
        string inp="";
        while(p[i]!=' ') {
            inp+=p[i++];
        }
        string pos="";
        while(i<p.length()) {
            pos+=p[i++];
        }
        int posi=stoi(pos);

        s.insert(posi, inp);
    }
    else {
        string st="",ed="";
        while(p[i]!=' ') {
            st+=p[i++];
        }
        i++;
        while(i<p.length()) {
            ed+=p[i++];
        }
        int sti=stoi(st), edi=stoi(ed);
        cout << s.substr(sti, edi-sti+1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string p;
    cin >> t >> s;

    while(t--) {

        cin.ignore();
        while(1) {
            getline(cin, p);
            if(p=="END") break;
            doj(p);
        }
    }
}
