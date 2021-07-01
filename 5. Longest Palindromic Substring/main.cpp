#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    size_t n = s.length();
    if(n == 0) return "";

    // d[i][j] is true if string from i to j is a palindrome
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    // every single character is a palindrome
    for(int i = 0; i < n; i++)
      dp[i][i] = true;

    // assume the palindrome to be the first character in the string
    string ans = "";
    ans+=s[0];
    for(int i = n-1; i >=0; i--) {
      for(int j = i+1; j < n; j++) {
        if(s[i] == s[j]) {
          if(j-i==1||dp[i+1][j-1]) {
            dp[i][j]=true;
            if(ans.size()<j-i+1) ans = s.substr(i,j-i+1);
          }
        }
      }
    }

    return ans;
  }
} foo;

// cbbd
// 0. Start with empty string ans as largest
// 1. Start with the first character as the window + find the next character in the string.
// 2. Check to see if the window is a palindrome
// 3. If the window is a palindrome, check if it'ds bigger than the ans.
//   a. If it is, set ans to the window.
//   b. If it is not
TEST(TestSuite, aba) {
  EXPECT_EQ(foo.longestPalindrome("ac"), "a");
}

TEST(TestSuite, cbbd) {
  EXPECT_EQ(foo.longestPalindrome("cbbd"), "bb");
}

TEST(TestSuite, babad) {
  EXPECT_EQ(foo.longestPalindrome("babad"), "aba");
}

TEST(TestSuite, a) {
  EXPECT_EQ(foo.longestPalindrome("a"), "a");
}

TEST(TestSuite, bb) {
  EXPECT_EQ(foo.longestPalindrome("bb"), "bb");
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
