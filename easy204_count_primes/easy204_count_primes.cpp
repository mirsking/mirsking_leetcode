#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
		int count = 0;
		for (int i = 2; i < n; i++)
		{
			if (isPrime(primers, i))
				count++;
		}
		return count;
    }

	Solution()
	{
		makePrimers();
	}

private:
	bool isPrime(vector<int>& primers, int n)
	{
		if (n < 2)
			return false;
		for (int i = 0; primers[i] <= sqrt(n); i++)
		{
			if (n%primers[i] == 0)
				return false;
		}
		return true;
	}



	bool isPrime(int n)
	{
		if (n == 1)
			return false;
		if (n == 2)
			return true;
		if (n % 2 == 0)
			return false;

		for (int i = 3; i <= sqrt(n); i+=2)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}

	void makePrimers()
	{
		for (int i = 0; i < sqrt(pow(2, 31)); i++)
		{
			if (isPrime(i))
				primers.push_back(i);
		}
	}


	vector<int> primers;
};


int main(int argc, char** argv)
{

	Solution sol;
	cout << sol.countPrimes(1500000);
	//for (int i = 2; i < pow(2, 15) - 1; i++)
	//{
	//	if (sol.isPrime(i))
	//		cout << i << ", ";
	//}

	return 0;
}