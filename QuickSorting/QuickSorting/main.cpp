#include<iostream>
using namespace std;

void SortCore(int a[], int low, int high) {
	int pivot;
	if (low >= high)          //递归结束
		return;

	int i = low;
	int j = high;
	pivot = a[i];            //选取第一个元素作为枢轴元素

	while (i < j) {
		while (i < j && a[j] >= pivot)	--j;
		
		if (i < j)
			a[i++] = a[j];     //找到后端小于枢轴的元素置换到前端

		while (i < j && a[i] < pivot)	++i;

		if (i < j)
			a[j--] = a[i];    //找到前端大于枢轴的元素置换到后端

	}

	a[i] = pivot;            //i与j相遇，放置枢轴
	SortCore(a, low, i - 1);
	SortCore(a, i + 1, high);
}

void QuickSorting(int a[], int len) {
	SortCore(a,0,len-1);
}

int main() {
	int array[] = {5, 4, 9, 8, 7, 6, 0, 1, 3, 2};
	int len = sizeof(array) / sizeof(array[0]);
	QuickSorting(array, len);

	for (auto i : array)
		cout << i << "  ";
	cout << endl;

	system("pause");
	return 0;
}