#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		//insertSort(nums);
		//heapSort(nums);
		//mergeSort_nonrecursion(nums);
		//mergeSort_recursion(nums);
		quickSort(nums);
	}

private:
	/* O(n^2) */
	// Insert Sort : ok
	// 思想： 将nums[i] 插入到 nums[0]~nums[i-1]中
	void insertSort(vector<int>& nums)
	{
		for (int i = 1; i < nums.size(); i++)
		{
			int tmp = nums[i];
			int j;
			for (j = i - 1; j >= 0; j--)
			{
				if (tmp < nums[j])
					nums[j + 1] = nums[j];
				else
					break;
			}

			nums[j + 1] = tmp;
		}
	}

	/* O(n*logn) */
	// heap sort : not ok
	// 思想： 花O(n)时间建最小堆，每个元素花O(logn)时间deleteMin，并存储到新数组中, 故总的时间是O(nlogn+n+n)
	// 缺点：由于要建堆,空间复杂度较大, 但是可以通过对deleteMin后空出的空间进行利用。
	#define LEFT_CHILD(i) ((2*i)+1)
	void percDown(vector<int>& nums, int i)
	{
		int tmp;
		int child, N = nums.size();
		for (tmp = nums[i]; LEFT_CHILD(i) < N; i = child)
		{
			child = LEFT_CHILD(i);
			if (child != N - 1 && nums[child + 1] >= nums[child])
				child++;
			if (tmp < nums[child])
				nums[i] = nums[child];
			else
				break;
		}
		nums[i] = tmp;
	}
	void heapSort(vector<int>& nums)
	{
		int N = nums.size();
		// build heap
		for (int i = N / 2; i >= 0; i--)
			percDown(nums, i);

		for (int i = N - 1; i > 0; i--)
		{
			swap(nums[0], nums[i]);
			percDown(nums, i);
		}
	}

	// merge sort
	// 递归实现
	void merge(vector<int>& nums, vector<int>& tmp, int left, int center, int right)
	{
		int left_min = left;
		int left_max = center;
		int right_min = center;
		int right_max = right+1;
		int next = 0;
		while (left_min < left_max && right_min < right_max)
			tmp[next++] = nums[left_min] < nums[right_min] ? nums[left_min++] : nums[right_min++];

		while (left_min < left_max)
			nums[--right_min] = nums[--left_max];

		while (next>0)
			nums[--right_min] = tmp[--next];

	}
	void msort(vector<int>& nums, vector<int>& tmp, int left, int right)
	{
		if (left < right)
		{
			int center = (left + right) / 2;
			msort(nums, tmp, left, center);
			msort(nums, tmp, center + 1, right);
			merge(nums, tmp, left, center + 1, right);
		}
	}
	void mergeSort_recursion(vector<int>& nums)
	{
		vector<int> tmp;
		tmp.resize(nums.size());
		msort(nums, tmp, 0, nums.size() - 1);
			
	}
	// 非递归是实现
	// 思想：2个2个排序，然后4个4个排序，然后8个8个排序
	void mergeSort_nonrecursion(vector<int>& a)
	{
		int left_min, left_max, right_min, right_max;
		int next;
		int length = a.size();
		vector<int> tmp;
		tmp.resize(length);

		for (int i = 1; i < length; i *= 2)
		{
			for (left_min = 0; left_min < length - i; left_min = right_max)
			{
				left_max = right_min = left_min + i;
				right_max = right_min + i;
				if (right_max > length)
					right_max = length;

				next = 0;
				while (left_min < left_max && right_min < right_max)
					tmp[next++] = a[left_min] < a[right_min] ? a[left_min++] : a[right_min++];

				while (left_min < left_max)
					a[--right_min] = a[--left_max];

				while (next>0)
					a[--right_min] = tmp[--next];
			}

		}

	}


	// quick Sort
	void quickSort(vector<int>& nums, int left, int right)
	{
		if (left < right)
		{
			int tmp = nums[left]; // 第一个数作为中枢，但是这是不科学的，见数据结构与算法分析。
			int i = left, j = right;
			while (i < j)
			{
				while (i < j && nums[j] >= tmp) //从右往左找一个小于tmp的数
					j--;
				if (i < j)
					nums[i++] = nums[j];

				while (i < j && nums[i] < tmp) //从左向右找第一个大于tmp的数
					i++;
				if (i < j)
					nums[j--] = nums[i];
			}
			nums[i] = tmp;
			quickSort(nums, left, i);
			quickSort(nums, i + 1, right);
		}
	}

	void quickSort(vector<int>& nums)
	{
		quickSort(nums, 0, nums.size()-1);
	}
};

int main()
{
	int a[] = {0,1,1,2,2,1,1,0,2,0};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	sol.sortColors(b);
	return 0;
}