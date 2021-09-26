// easy
#include<bits/stdc++.h>

using namespace std;

int main() {
    int a;
    string b;
    cin >> a >> b;

    cout << a*((int)b[2]-48) << '\n';
    cout << a*((int)b[1]-48) << '\n';
    cout << a*((int)b[0]-48) << '\n';
    cout << a*stoi(b);
}
