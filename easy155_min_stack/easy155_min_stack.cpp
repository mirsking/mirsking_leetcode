#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
		stack_.push(x);

		if (stackMin.empty() || x < stackMin.top())
			stackMin.push(x);
		else
			stackMin.push(stackMin.top());
    }

    void pop() {
		stack_.pop();
		stackMin.pop();
    }

    int top() {
		return stack_.top();
    }

    int getMin() {
		return stackMin.top();
    }

private:
	stack<int> stack_;
	stack<int> stackMin;
};

int main()
{
	MinStack sol;
	sol.push(1);
	sol.push(2);
	cout << sol.getMin()<<endl;
	cout << sol.top()<<endl;
	sol.pop();
	//sol.pop();
	//cout << sol.getMin()<<endl;
	sol.push(2);
	cout << sol.top() << endl;
	

	return 0;
}
