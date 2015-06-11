#include <vector>
using namespace std;


vector<int> plusOne(vector<int>& digits) {
	vector<int> return_val;
	if (digits.size() < 1)
		return digits;


	int i = digits.size() - 1;
	digits[i] += 1;
	while (digits[i] >= 10 && i > 0)
	{
		digits[i] -= 10;
		digits[i - 1] += 1;
		i--;
	}

	if (digits[0] >= 10)
	{
		digits[0] -= 10;
		return_val.resize(digits.size() + 1);
		for (int i = 1; i < digits.size() + 1; i++)
		{
			return_val[i] = digits[i - 1];
		}
		return_val[0] = 1;
		return return_val;
	}
	else
		return digits;


}


int main(int argc, char** argv)
{
	vector<int> a, b;
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);
	b = plusOne(a);
	return 0;
}