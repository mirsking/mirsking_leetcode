#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode{
public:
	TrieNode(char ch='$') : val(ch)
	{}
public:
	char val;
	unordered_map<char, TrieNode*> children;
};

class Trie{
public:
	Trie()
	{
		root = new TrieNode;
	}

	void addWord(string& word)
	{
		TrieNode *cur = root;
		for (auto& ch : word)
		{
			if (cur->children.find(ch) == cur->children.end())
			{
				cur->children[ch] = new TrieNode(ch);
			}
			cur = cur->children[ch];
		}
		cur->children['$'] = new TrieNode;
	}

	bool search(string& word)
	{
		TrieNode *cur = root;
		return search(word, 0, cur);
	}
private:
	bool search(string& word, int start, TrieNode* cur)
	{
		int n = word.size();
		if (start >= n)
			return cur->children.find('$') != cur->children.end();

		bool res = false;
		char& ch = word[start];
		if (ch == '.')
		{
			for (auto& child : cur->children)
			{
				res |= search(word, start + 1, child.second);
			}
			return res ;
		}
		else
		{
			if (cur->children.find(ch) != cur->children.end())
				return search(word, start + 1, cur->children[ch]);
			else
				return false;
		}
	}

private:
	TrieNode* root;
};


class WordDictionary {
public:
	WordDictionary()
	{
		trie = new Trie;
	}

    // Adds a word into the data structure.
    void addWord(string word) {
		trie->addWord(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		return trie->search(word);
    }

private:
	Trie* trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
	WordDictionary wd;
	wd.addWord("a");
	string word = "a";
	cout << (wd.search(word) ? "Find " : "Cannot find ") << word << endl;
	word = ".a";
	cout << (wd.search(word) ? "Find " : "Cannot find ") << word << endl;
	word = "a.";
	cout << (wd.search(word) ? "Find " : "Cannot find ") << word << endl;
	return 0;
}