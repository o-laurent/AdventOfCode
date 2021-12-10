#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

long median2(std::vector<long> &states) {
  long n = states.size() / 2;
  nth_element(states.begin(), states.begin() + n, states.end());
  return states[n];
}

int points(char c) {
  int res = -1;
  if (c == ')')
    res = 3;
  else if (c == ']')
    res = 57;
  else if (c == '}')
    res = 1197;
  else if (c == '>')
    res = 25137;
  return res;
}

char opposite(char c) {
  char res = ' ';
  if (c == ')')
    res = '(';
  else if (c == ']')
    res = '[';
  else if (c == '}')
    res = '{';
  else if (c == '>')
    res = '<';
  return res;
}

unsigned long int score(char c) {
  unsigned long int res = 0;
  if (c == '(')
    res = 1;
  else if (c == '[')
    res = 2;
  else if (c == '{')
    res = 3;
  else if (c == '<')
    res = 4;
  return res;
}



int stage1_10(bool test) {
  /**
   * @brief Resolve the stage1 of 10th December.
   *
   */
  std::ifstream infile;
  if (test)
    infile.open("../data/data10_test.txt");
  else
    infile.open("../data/data10.txt");

  std::string str;
  int line = 0;
  std::vector<std::stack<char>> map;

  std::string openings = "([{<";
  int loss = 0;
  while (infile >> str) {
    std::stack<char> stack;
    bool ok = true;
    // std::cout << std::endl;

    for (char const &c : str) {
      // std::cout << (int)(c - '0') << std::endl;
      if (ok) {
        // std::cout << c;
        if (openings.find(c) != std::string::npos)
          stack.push(c);
        else {
          if (!stack.empty()) {
            char val = stack.top();
            stack.pop();
            if (val != opposite(c)) {
              ok = false;
              loss += points(c);
              // std::cout << " - erreur - " << opposite(c) << " vs. " << val;
            }
          } else {
            // std::cout << c;
            ok = false;
            loss += points(c);
          }
        }
      }
    }
  }

  return loss;
}

long stage2_10(bool test) {
  /**
   * @brief Resolve the stage1 of 10th December.
   *
   */
  std::ifstream infile;
  if (test)
    infile.open("../data/data10_test.txt");
  else
    infile.open("../data/data10.txt");

  std::string str;
  int line = 0;
  std::vector<std::stack<char>> map;
  std::vector<long> scores;
  std::string openings = "([{<";
  while (infile >> str) {
    std::stack<char> stack;
    bool ok = true;
    // std::cout << std::endl;

    for (char const &c : str) {
      // std::cout << (int)(c - '0') << std::endl;
      if (ok) {
        // std::cout << c;
        if (openings.find(c) != std::string::npos)
          stack.push(c);
        else {
          if (!stack.empty()) {
            char val = stack.top();
            stack.pop();
            if (val != opposite(c)) {
              ok = false;
              // std::cout << " - erreur - " << opposite(c) << " vs. " << val;
            }
          } else {
            // std::cout << c;
            ok = false;
          }
        }
      }
    }
    if (ok) {
      unsigned long int c_score = 0;
      while (!stack.empty()) {
        c_score = c_score*5+score(stack.top());
        stack.pop();
      }
      scores.push_back(c_score);
      // std::cout << c_score << std::endl;
    }

  }

  return median2(scores);
}