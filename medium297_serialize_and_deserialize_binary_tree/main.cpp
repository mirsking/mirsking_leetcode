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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		vector<string> res_vec;
		IndexTravesal(root, 0, res_vec);
		string res;
		for (int i = 0; i < res_vec.size(); i++)
		{
			if (res_vec[i] != "")
				res += res_vec[i];
			else
				res += "null";
			if (i + 1 != res_vec.size())
				res += " ";
		}
		return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		vector<string> nodes;
		str2Vector(data, nodes);
		return deserialize(nodes, 0);
    }

private:
	void IndexTravesal(TreeNode* root, int id, vector<string>& res)
	{
		if (!root)
			return;
		if (id >= res.size())
			res.resize(id + 1);
		res[id] = to_string(root->val);
		IndexTravesal(root->left, 2*id + 1, res);
		IndexTravesal(root->right, 2*id + 2, res);
	}
	TreeNode* deserialize(vector<string>& nodes, int id)
	{
		if (id >= nodes.size() || nodes[id] == "null")
			return NULL;

		int val = stoi(nodes[id]);
		TreeNode* root = new TreeNode(val);
		root->left = deserialize(nodes, id * 2 + 1);
		root->right = deserialize(nodes, id * 2 + 2);
		return root;
	}
	void str2Vector(string& str, vector<string>& res)
	{
		stringstream ss(str);
		while (ss)
		{
			string tmp;
			ss >> tmp;
			if (tmp != "")
				res.push_back(tmp);
		}
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
	string res = cod.serialize(NULL);
	TreeNode* res1 = cod.deserialize(res);
	return 0;
}