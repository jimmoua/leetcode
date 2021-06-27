#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if(s.length() == 1 || s.length() == 0) return s.length();

    // Sliding window approach
    unordered_map<char, int> mp;
    size_t l=0;
    string window, longest("");
    for(int i = 0; i < s.length(); i++) {
      window.push_back(s[i]);
      mp[s[i]]++;
      if(mp[s[i]] > 1) {
        l = s.find_last_of(s[i], i-1)+1;
        size_t p = window.find(s[i]);
        string ll = window.substr( p+1 );
        window.clear(); mp.clear();
        window = ll;
        for(const auto& d : window) mp[d]++;
      } else {
        if(window.length() > longest.length()) longest = window;
      }
    }
    return (int)longest.length();
  };
};

TEST(TestSuite, abcabcbb) {
  Solution foo;
  string s = "abcabcbb";
  EXPECT_EQ(foo.lengthOfLongestSubstring(s), 3);
}

TEST(TestSuite, pwwkew) {
  Solution foo;
  string s = "pwwkew";
  EXPECT_EQ(foo.lengthOfLongestSubstring(s), 3);
}

TEST(TestSuite, au) {
  Solution foo;
  string s = "au";
  EXPECT_EQ(foo.lengthOfLongestSubstring(s), 2);
}

TEST(TestSuite, aab) {
  Solution foo;
  string s = "aab";
  EXPECT_EQ(foo.lengthOfLongestSubstring(s), 2);
}

TEST(TestSuite, dvdf) {
  Solution foo;
  string s = "dvdf";
  EXPECT_EQ(foo.lengthOfLongestSubstring(s), 3);
}

TEST(TestSuite, vdf) {
  Solution foo;
  string s = "vdf";
  EXPECT_EQ(foo.lengthOfLongestSubstring(s), 3);
}

TEST(TestSuite, asdfasdf) {
  Solution foo;
  EXPECT_EQ(foo.lengthOfLongestSubstring(string("asdfasdf")), 4);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
