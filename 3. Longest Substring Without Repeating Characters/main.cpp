#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    array<char, 256> arr{0};
    int rp=0, lp=0;
    int ans=0;
    while(rp < s.length()) {
      arr[s[rp]]++;
      while(arr[s[rp]] > 1) {
        arr[s[lp]]--;
        lp++;
      }
      ans = max(ans, rp-lp+1);
      rp++;
    }
    return ans;
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
