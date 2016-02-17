#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
		que.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
		que.pop_back();
    }

    // Get the top element.
    int top() {
		return que.back();
    }

    // Return whether the stack is empty.
    bool empty() {
		return que.empty();
    }
private:
	deque<int> que;
};

int main()
{
	Stack sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	cout << sta.top() << endl;
	sta.pop();
	cout << sta.top() << endl;
	return 0;
}