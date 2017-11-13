#include<iostream>
using namespace std;

void _swap(int& a, int& b) {   //����
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void adjustMinHeap(int a[], int pos, int rear) {
	int child;

	for (; 2 * pos + 1 <= rear; pos = child) {      //����ȡ��С�������п��ܽ������²����㣬��������
		child = 2 * pos + 1;
		if (child <= rear && child+1 <= rear && a[child] > a[child + 1])  ++child;   //�ҳ��������ӱȽ�С��
		if (a[pos] > a[child]) _swap(a[pos], a[child]);    //������׶����С������
	}
}

void minHeapSorting(int a[], int len) {
	int i;
	for (i = len/2 -1; i >= 0; --i)        //�ӵ�һ����Ҷ�Ӷ��㿪ʼ����
		adjustMinHeap(a, i, len-1);

	for (i = len-1; i >= 0; --i) {
		_swap(a[0], a[i]);                    //��ĩβԪ�ؽ�������ɵ���
		adjustMinHeap(a, 0, i-1);             //������С���Ѷ���
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