#include<iostream>
using namespace std;

void InsertSorting(int a[], int len) {
	int temp;
	int j;
	for (int i = 1; i < len; ++i) {      //a[0]���򣬴����1��ʼ
		temp = a[i];

		for (j = i - 1; j >= 0; --j) {
			if (temp < a[j]) {
				a[j + 1] = a[j];       //����Ԫ�غ���
			}
			else
				break;
		}

		a[j + 1] = temp;               //�ҵ�����λ�ã�����
	}
}

int main() {
	int array[] = {5, 4, 9, 8, 7, 6, 0, 1, 3, 2};
	int len = sizeof(array) / sizeof(array[0]);
	InsertSorting(array,len);

	for (auto i : array)
		cout << i << "  ";
	cout << endl;

	system("pause");
	return 0;
}