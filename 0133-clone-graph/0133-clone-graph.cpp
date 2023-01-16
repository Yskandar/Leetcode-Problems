/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:

    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
            return NULL;

        std::unordered_map<int, Node*> node_map;
        std::vector<Node*> queue = {node};
        std::vector<Node*> visited = {};
        

        while (queue.size() != 0) {
            
            Node* curr = queue[0];
            
            
            if (node_map.find(curr->val) == node_map.end()) {
                visited.push_back(curr);
                Node* copy_node = new Node(curr->val);
                node_map[curr->val] = copy_node;
                std::vector<Node*> curr_neighbors = curr->neighbors;
                for (auto orig_node : curr_neighbors) {
                    queue.push_back(orig_node);
                }
            }
            
            queue.erase(queue.begin());

        }

        // Second round

        for (auto curr : visited) {

            std::vector<Node*> curr_neighbors = curr->neighbors;

            for (auto neighbor_node : curr_neighbors) {
                node_map[curr->val]->neighbors.push_back(node_map[neighbor_node->val]);
            }
        }

        
        return node_map[node->val];

    }



};