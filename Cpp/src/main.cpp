#include "solutions/day1.cpp"
#include "solutions/day2.cpp"
#include "solutions/day3.cpp"
#include "solutions/day6.cpp"
#include "solutions/day7.cpp"
#include "solutions/day9.cpp"

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

  std::cout << "Answer to the 6nd day - 1st stage test: " << stage1_6_test() << std::endl;
  std::cout << "Answer to the 6nd day - 1st stage: " << stage1_6() << std::endl;
  std::cout << "Answer to the 6nd day - 2nd stage test: " << stage2_6_test() << std::endl;
  std::cout << "Answer to the 6nd day - 2nd stage: " << stage2_6() << std::endl;

  std::cout << "Answer to the 7nd day - 1st stage test: " << stage1_7_test() << std::endl;
  std::cout << "Answer to the 7nd day - 1st stage: " << stage1_7() << std::endl;
  std::cout << "Answer to the 7nd day - 2nd stage test: " << stage2_7_test() << std::endl;
  std::cout << "Answer to the 7nd day - 2nd stage: " << stage2_7() << std::endl;

  std::cout << "Answer to the 9th day - 1st stage test: " << stage1_9(true) << std::endl;
  std::cout << "Answer to the 9th day - 1st stage: " << stage1_9(false) << std::endl;
  return 0;
}
