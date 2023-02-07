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

	ListNode* middleNode(ListNode* head) {


		int count = 1;
		std::unordered_map<int, ListNode*> nodes;
		parcour_list(head, nodes, count);

        return nodes[(int)(count / 2) + 1];
		//if (count % 2 == 0) { return nodes[(int)(count / 2) + 1]; }
		//else { 
            
        //    std::cout<< "middle is " << (int)(count/2) << std::endl;
        //    return nodes[(int)(count / 2)]; }


	}

	void parcour_list(ListNode* node, std::unordered_map<int, ListNode*>& nodes, int& count) {

		if (node->next == nullptr) {
			nodes[count] = node;
            std::cout << "done, count = " << count << std::endl;
			return;
		}

		else {
			nodes[count] = node;
			count += 1;
			return parcour_list(node->next, nodes, count);

		}
		

	};


};