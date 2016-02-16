#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : val('$'){ //'$' means the end of a word
    }
public:
	char val;
	unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			char &ch = word[i];
			if (cur->children.find(ch) == cur->children.end())
			{
				TrieNode* tmp = new TrieNode;
				tmp->val = ch;
				cur->children[ch] = tmp;
			}
			cur = cur->children[ch];
		}
		cur->children['$'] = NULL;
    }

    // Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			char &ch = word[i];
			auto it = cur->children.find(ch);
			if (it != cur->children.end())
				cur = it->second;
			else
				return false;
		}
		if (cur->children.find('$') != cur->children.end())
			return true;
		else
			return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		TrieNode* cur = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			char &ch = prefix[i];
			auto it = cur->children.find(ch);
			if (it != cur->children.end())
				cur = it->second;
			else
				return false;
		}
		return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	Trie t;
	string word = "abc";
	cout << (t.search(word) ? "Has " : "Has Not ") << word << endl;
	t.insert("abc");
	cout << (t.search(word) ? "Has " : "Has Not ") << word << endl;
	string word1 = "ab";
	cout << (t.search(word1) ? "Start with " : "No Start with ") << word1 << endl;
	t.insert(word1);
	cout << (t.search(word1) ? "Start with " : "No Start with ") << word1 << endl;
	return 0;
}