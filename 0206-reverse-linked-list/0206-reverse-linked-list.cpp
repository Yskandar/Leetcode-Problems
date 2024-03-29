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

		
		ListNode* prev = NULL;
        ListNode* following = NULL;
        
		while (head != nullptr) {
            std::cout<<head->val<<endl;
			following = head->next;
            head->next = prev;
			prev = head;
			head = following;
		}
        
		return prev;
        


    }


};