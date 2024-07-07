#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
  int xs, ys, xe, ye, dx, dy;
  cin >> xs >> ys >> xe >> ye >> dx >> dy;

  if (dx == 0 && dy == 0) {
    cout << xe << " " << ye << "\n";
    return 0;
  }

  if (dx == 0) {
    if (dy < 0) {
      dy = -1;
    } else {
      dy = 1;
    }
  } else if (dy == 0) {
    if (dx < 0) {
      dx = -1;
    } else {
      dx = 1;
    }
  } else {
    int _gcd = abs(gcd(dx, dy));
    dx = dx / _gcd;
    dy = dy / _gcd;
  }

  float dis = sqrt(pow((xs - xe), 2) + pow((ys - ye), 2)) + 1;
  int ax, ay;
  while(1) {
    float _far = sqrt(pow((xs - xe), 2) + pow((ys - ye), 2));
    if(_far < dis) {
      dis = _far;
      ax = xe;
      ay = ye;
    } else {
      break;
    }
    xe += dx;
    ye += dy;
  }

  cout << ax << " " << ay << "\n";
}
