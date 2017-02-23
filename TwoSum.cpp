#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>::size_type> twoSum(std::vector<int> &num,
                                                  int target) {
    // brute force
    for (auto b1 = num.begin(); b1 != num.end(); ++b1) {
      for (auto b2 = b1 + 1; b2 != num.end(); ++b2) {
        if (target - *b1 == *b2) {
          return {b1 - num.begin(), b2 - num.begin()};
        }
      }
    }
    return {};
  }
  std::vector<std::vector<int>::size_type> twoSum2(std::vector<int> &num,
                                                   int target) {
    // one-pass hash table
    std::map<int, int> mm;
    for (auto b = num.begin(); b != num.end(); ++b) {
      int complement = target - *b;
      if (mm.count(complement)) {
        return {mm[complement], b - num.begin()};
        std::cout << "find" << '\n';
      }
      mm.insert(std::pair<int, int>(*b, b - num.begin()));
      //      std::cout << "insert successfully" << '\n';
      //      std::cout << mm[complement] << std::endl;
    }
    return {};
  }
};

int main() {
  Solution sol;
  std::vector<int> num{2, 7, 11, 15};
  std::vector<std::vector<int>::size_type> result = sol.twoSum(num, 17);
  for (auto &v : result) {
    std::cout << v << '\n';
  }
}
