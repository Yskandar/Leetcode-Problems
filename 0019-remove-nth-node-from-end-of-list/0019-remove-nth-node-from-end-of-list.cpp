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
        
        deque<ListNode*> window = {head};
        
        
        while (window.size() < n){
            window.push_back(window.back()->next);
        }
        
        if (window.back()->next == nullptr){
            
            if (window.size()>=2) {return window[1];}              
            else{
                return nullptr;
            }
                
        }
        
        window.push_back(window.back()->next);
        while (window.back()->next != nullptr){
            window.pop_front();
            window.push_back(window.back()->next);
        }
        
        if (window.size()>=3){
            window[0]->next = window[2];
        }
        else{
            window[0]->next = nullptr;
        }
        
        return head;
    }
};