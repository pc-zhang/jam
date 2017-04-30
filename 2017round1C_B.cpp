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
  int start;
  int end;
  int who;
}Activity;

bool myfunction(Activity a1, Activity a2) {
  return a1.start < a2.start;
}


string compute(int Ac, int Aj, vector<Activity> activities) {
  assert(Ac + Aj == activities.size());
  assert(Ac <= 2 && Ac >=0);
  assert(Aj <= 2 && Aj >= 0);
  assert(Ac + Aj <= 2);
  assert(Ac + Aj >= 1);

  sort(activities.begin(), activities.end(), myfunction);

  if (Ac == 0 && Aj == 0) {
    return to_string(2);
  }
  else if (Ac == 0 && Aj == 1) {
    return to_string(2);
  }
  else if (Ac == 0 && Aj == 2) {
    Activity a0 = activities[0];
    Activity a1 = activities[1];
    if (a1.end - a0.start > 720 && a0.end + 1440 - a1.start > 720) {
      return to_string(4);
    }
    return to_string(2);
  }
  else if (Ac == 1 && Aj == 0) {
    return to_string(2);
  }
  else if (Ac == 1 && Aj == 1) {
    return to_string(2);
  }
  else if (Ac == 2 && Aj == 0) {
    Activity a0 = activities[0];
    Activity a1 = activities[1];
    if (a1.end - a0.start > 720 && a0.end + 1440 - a1.start > 720) {
      return to_string(4);
    }
    return to_string(2);
  }
  else {
    assert(0 == 1);
  }

  return string("");
}

int main() {
  ifstream in("B-small-attempt0.in");
  ofstream out("out.txt");

  int T;
  in >> T;
  for (int i = 1; i <= T; ++i) {
    int Ac, Aj;

    in >> Ac >> Aj;
    vector<Activity> activities;
    for (int j = 0; j < Ac; j++) {
      Activity a;
      in >> a.start >> a.end;
      a.who = 0;
      activities.push_back(a);
    }
    for (int j = 0; j < Aj; j++) {
      Activity a;
      in >> a.start >> a.end;
      a.who = 1;
      activities.push_back(a);
    }
    
    out << "Case #" << i << ": " << compute(Ac, Aj, activities) << endl;
  }

  return 0;
}