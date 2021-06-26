#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);

    // The previous is the all the seen elements multiplied by each other.
    int prev = 1;
    for(int i = 0; i < nums.size(); i++) {
      ans[i]*=prev;
      prev*=nums[i];
    }

    // Reset the previous and iterate through other direction.
    prev = 1;
    for(int i = nums.size()-1; i >= 0; i--) {
      ans[i]*=prev;
      prev*=nums[i];
    }
    return ans;
  }
};

TEST(TestSuite, TestCase1) {
  Solution foo;
  vector<int> ans {-1,1,0,-3,3}, expectedAns {0,0,9,0,0};
  EXPECT_EQ(foo.productExceptSelf(ans), expectedAns);
}

TEST(TestSuite, TestCase2) {
  Solution foo;
  vector<int> ans {1,2,3,4}, expectedAns {24,12,8,6};
  EXPECT_EQ(foo.productExceptSelf(ans), expectedAns);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
