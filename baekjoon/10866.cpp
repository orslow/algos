#include <cstdio>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque <int> kef;

int main() {

	int N;
	scanf("%d\n", &N);

	string p;
	for(int i=0; i<N; i++) {
		getline(cin, p);
		if(p[0]=='p') {
			if(p[1]=='u') { // push
				if(p[5]=='f') {
					kef.push_front(stoi(p.substr(11, p.length()-1)));
				} else {
					kef.push_back(stoi(p.substr(10, p.length()-1)));
				}
			} else { // pop
				if(!kef.size()) {
					printf("-1\n");
				}
				else {
					if(p[4]=='f') {
						printf("%d\n", kef.front());
						kef.pop_front();
					} else {
						printf("%d\n", kef.back());
						kef.pop_back();
					}
				}
			}
		} else if(p[0]=='s') {
			printf("%d\n", kef.size());
		} else if(p[0]=='e') {
			if(kef.size()) {
				printf("0\n");
			} else {
				printf("1\n");
			}
		} else if(p[0]=='f'){ 
			if(kef.size()) {
				printf("%d\n", kef.front());
			} else {
				printf("-1\n");
			}
		} else { // b
			if(kef.size()) {
				printf("%d\n", kef.back());
			} else {
				printf("-1\n");
			}
		}
	}

	return 0;
}
