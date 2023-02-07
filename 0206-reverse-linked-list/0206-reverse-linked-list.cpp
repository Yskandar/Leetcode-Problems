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
    ListNode* reverseList(ListNode* head) {

		
		ListNode* curr = head;
		ListNode* prev = nullptr;
        ListNode* following;
        
		while (curr != nullptr) {
            std::cout<<curr->val<<endl;
			following = curr->next;
            curr->next = prev;
			prev = curr;
			curr = following;
		}
        
		return prev;
        


    }


};