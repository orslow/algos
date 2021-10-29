#include <cstdio>

bool si[10000];

int main() {

  int kef=0;
  int tmp;
  for(int i=1; i<10000; i++) {
    tmp=i;
    kef+=tmp;
    while(tmp>0) {
      kef+=tmp%10;
      tmp=tmp/10;
    }
    si[kef]=1;
    kef=0;
  }

  for(int i=1; i<10000; i++) {
    if(si[i]==0) {
      printf("%d\n", i);
    }
  }
}
