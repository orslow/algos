// realize
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

double sup[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(2);

    int n;
    cin >> n;

    cin.ignore();
    
    string pb;
    for(int i=1; i<=n; i++) {

        for(int i=0; i<3; i++) {
            sup[i]=0;
        }

        getline(cin, pb);

        for(int i=0; i<pb.length(); i++) {
            if(pb[i]=='=') {
                int j=i+1;
                string su="";
                while(1) {
                    if((pb[j]>=48 && pb[j]<=57) || pb[j]==46) { // num
                        su+=pb[j];
                    }
                    else break;
                    j++;
                }
                double soo;
                if(pb[j]=='m' || pb[j]=='k' || pb[j]=='M') {
                    if(pb[j]=='m') soo=stod(su) * 0.001;
                    else if(pb[j]=='k') soo=stod(su) * 1000;
                    else soo=stod(su) * 1000000;
                }
                else {
                    soo=stod(su);
                }
                if(pb[i-1]=='P') {
                    sup[0]=soo;
                } else if(pb[i-1]=='U') {
                    sup[1]=soo;
                } else if(pb[i-1]=='I') {
                    sup[2]=soo;
                }
            }
        }
        cout << "Problem #" << i << '\n';
        if(sup[0]==0) {
            cout << "P=" << sup[1]*sup[2] << "W\n\n";
        }
        else if(sup[1]==0) {
            cout << "U=" << sup[0]/sup[2] << "V\n\n";
        }
        else {
            cout << "I=" << sup[0]/sup[1] << "A\n\n";
        }
    }
}

