class Node {
public:
	
	int value;
	std::vector<Node*> neighbors;

	Node() {
		value = NULL;
		neighbors = {};
	}

	Node(int val, std::vector<Node*> n) {
		value = val;
		neighbors = n;
	}
	
	Node(int val) {
		value = val;
		neighbors = {};
	}

	void add_neighbors(std::unordered_map<int, Node>& nodes) {

		if (nodes.find(value + 1) != nodes.end()){
			neighbors.push_back(&nodes[value + 1]);
		}
		
	}


};

int dfs(Node& node, std::unordered_map<int, int>& counts) {

	if (counts.find(node.value) != counts.end()) {
		return counts[node.value];
	}

	if (node.neighbors.size() == 0) {
		counts[node.value] = 1;
		return counts[node.value];
	}

	else {
		counts[node.value] = 1 + dfs(*node.neighbors[0], counts);
		return counts[node.value];
	}

}



class Solution {

public:

	int longestConsecutive(std::vector<int>& nums) {

		std::unordered_map<int, Node> nodes;

		// create the graph
		for (int i = 0; i < nums.size(); i++) {
			nodes[nums[i]] = Node(nums[i]);
		}

		// instanciate neighbors
		for (int i = 0; i < nums.size(); i++) {
			nodes[nums[i]].add_neighbors(nodes);
		}

		// apply dfs for each node
		int count = 0;
		std::unordered_map<int, bool> visited;
		std::unordered_map<int, int> counts;


		for (int i = 0; i < nums.size(); i++) {
			if (visited[nums[i]]) {
				continue;
			}
			
			visited[nums[i]] = true;
			count = std::max(count, dfs(nodes[nums[i]],counts));

		}

		return count;





	}

};