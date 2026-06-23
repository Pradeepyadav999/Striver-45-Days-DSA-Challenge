#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(auto head:lists){
            while(head) {
                arr.push_back(head->val);
                head = head->next;
            }
        }
        sort(arr.begin(),arr.end());
        if(arr.empty()) return NULL;

        ListNode* head=new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i=1;i<arr.size();i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    }
};

int main() {
    Solution sol;
    vector<ListNode*> lists;
    // Create some linked lists and add them to 'lists'
    // For example:
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);
    
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    
    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);
    
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode* mergedHead = sol.mergeKLists(lists);
    
    // Print the merged linked list
    while (mergedHead) {
        cout << mergedHead->val << " ";
        mergedHead = mergedHead->next;
    }
    
    return 0;
}