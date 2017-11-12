#include<iostream>
using namespace std;

void shellSorting(int a[],int len) {
	int temp;
	int i, j;
	for (int step = len / 2; step > 0;step /= 2) {
		for (i = step; i < len; ++i) {        //�ҵ�����Ԫ��
			temp = a[i];
			j = i - step;             //��ʼԪ��
			if (a[j] > a[i]) {        //������˳�򣬽���
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main() {
	int array[] = {8, 5, 4, 9, 7, 6, 0, 1, 3, 2};
	int len = sizeof(array) / sizeof(array[0]);

	shellSorting(array,len);

	for (auto i : array)
		cout << i << "  ";

	system("pause");
	return 0;
}