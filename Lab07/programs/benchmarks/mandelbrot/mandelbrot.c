#include "util.h"

/* arithmetique de virgule fixe
   precision q = 8192 i.e. 13 bits pour la partie decimale */

int divide(int x, int y) {
	if (x<=0) return 1;
	else return (1+divide(x-y,y));
}

int multiply( int x, int y )
{

 int i;
 int result = 0;

 for (i = 0; i < 32; i++) {
   if ((x & 0x1) == 1)
     result = result + y;
       
   x = x >> 1;
   y = y << 1;
 } 
 
 return result;

}

int add(int x, int y) {
  return x + y;
}
int sub(int x, int y) {
  return x - y;
}
int mul(int x, int y) {
  int t;
  t = multiply(x , y);
  return (t + (4096)) >> 13;
}
int div(int x, int y) {
  int t;
  t = x << 13;
  return divide((t + (y >> 1)) , y);
}
int of_int(int x) {
  return x <<13;
}

int iter(int n, int a, int b, int xn, int yn) {
  int xn2, yn2;
  if (n == 100) return 1;
  xn2 = mul(xn, xn);
  yn2 = mul(yn, yn);
  if (add(xn2, yn2) > of_int(4)) return 0;
  return iter(n+1, a, b, add(sub(xn2, yn2), a),
              add(mul(of_int(2), mul(xn, yn)), b));
}

int inside(int x, int y) {
  return iter(0, x, y, of_int(0), of_int(0));
}

void run(int steps) {
  int xmin, xmax, deltax, ymin, ymax, deltay, i;
  xmin = of_int(-2);
  xmax = of_int(1);
  deltax = div(sub(xmax, xmin), of_int(2 * steps));
  ymin = of_int(-1);
  ymax = of_int(1);
  deltay = div(sub(ymax, ymin), of_int(steps));
  i;
  for (i = 0; i < steps; i++) {
    int y, j;
    y = add(ymin, mul(of_int(i), deltay));
    j;
    for (j = 0; j < 2 * steps; j++) {
      int x;
      x = add(xmin, mul(of_int(j), deltax));
      if (inside(x, y))
        printChar('0');
      else
        printChar('1');
    }
    printChar(10);
  }
}

int main() {
  int cycles, insts;
  cycles = getCycle();
  insts = getInsts();
  run(30);
  cycles = getCycle() - cycles;
  insts = getInsts() - insts;
  printStr("Cycles = "); printInt(cycles); printChar('\n');
  printStr("Insts  = "); printInt(insts); printChar('\n');
  return 0;
}
