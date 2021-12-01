#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  int a;
  scanf("%d", &a);

  int b=a;

  if(b<10) {
    b=a*10+a;
  } else {
    b=a%10*10+(a/10+a%10)%10;
  }

  int cnt=1;
  while(a!=b) {
    if(b<10) {
      b=b*10+b;
    } else {
      b=b%10*10+(b/10+b%10)%10;
    }
    cnt++;
  }


  printf("%d\n", cnt);


  return 0;
}
