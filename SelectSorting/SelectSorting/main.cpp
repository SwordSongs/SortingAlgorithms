#include<iostream>
using namespace std;

void selectSorting(int a[], int len) {
	int min = 0;
	int flag = 0;

	for (int i = 0; i < len - 1; ++i) {
		min = a[i];
		flag = i;

		for (int j = i + 1; j < len; ++j) {
			if (a[j] < min) {
				min = a[j];
				flag = j;
			}
		}

		if (flag != i) {
			a[flag] = a[i];       //将后面无序数列中的最小元素与第一个元素交换
			a[i] = min;
		}

	}
}

int main() {
	int array[] = {5, 4, 9, 8, 7, 6, 0, 1, 3, 2};
	int len = sizeof(array) / sizeof(array[0]);
	selectSorting(array,len);
	
	for (auto i : array)
		cout << i << "  ";

	cout << endl;
	system("pause");
	return 0;
}