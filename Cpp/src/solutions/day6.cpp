#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <cstdint>

void update(std::vector<uint64_t> &states) {
  uint64_t newfish = states[0];
  states[0] = states[1];
  states[1] = states[2];
  states[2] = states[3];
  states[3] = states[4];
  states[4] = states[5];
  states[5] = states[6];
  states[6] = states[7] + newfish;
  states[7] = states[8];
  states[8] = newfish;
}

uint64_t stage1_6_test() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data6_test.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<uint64_t> states(9, 0);
  while (std::getline(stream, state, ',')) {
    states[stoi(state)]++;
  }

  for (int day = 1; day <= 80; day++) {
    update(states);
  }

  return std::accumulate(states.begin(), states.end(), decltype(states)::value_type(0));
}

uint64_t stage1_6() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data6.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<uint64_t> states(9, 0);
  while (std::getline(stream, state, ',')) {
    states[stoi(state)]++;
  }

  for (int day = 1; day <= 80; day++) {
    update(states);
  }

  return std::accumulate(states.begin(), states.end(), decltype(states)::value_type(0));
}

uint64_t stage2_6_test() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data6_test.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<uint64_t> states(9, 0);
  while (std::getline(stream, state, ',')) {
    states[(uint64_t)stoi(state)]++;
  }

  for (int day = 1; day <= 256; day++) {
    update(states);
  }

  return std::accumulate(states.begin(), states.end(), decltype(states)::value_type(0));
}

uint64_t stage2_6() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data6.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<uint64_t> states(9, 0);
  while (std::getline(stream, state, ',')) {
    states[(uint64_t)stoi(state)]++;
  }

  for (int day = 1; day <= 256; day++) {
    update(states);
  }

  return std::accumulate(states.begin(), states.end(), decltype(states)::value_type(0));
}