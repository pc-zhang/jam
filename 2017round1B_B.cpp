// test.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <boost/foreach.hpp>
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
  assert(r + o + y + g + b + v == n);
  
  return "IMPOSSIBLE";
}

int main() {
  ifstream in("sample.in");
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