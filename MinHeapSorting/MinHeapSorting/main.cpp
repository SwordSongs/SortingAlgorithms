#include<iostream>
using namespace std;

void _swap(int& a, int& b) {   //交换
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void adjustMinHeap(int a[], int pos, int rear) {
	int child;

	for (; 2 * pos + 1 <= rear; pos = child) {      //三个取最小交换后，有可能交换导致不满足，连锁调整
		child = 2 * pos + 1;
		if (child <= rear && child+1 <= rear && a[child] > a[child + 1])  ++child;   //找出两个孩子比较小的
		if (a[pos] > a[child]) _swap(a[pos], a[child]);    //如果父亲顶点较小，交换
	}
}

void minHeapSorting(int a[], int len) {
	int i;
	for (i = len/2 -1; i >= 0; --i)        //从第一个非叶子顶点开始调整
		adjustMinHeap(a, i, len-1);

	for (i = len-1; i >= 0; --i) {
		_swap(a[0], a[i]);                    //跟末尾元素交换，变成倒序
		adjustMinHeap(a, 0, i-1);             //不满足小顶堆定义
	}
}

void printArray(int a[], int len) {
	for (int i = len-1; i >= 0; --i)
		cout << a[i] << " ";
	cout << endl;
}
int main() {
	int array[] = {5, 4, 1, 3, 2, 7, 9, 0, 8, 6};
	int len = sizeof(array) / sizeof(array[0]);
	minHeapSorting(array, len);
	printArray(array,len);

	system("pause");
	return 0;
}