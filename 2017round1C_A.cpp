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
  double R;
  double H;
}Pancake;

bool myfunction(Pancake p1, Pancake p2) { 
  return p1.H*p1.R > p2.H*p2.R;
}

bool myfunction2(Pancake p1, Pancake p2) {
  if (p1.R > p2.R)return true;
  if (p1.R < p2.R)return false;
  return p1.H > p2.H;
}

#define PI 3.14159265358979323846
string compute(int N, int K, vector<Pancake> pancakes) {
  assert(N == pancakes.size());

  sort(pancakes.begin(), pancakes.end(), myfunction2);

  double max = 0;
  for (int i = 0; i < N-K+1; i++) {
    Pancake bottom_p = pancakes[i];
    vector<Pancake> copy_pancakes;
    for (int j = i + 1; j < N; j++) {
      copy_pancakes.push_back(pancakes[j]);
    }
    sort(copy_pancakes.begin(), copy_pancakes.end(), myfunction);
    double sum = bottom_p.H*bottom_p.R;
    for (int i = 0; i < K - 1; i++) {
      Pancake p = copy_pancakes[i];
      sum += p.H*p.R;
    }
    sum *= 2;
    sum += bottom_p.R * bottom_p.R;
    sum *= PI;
    if (sum > max)max = sum;
  }

  char result[1000];
  memset(result, 0, 1000);
  sprintf(result, "%.9f", max);

  return string(result);
}

int main() {
  ifstream in("A-large.in");
  ofstream out("out.txt");

  int T;
  in >> T;
  for (int i = 1; i <= T; ++i) {
    int N, K;

    in >> N >> K;
    vector<Pancake> pancakes;
    for (int j = 0; j < N; j++) {
      Pancake p;
      in >> p.R >> p.H;
      pancakes.push_back(p);
    }
    
    out << "Case #" << i << ": " << compute(N, K, pancakes) << endl;
  }

  return 0;
}