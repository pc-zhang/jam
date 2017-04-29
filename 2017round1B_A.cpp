// test.cpp : 定义控制台应用程序的入口点。
//
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cassert>
using namespace std;

string compute(int n, int r, int o, int y, int g, int b, int v) {
  assert(r+o+y+g+b+v==n);
  //assert(0==o && 0==g && 0==v);
  if (0 == o && 0 == g && 0 == v) {

  }


  return "IMPOSSIBLE";
}

int main() {
  ifstream in("samples.txt");
  ofstream out("out.txt");

  int T;
  in >> T;
  for (int i = 1; i <= T; ++i) {
    int n, r, o, y, g, b, v;

    in >> n >> r >> o >> y >> g >> b >> v;
    out << "Case #" << i << ": " << compute(n, r, o, y, g, b, v) << endl;
  }

  return 0;
}