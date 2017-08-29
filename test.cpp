#include <iostream>
using namespace std;

int fastPower(int a, int b, int n) {
    int res = -1;
    int r = 1;
    int base = a;
    while(n) {
        if(n & 1) r *= base;
        if(-1 == res) {
            res = r % b;
        } else {
            res *= (r % b);
        }
        while(res >= b) {
            res %= b;
        }
        r = 1;
        base *= base;
        n >>= 1;
    }
    printf("%d\n", res);
    return res;
    
}

int main() {
  int a,b,n;
  cin>>a>>b>>n;
  fastPower(a,b,n);
  return 0;
}
