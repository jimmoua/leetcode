#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        
        // determines the length of the linked list
        auto list_size = [&head]() -> size_t {
            ListNode* node = head;
            size_t k{};
            while(node!=nullptr) { node=node->next; k++; }
            return k;
        };
        
        const size_t length = list_size();
        
        
        for(int i = 0 ; i < length-n; i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        
        if(prev == nullptr) return ptr->next;
        prev->next = ptr->next;
        
        return head;
    }
};

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
