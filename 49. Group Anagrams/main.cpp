#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<array<int, 26>, vector<string>> mp;
    for(const auto& s : strs) {
      array<int, 26> a{};
      for(const auto& c : s) {
        a[c-'a']++;
      }
      mp[a].push_back(s);
    }
    vector<vector<string>> ans;
    for(const auto& p : mp) {
      ans.push_back(p.second);
    }
    return ans;
  };
} foo;

TEST(TestSuite, TestCase) {
  vector<string> s = {"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>> group = {
    {
      {"tan","nat"},
      {"eat","tea","ate"},
      {"bat"}
   }
  };
  EXPECT_EQ(foo.groupAnagrams(s), group);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

