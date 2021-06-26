#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int max = 0;
    int low = prices[0];
    for(int i = 0; i < prices.size(); i++) {
      if(prices[i] < low) {
        low = prices[i];
      }
      if(max < prices[i] - low) {
        max = prices[i] - low;
      }
    }
    return max;
  }
};

TEST(TestSuite, TestCase1) {
  Solution foo;
  vector<int> prices = {7,6,4,3,1};
  EXPECT_EQ(foo.maxProfit(prices), 0);
}

TEST(TestSuite, TestCase2) {
  Solution foo;
  vector<int> prices = {7,1,5,3,6,4};
  EXPECT_EQ(foo.maxProfit(prices), 5);
}

TEST(TestSuite, TestCase3) {
  Solution foo;
  vector<int> prices = {1};
  EXPECT_EQ(foo.maxProfit(prices), 0);
}

TEST(TestSuite, TestCase4) {
  Solution foo;
  vector<int> prices = {1, 2};
  EXPECT_EQ(foo.maxProfit(prices), 1);
}

TEST(TestSuite, TestCase6) {
  Solution foo;
  vector<int> prices = {2,4,1};
  EXPECT_EQ(foo.maxProfit(prices), 2);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
