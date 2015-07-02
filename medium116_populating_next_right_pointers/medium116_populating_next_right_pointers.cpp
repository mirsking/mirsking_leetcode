#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		queue<TreeLinkNode*> que;
		que.push(root);
		levelConnect(que);
    }
private:
	void levelConnect(queue<TreeLinkNode*> que)
	{
		if (que.empty())
			return;

		queue<TreeLinkNode*> next_level_que;

		TreeLinkNode* node1 = que.front();
		que.pop();
		if (node1->left!=NULL)
			next_level_que.push(node1->left);
		if (node1->right!=NULL)
			next_level_que.push(node1->right);

		TreeLinkNode* node2;
		while (!que.empty())
		{
			node2 = que.front();
			que.pop();
			if (node2->left!=NULL)
				next_level_que.push(node2->left);
			if (node2->right!=NULL)
				next_level_que.push(node2->right);
			node1->next = node2;
			node1 = node2;
		}
		node1->next = NULL;
		levelConnect(next_level_que);
	}
	
};
int main()
{
	TreeLinkNode a(-1), b(0), c(1), d(2), e(3), f(4), g(5), h(6), i(7), j(8), k(9), l(10), m(11), n(12), o(13);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f; c.right = &g;
	d.left = &h; d.right = &i;
	e.left = &j; e.right = &k;
	f.left = &l; f.right = &m;
	g.left = &n; g.right = &o;
	Solution sol;
	sol.connect(&a);
	return 0;
}