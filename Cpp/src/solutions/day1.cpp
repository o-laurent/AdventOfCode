#include <fstream>
#include <iostream>
#include <deque>

int stage1() {
  /**
   * @brief Resolve the stage1 of the December the first.
   * 
   */
  std::ifstream infile("../data/data1.txt");
  int val;
  int previous = 0;
  int counter = -1;

  while (infile >> val) {
    if (val >= previous) {
      counter++;
    }
    previous = val;
  }
  return counter;
}

int stage2() {
  /**
   * @brief Resolve the stage1 of the December the second.
   * 
   */
  std::ifstream infile("../data/data1.txt");
  int val;
  int val1=0;
  int val2=0;
  int val3=0;

  int counter = 0;
  
  while (infile >> val) {
    if (val1 != 0 && val > val1) counter++;
    val1 = val2;
    val2 = val3;
    val3 = val;
  }
  return counter;
}