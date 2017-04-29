// test.cpp : 定义控制台应用程序的入口点。
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

typedef struct {
  int K;
  int S;
}Horse;

string compute(int D, int N, const vector<Horse> &horses) {
  assert(N == horses.size());
  double max_time = 0;

  BOOST_FOREACH(Horse h, horses) {
    double time = 1.0*(D - h.K) / h.S;
    if (time > max_time) {
      max_time = time;
    }
  }

  double max_speed = D / max_time;

  return to_string(max_speed);
}

int main() {
  ifstream in("A-large-practice.in");
  ofstream out("out.txt");

  int T;
  in >> T;
  for (int i = 1; i <= T; ++i) {
    int D, N;

    in >> D >> N;
    vector<Horse> horses;
    for (int j = 0; j < N; j++) {
      Horse h;
      in >> h.K >> h.S;
      horses.push_back(h);
    }
    out << "Case #" << i << ": " << compute(D,N,horses) << endl;
  }

  return 0;
}