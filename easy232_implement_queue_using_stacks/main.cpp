#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
		sta.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
		stack<int> tmp;
		while (!sta.empty())
		{
			tmp.push(sta.top());
			sta.pop();
		}
		tmp.pop();
		while (!tmp.empty())
		{
			sta.push(tmp.top());
			tmp.pop();
		}
    }

    // Get the front element.
    int peek(void) {
		stack<int> tmp = sta;
		int val = 0;
		while (!tmp.empty())
		{
			val = tmp.top();
			tmp.pop();
		}
		return val;
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return sta.empty();
    }
private:
	stack<int> sta;
};

int main()
{
	Queue que;
	que.push(1);
	que.push(2);
	que.push(3);
	cout << que.peek() << endl;
	que.pop();
	cout << que.peek() << endl;
	return 0;
}