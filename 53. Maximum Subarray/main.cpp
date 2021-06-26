#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int curr = 0;
    int maxSub = nums[0];
    for(int i = 0; i < nums.size(); i++) {
      if(curr < 0) curr = 0; // if window results in negative, discard the current window and start anew window
      curr+=nums[i];
      maxSub = max(curr, maxSub);
    }
    return maxSub;
  }
};

TEST(TestSuite, TestCase1) {
  Solution foo;
  vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
  EXPECT_EQ(foo.maxSubArray(nums), 6);
}

TEST(TestSuite, TestCase2) {
  Solution foo;
  vector<int> nums {1};
  EXPECT_EQ(foo.maxSubArray(nums), 1);
}

TEST(TestSuite, TestCase3) {
  Solution foo;
  vector<int> nums {5,4,-1,7,8};
  EXPECT_EQ(foo.maxSubArray(nums), 23);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
