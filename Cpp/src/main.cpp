#include "solutions/day1.cpp"
#include "solutions/day2.cpp"
#include "solutions/day3.cpp"
#include <iostream>
#include <tuple>

int main(int argc, const char **argv) {
  std::cout << "Answer to the 1st day - 1st stage: " << stage1_1() << std::endl;
  std::cout << "Answer to the 1st day - 2nd stage: " << stage2_1() << std::endl;

  std::cout << "Answer to the 2nd day - 1st stage: " << stage1_2() << std::endl;
  std::cout << "Answer to the 2nd day - 2nd stage: " << stage2_2() << std::endl;

  std::tuple<int, int> val = stage1_3();
  int gamma = std::get<0>(val);
  int eps = std::get<1>(val);
  std::cout << "Answer to the 3rd day - 1st stage: gamma: " << gamma
            << "; eps: " << eps << "; prod: " << gamma * eps << std::endl;
  return 0;
}
