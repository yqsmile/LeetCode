#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::map;
using std::pair;
using std::endl;

class solution {
public:
  typedef pair<char, int> PAIR;
  static bool cmpvec(const PAIR &x, const PAIR &y) {
    return x.second < y.second;
  }

  int lengthOfLongestSubstring(string s) {
    map<char, int> mm;
    vector<PAIR> mapVec;
    for (int j = 0; j < s.length(); ++j) {
      for (int i = j; i < s.length(); ++i) {
        if (!mm.count(s[i])) {
          mm.insert(pair<char, int>(s[i], i));
        } else {
          j = mm[s[i]];
          if (mapVec.size() < mm.size()) {
            mapVec.clear();
            for (auto b = mm.begin(); b != mm.end(); ++b) {
              mapVec.push_back(PAIR(b->first, b->second));
            }
            sort(mapVec.begin(), mapVec.end(), cmpvec);
          }
          mm.clear();
          if (i == s.length() - 1)
            j = i;
          break;
        }
      }
    }

    for (auto b = mapVec.begin(); b != mapVec.end(); ++b) {
      cout << (*b).first;
    }
    cout << endl;
    return 0;
  }
};

int main() {
  string s = "";
  cin >> s;
  solution sol;
  sol.lengthOfLongestSubstring(s);
}
