#include <cstring>
#include <fstream>
#include <iostream>
#include <tuple>
#include <bitset>

std::tuple<int,int> stage1_3() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data3.txt");

  std::string str;

  unsigned char bits[12][1000];
  int line = 0;
  while (infile >> str) {
    unsigned char count = 0;
    for (char const &c : str) {
      bits[count][line] = (unsigned char)(c - '0');
      count++;
    }
    line++;
  }

  int gamma_rate = 0;
  int epsilon_rate = 0;

  int power2 = 1;
  for (int i = 11; i >= 0; i--) {
    int count0 = 0;
    int count1 = 0;
    for (int j = 0; j < 1000; j++) {
      if (bits[i][j] == 0)
        count0++;
      else
        count1++;
    }
    if (count1 > count0) {
      gamma_rate += power2;
    }
    power2 *= 2;
  }
  std::bitset<32> bitwise(gamma_rate);
  std::cout << bitwise << std::endl;
  int eps_rate = ~gamma_rate & ((1<<12)-1);
  return std::make_tuple(gamma_rate, eps_rate);
}

int stage2_3() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */
  std::ifstream infile("../data/data3.txt");
  std::string str;

  while (infile >> str) {
  }
}