#include <iostream>
#include <vector>
using namespace std;
/*
// 树状数组
int lowbit(int pos){
    return pos&(-pos);
}
void add(int pos, int value){
    while(pos < c.size()){
        c[pos] += value;
        pos += lowbit(pos);
    }
}
int sum(int pos){
    int res = 0;
    while(pos > 0){
        res += c[pos];
        pos -= lowbit(pos);
    }
    return res;
}
*/

// 树状数组
class NumArray {
public:
    NumArray(vector<int> &nums) {
		int n = nums.size();
		BIT = vector<int>(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			add(i + 1, nums[i]);
		}
		nums_ = nums;
    }

    void update(int i, int val) {
		int diff = val - nums_[i];
		nums_[i] = val;
		add(i + 1, diff);
    }

    int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);
    }
private:
	int lowerbit(int pos)
	{
		return pos&(-pos);
	}
	void add(int pos, int val)
	{
		while (pos < BIT.size())
		{
			BIT[pos] += val;
			pos += lowerbit(pos);
		}
	}
	int sum(int pos)
	{
		int res = 0;
		while (pos > 0)
		{
			res += BIT[pos];
			pos -= lowerbit(pos);
		}
		return res;
	}
private:
	vector<int> BIT; //Binary Indexed Tree， 树状数组
	vector<int> nums_;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
int main()
{
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
	NumArray numArray(nums);
	numArray.update(2, 1);
	cout << numArray.sumRange(0, 2) << endl;
	cout << numArray.sumRange(2, 5) << endl;
	cout << numArray.sumRange(0, 5) << endl;
	return 0;
}
