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

int bassin(int i, int j, std::vector<std::vector<int>> &map) {
  /**
   * @brief Compute the size of the bassin corresponding to a local minimum.
   *
   */
  // std::cout << i << ", " << j << ", " << std::endl;
  map[i][j] = -1;
  int isize = map.size();
  int jsize = map[0].size();
  int score = 1;

  if (i != 0) {
    int val = map[i - 1][j];
    if (val != -1 && val != 9) {
      score += bassin(i - 1, j, map);
    }
  }
  if (i != isize - 1) {
    int val = map[i + 1][j];
    if (val != -1 && val != 9) {
      score += bassin(i + 1, j, map);
    }
  }
  if (j != 0) {
    int val = map[i][j - 1];
    if (val != -1 && val != 9) {
      score += bassin(i, j - 1, map);
    }
  }
  if (j != jsize - 1) {
    int val = map[i][j + 1];
    if (val != -1 && val != 9) {
      score += bassin(i, j + 1, map);
    }
  }

  return score;
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

int stage2_9(bool test) {
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

  std::vector<int> bassin_size;
  int risk = 0;
  int size_i = map.size();
  for (int i = 0; i < size_i; i++) {
    int size_j = map[i].size();
    for (int j = 0; j < size_j; j++) {
      if (local_minimum(i, j, map)) {
        // std::cout << "i: " << i << " j: " << j << std::endl;
        bassin_size.push_back(bassin(i, j, map));
      }
    }
  }
  std::vector<int> dest(3); // largest n numbers; VLA or std::dynarray in C++14
  std::partial_sort_copy(std::begin(bassin_size),
                         std::end(bassin_size), //.begin/.end in C++98/C++03
                         std::begin(dest), std::end(dest),
                         std::greater<int>() // remove "int" in C++14
  );

  return std::accumulate(dest.begin(), dest.end(), 1, std::multiplies<int>());
}