#include<iostream>
using namespace std;

void _swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void BubbleSorting(int* a, int len){
	int i, j;
	for (i = 0; i < len - 1; ++i) {                        //算法核心从后向前冒泡，前边的元素有序
		for (j = len - 1; j > i; --j) {
			if (a[j] < a[j - 1]) {
				_swap(a[j], a[j - 1]);
			}
		}
	}
}

int main() {
	int array[] = {36, 25, 48, 12, 25, 65, 43, 57};
	int length = sizeof(array) / sizeof(array[0]);
	BubbleSorting(array, length);
	for (auto i : array) {
		cout << i << "  ";
	}
	system("pause");
	return 0;
}