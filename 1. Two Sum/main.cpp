#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
      for(int j = i+1; j < nums.size(); j++) {
        if(nums[i]+nums[j] == target) {
          return { i, j };
        }
      }
    }
    return {0, 1};
  }
};

TEST(TestSuite, TestCase1) {
  Solution foo;
  vector<int> nums = {2,7,11,15};
  int target = 9;
  EXPECT_EQ(foo.twoSum(nums, target), vector<int>({0, 1}));
}

TEST(TestSuite, TestCase2) {
  Solution foo;
  vector<int> nums = {3,2,4};
  int target = 6;
  EXPECT_EQ(foo.twoSum(nums, target), vector<int>({1,2}));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
