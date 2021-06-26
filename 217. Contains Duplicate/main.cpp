#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    cout << endl;
    int foo = nums[0];
    for(size_t i = 1; i < nums.size(); i++) {
      if(nums[i] == foo) {
        return true;
      }
      foo = nums[i];
    }
    return false;
  }
};

TEST(TestSuite, TestCase1) {
  Solution foo;
  vector<int> nums {1,2,3,4};
  EXPECT_EQ(foo.containsDuplicate(nums), false);
}
TEST(TestSuite, TestCase2) {
  Solution foo;
  vector<int> nums {1,1,1,3,3,4,3,2,4,2};
  EXPECT_EQ(foo.containsDuplicate(nums), true);
}
TEST(TestSuite, TestCase3) {
  Solution foo;
  vector<int> nums {1,2,3,1};
  EXPECT_EQ(foo.containsDuplicate(nums), true);
}

TEST(TestSuite, TestCase4) {
  Solution foo;
  vector<int> nums{2,14,18,22,22};
  EXPECT_EQ(foo.containsDuplicate(nums), true);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
