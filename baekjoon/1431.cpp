// make cmp function
#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b) {
    if (a.length() != b.length()) return a.length() < b.length();


    int ta=0, tb=0, tmp;
    for(int i=0; i<a.length(); i++) {
        tmp = a[i];
        if (tmp >= 48 && tmp <= 57) ta += tmp - 48;
    }

    for(int i=0; i<b.length(); i++) {
        tmp = b[i];
        if (tmp >= 48 && tmp <= 57) tb += tmp - 48;
    }

    if (ta != tb) return ta < tb;

    return a < b;
}

string guitars[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> guitars[i];
    }

    sort(guitars, guitars+n, cmp);

    for(int i=0; i<n; i++) {
        cout << guitars[i] << '\n';
    }

}


