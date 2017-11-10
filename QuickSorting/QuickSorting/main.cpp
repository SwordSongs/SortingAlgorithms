#include<iostream>
using namespace std;

void SortCore(int a[], int low, int high) {
	int pivot;
	if (low >= high)          //�ݹ����
		return;

	int i = low;
	int j = high;
	pivot = a[i];            //ѡȡ��һ��Ԫ����Ϊ����Ԫ��

	while (i < j) {
		while (i < j && a[j] >= pivot)	--j;
		
		if (i < j)
			a[i++] = a[j];     //�ҵ����С�������Ԫ���û���ǰ��

		while (i < j && a[i] < pivot)	++i;

		if (i < j)
			a[j--] = a[i];    //�ҵ�ǰ�˴��������Ԫ���û������

	}

	a[i] = pivot;            //i��j��������������
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