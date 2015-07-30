#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return node;
		if (copied_.find(node) != copied_.end())
			return copied_[node];

		UndirectedGraphNode* res_node = new UndirectedGraphNode(node->label);
		copied_[node] = res_node;
		for (auto& neighbor : node->neighbors)
		{
			res_node->neighbors.push_back(cloneGraph(neighbor));
		}
		return res_node;

    }
private:
	unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> copied_;
};

int main()
{
	UndirectedGraphNode a(0), b(1), c(2);
	a.neighbors.push_back(&b); a.neighbors.push_back(&c);
	b.neighbors.push_back(&c);
	c.neighbors.push_back(&c);

	Solution sol;
	UndirectedGraphNode* res = sol.cloneGraph(&a);
	return 0;
}