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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        if (list1 == nullptr){return list2;}
        if (list2 == nullptr){return list1;}
        
        if (list1->val <= list2->val){
            recurse_down(list1, list2);
            return list1;
            
        }
        
        else{
            recurse_down(list2, list1);
            return list2;
        }
        
        
        
        
        
    }
    
    
    void recurse_down(ListNode* list1, ListNode* list2){
        
        
        if (list1->next == nullptr){list1->next = list2;
                                    return;}
        
        if (list1->next->val <= list2->val){
            recurse_down(list1->next, list2);
        }
        else{
            //ListNode* temp = new ListNode;
            ListNode* temp = list1->next;
            list1->next = list2;
            recurse_down(list2, temp);
            
            
        }
    }
    
};