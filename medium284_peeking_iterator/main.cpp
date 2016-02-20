#include <iostream>
#include <vector>
using namespace std;
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!hasPeeked)
		{
			hasPeeked = true;
			return cache = Iterator::next();
		}
		else
			return cache;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (!hasPeeked)
			return Iterator::next();
		else
		{
			hasPeeked = false;
			return cache;
		}
	}

	bool hasNext() const {
		if (hasPeeked)
			return true;
		else
			return Iterator::hasNext();
	}
private:
	int cache;
	bool hasPeeked;
};

int main()
{
	return 0;
}