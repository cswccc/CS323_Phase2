int test_2_r10()
{
  int a[2][4][6][8];
  int b[4][6][8];
  int c[6][8];
  int d[8];
  int e;
  a[0] = b;
  a[0][1] = c;
  a[0][1][3] = d;
  a[0][1][3][5] = e;
  // a[1][3][5][7][9] = e[0];
  return a[e][e][e][e][e];
}