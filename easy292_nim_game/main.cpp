#include <iostream>
#include <vector>
using namespace std;
//http://bookshadow.com/weblog/2015/10/12/leetcode-nim-game/
//��n��[1,3]ʱ�����ֱ�ʤ��
//��n == 4ʱ���������ֵ�һ�����ѡȡ����һ�ֶ���ת��Ϊn��[1,3]�����Σ���ʱ���ֱظ���
//��n��[5,7]ʱ�����ֱ�ʤ�����ֱַ�ͨ��ȡ��[1,3]��ʯͷ���ɽ�״̬ת��Ϊn == 4ʱ�����Σ���ʱ���ֱظ���
//��n == 8ʱ���������ֵ�һ�����ѡȡ����һ�ֶ���ת��Ϊn��[5,7]�����Σ���ʱ���ֱظ���
//So
//��n % 4 != 0ʱ�����ֱ�ʤ���������ֱظ���


class Solution {
public:
    bool canWinNim(int n) {
		if (n % 4 != 0)
			return true;
		else
			return false;
    }
};

int main()
{
	return 0;
}