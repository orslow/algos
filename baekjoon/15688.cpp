#include <bits/stdc++.h>

using namespace std;

int su[2000001];

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int n, s;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s;
		su[s+1000000]+=1;
	}

	for(int i=0; i<2000001; i++) {
		for(int j=0; j<su[i]; j++) {
			cout << i - 1000000 << '\n';
		}
	}
}
