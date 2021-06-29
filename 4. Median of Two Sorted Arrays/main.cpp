#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Naive {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr = nums1;
    arr.insert(arr.end(), nums2.begin(), nums2.end());
    if(arr.size() == 1) return arr[0];
    sort(arr.begin(), arr.end());
    size_t mid = arr.size()/2;
    if(arr.size()%2 == 0) {
      printf("(%lu, %lu)\n", mid-1, mid);
      double ans = arr[mid-1]+arr[mid];
      cout << "ans: " << ans << endl;
      return ans/2;
    }
    return arr[mid];
  }
};

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto p1 = nums1.begin(), p2 = nums2.begin();
    vector<int> merged(nums1.size()+nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
    size_t mid = merged.size()/2;
    if(merged.size()%2 == 0) {
      double ans = merged[mid-1]+merged[mid];
      return ans/2;
    }
    return merged[mid];
  }
} foo;

TEST(TestSuite, TestCase1) {
  vector<int> nums1({1,3});
  vector<int> nums2({2});
  EXPECT_EQ(foo.findMedianSortedArrays(nums1,nums2),2);
}

TEST(TestSuite, TestCase2) {
  vector<int> nums1({1,2});
  vector<int> nums2({3,4});
  EXPECT_EQ(foo.findMedianSortedArrays(nums1,nums2),2.5);
}

TEST(TestSuite, TestCase3) {
  vector<int> nums1({0,0});
  vector<int> nums2({0,0});
  EXPECT_EQ(foo.findMedianSortedArrays(nums1,nums2),0);
}

TEST(TestSuite, TestCase4) {
  vector<int> nums1({});
  vector<int> nums2({1});
  EXPECT_EQ(foo.findMedianSortedArrays(nums1,nums2),1);
}

TEST(TestSuite, TestCase5) {
  vector<int> nums1({2});
  vector<int> nums2({});
  EXPECT_EQ(foo.findMedianSortedArrays(nums1,nums2),2);
}

TEST(TestSuite, TestCase6) {
  vector<int> nums1({});
  vector<int> nums2({2,3});
  EXPECT_EQ(foo.findMedianSortedArrays(nums1,nums2),2.5);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
