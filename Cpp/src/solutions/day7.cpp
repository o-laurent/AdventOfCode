#include <algorithm>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

long median(std::vector<long> &states) {
  long n = states.size() / 2;
  nth_element(states.begin(), states.begin() + n, states.end());
  return states[n];
}

long stage1_7_test() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data7_test.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<long> states;
  while (std::getline(stream, state, ',')) {
    states.push_back(stoi(state));
  }

  long median_val = median(states);
  long fuel = 0;
  for (long i : states) {
    fuel += std::abs(i-median_val);
  }
  return fuel;
}

long stage1_7() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data7.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<long> states;
  while (std::getline(stream, state, ',')) {
    states.push_back(stoi(state));
  }

  long median_val = median(states);
  long fuel = 0;
  for (long i : states) {
    fuel += std::abs(i-median_val);
  }
  return fuel;
}

long average(std::vector<long> &states) {
  return std::accumulate(states.begin(), states.end(), 0) / states.size();
}

long stage2_7_test() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data7_test.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<long> states;
  while (std::getline(stream, state, ',')) {
    states.push_back(stoi(state));
  }

  long average_val = average(states);
  long fuel = 0;
  for (long i : states) {
    long n = std::abs(i-average_val);
    fuel += n*(n+1)/2;
  }
  return fuel;
}

long stage2_7() {
  /**
   * @brief Resolve the stage1 of 3rd December.
   *
   */

  std::ifstream infile("../data/data7.txt");

  std::string line;
  infile >> line;
  std::stringstream stream(line);

  std::string state;
  std::vector<long> states;
  while (std::getline(stream, state, ',')) {
    states.push_back(stoi(state));
  }

  long average_val = average(states);
  long fuel = 0;
  for (long i : states) {
    long n = std::abs(i-average_val);
    fuel += n*(n+1)/2;
  }
  return fuel;
}