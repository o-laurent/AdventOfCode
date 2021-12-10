#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

bool local_minimum(int i, int j, std::vector<std::vector<int>> &map) {
  int end_val;
  int size = map.size();
  if (i == 0 && j == 0) {
    end_val = std::min({map[i + 1][j], map[i][j + 1]});
  } else if (i == 0 && j == size - 1) {
    end_val = std::min({map[i + 1][j], map[i][j - 1]});
  } else if (i == size - 1 && j == 0) {
    end_val = std::min({map[i][j + 1], map[i - 1][j]});
  } else if (i == size - 1 && j == size - 1) {
    end_val = std::min({map[i - 1][j], map[i][j - 1]});
  } else if (i == 0) {
    end_val = std::min({map[i + 1][j], map[i][j + 1], map[i][j - 1]});
  } else if (i == size - 1) {
    end_val = std::min({map[i - 1][j], map[i][j + 1], map[i][j - 1]});
  } else if (j == 0) {
    end_val = std::min({map[i + 1][j], map[i][j + 1], map[i - 1][j]});
  } else if (j == size - 1) {
    end_val = std::min({map[i + 1][j], map[i][j - 1], map[i - 1][j]});
  } else {
    end_val =
        std::min({map[i + 1][j], map[i - 1][j], map[i][j + 1], map[i][j - 1]});
  }
  // std::cout << end_val << std::endl;
  // std::cout << map[i + 1][j] << ", " << map[i][j + 1] << std::endl;
  // std::cout << std::min({map[i + 1][j], map[i][j + 1]}) << std::endl;

  return map[i][j] < end_val;
}

int stage1_9(bool test) {
  /**
   * @brief Resolve the stage1 of 9th December.
   *
   */
  std::ifstream infile;
  if (test)
    infile.open("../data/data9_test.txt");
  else
    infile.open("../data/data9.txt");

  std::string str;
  int line = 0;
  std::vector<std::vector<int>> map;

  while (infile >> str) {
    std::vector<int> row;
    for (char const &c : str) {
      // std::cout << (int)(c - '0') << std::endl;
      row.push_back((int)(c - '0'));
    }
    // std::cout << std::endl;
    map.push_back(row);
  }

  int risk = 0;
  int size_i = map.size();
  for (int i = 0; i < size_i; i++) {
    int size_j = map[i].size();
    for (int j = 0; j < size_j; j++) {
      if (local_minimum(i, j, map)) {
        // std::cout << "i: " << i << " j: " << j << std::endl;
        risk += map[i][j] + 1;
      }
    }
  }
  return risk;
}