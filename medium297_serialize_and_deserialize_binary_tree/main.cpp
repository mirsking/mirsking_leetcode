#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
	//http://www.cnblogs.com/grandyang/p/4913869.html
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		stringstream ss;
		serialize(root, ss);
		return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		stringstream ss(data);
		return deserialize(ss);
    }

private:
	//preorder
	void serialize(TreeNode* root, stringstream& ss)
	{
		if (root)
		{
			ss << root->val << ' ';
			serialize(root->left, ss);
			serialize(root->right, ss);
		}
		else
		{
			ss << "# ";
		}
	}

	TreeNode* deserialize(stringstream& ss)
	{
		string val;
		ss >> val;
		if (val == "#")
			return NULL;
		TreeNode *root = new TreeNode(stoi(val));
		root->left = deserialize(ss);
		root->right = deserialize(ss);
		return root;
	}

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
	TreeNode a(1), b(2), c(3), d(4), e(5);
	a.left = &b; a.right = &c; c.left = &d;// c.right = &e;
	Codec cod;
	string res = cod.serialize(&a);
	TreeNode* res1 = cod.deserialize(res);
	return 0;
}