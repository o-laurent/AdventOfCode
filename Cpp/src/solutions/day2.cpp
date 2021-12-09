#include <fstream>
#include <iostream>
#include <string>

int stage1_2() {
  /**
   * @brief Resolve the stage1 of the December the first.
   *
   */

  std::ifstream infile("../data/data2.txt");

  std::string dir;
  int a;

  int x = 0;
  int z = 0;

  while (infile >> dir >> a) {
    if (dir.compare("forward") == 0)
      x += a;
    else if (dir.compare("down") == 0)
      z += a;
    else if (dir.compare("up") == 0)
      z -= a;
  }

  return x * z;
}

int stage2_2() {
  /**
   * @brief Resolve the stage1 of the December the second.
   *
   */
  std::ifstream infile("../data/data2.txt");

  std::string dir;
  int a;

  int x = 0;
  int z = 0;
  int aim = 0;

  while (infile >> dir >> a) {
    if (dir.compare("forward") == 0) {
      x += a;
      z += aim * a;
    } else if (dir.compare("down") == 0) {
      aim += a;
    } else if (dir.compare("up") == 0) {
      aim -= a;
    }
  }

  return x * z;
}