#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    set<int> seen;

    for(const auto& d : nums) seen.insert(d);

    int j = 0;
    for(const auto& d : seen) {
      nums[j++] = d;
    }

    return seen.size();
  }
} foo;

TEST(TestSuite, TestCase) {
  vector<int> arr            {1,1,1,2,2,2,3,4,5,6,6,7,8,8,9};
  int k = foo.removeDuplicates(arr);
  EXPECT_EQ(arr, vector<int>({1,2,3,4,5,6,7,8,9,6,6,7,8,8,9}));
  EXPECT_EQ(k, 9);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
