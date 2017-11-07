#include<iostream>
using namespace std;

void _swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void Bubble2Sorting(int a[], int len) {
	int left = 1;
	int right = len - 1;
	int flag;

	do {
		//���򲿷�
		for (int i = right; i >= left; --i) {
			if (a[i] < a[i - 1]) {
				_swap(a[i], a[i - 1]);
				flag = i;
			}
		}

		left = flag + 1;

		//���򲿷�
		for (int j = left; j < len; ++j) {
			if (a[j-1]>a[j]) {
				_swap(a[j-1],a[j]);
			}
			flag = j;
		}

		right = flag - 1;
	} while (left <= right);   //right���Ҳ�������ģ�left����ǰһ��λ�ÿ��Ա�֤����
}

int main() {
	int array[] = {5, 4, 9, 8, 7, 6, 0, 1, 3, 2};
	int length = sizeof(array) / sizeof(array[0]);
	Bubble2Sorting(array,length);

	for (auto i : array) {
		cout << i << "   ";
	}

	system("pause");
	return 0;
}