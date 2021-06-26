#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
  public:
    vector<string> letterCombinations(std::string digits) {
      map<int, vector<string>> comb = {
        { 2, {"a", "b", "c"} },
        { 3, {"d", "e", "f"} },
        { 4, {"g", "h", "i"} },
        { 5, {"j", "k", "l"} },
        { 6, {"m", "n", "o"} },
        { 7, {"p", "q", "r", "s"} },
        { 8, {"t", "u", "v"} },
        { 9, {"w", "x", "y", "z"} }
      };

      if(digits.size() == 0) {
        return {};
      }
      if(digits.size() == 1) {
        return comb[stoi(digits)];
      }

      vector<int> digitsVector; // vector of digits casted to int
      for(const auto& i : digits) {
        digitsVector.push_back(static_cast<int>(i)-48);
      }

      // Grab all the sets depending on digit
      vector<vector<string>> sets;
      for(const auto& digit : digitsVector) {
        sets.push_back(comb[digit]);
      }

      // lambda to multiple two sets and return a new set based on multiplicatioln
      auto multiply = [&](vector<string> set1, vector<string> set2) -> vector<string> {
        vector<string> product;
        for(const auto& letter : set1) {
          for(const auto& letter2 : set2) {
            product.push_back(letter+letter2);
          }
        }
        return product;
      };

      vector<string> ans = sets[0];
      // Multiple each element in the sets
      for(size_t i = 1; i < sets.size(); i++) {
        ans = multiply(ans, sets[i]);
      }

      return ans;
    }     
};

TEST(LetterCombination, TwoDigits) {
  Solution foo;
  vector<string> ans = foo.letterCombinations("23");
  vector<string> expected_answer { "ad","ae","af","bd","be","bf","cd","ce","cf" };
  EXPECT_EQ(ans, expected_answer);
}

TEST(LetterCombination, NoDigits) {
  Solution foo;
  vector<string> ans = foo.letterCombinations("");
  vector<string> expected_answer {};
  EXPECT_EQ(ans, expected_answer);
}

TEST(LetterCombination, SingleDigit) {
  Solution foo;
  vector<string> ans = foo.letterCombinations("2");
  vector<string> expected_answer { "a", "b", "c" };
  EXPECT_EQ(ans, expected_answer);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

