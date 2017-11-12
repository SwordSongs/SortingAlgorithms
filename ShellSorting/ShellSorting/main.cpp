#include<iostream>
using namespace std;

void shellSorting(int a[],int len) {
	int temp;
	int i, j;
	for (int step = len / 2; step > 0;step /= 2) {
		for (i = step; i < len; ++i) {        //找到步长元素
			temp = a[i];
			j = i - step;             //初始元素
			if (a[j] > a[i]) {        //不满足顺序，交换
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