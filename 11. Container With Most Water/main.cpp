#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class BruteForce {
public:
  int maxArea(vector<int>& height) {
    int max = 0;
    for(int i = 0; i < height.size(); i++) {
      int area = 0;
      for(int j = i+1; j < height.size(); j++) {
        if(height[i] > height[j]) {
          area = height[j] * (j-i);
        } else {
          area = height[i] * (j-i);
        }
        max = std::max(area, max);
      }
    }
    return max;
  }
};

class Solution {
public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size()-1;
    int max_area = 0;
    while(l < r) {
      int lh = height[l];
      int rh = height[r];
      int height = min(lh, rh); // container will only fill up to the lowest height without overflowing
      int width = (r-l);
      max_area = std::max(max_area, width*height);
      if(lh < rh) l++;
      else r--;
    }
    return max_area;
  }
} foo;

TEST(TestSuite, TestCase1) {
  vector<int> arr = {1,8,6,2,5,4,8,3,7};
  EXPECT_EQ(foo.maxArea(arr), 49);
}

TEST(TestSuite, TestCase2) {
  vector<int> arr = {1,1};
  EXPECT_EQ(foo.maxArea(arr), 1);
}

TEST(TestSuite, TestCase3) {
  vector<int> arr = {1,2,1};
  EXPECT_EQ(foo.maxArea(arr), 2);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
