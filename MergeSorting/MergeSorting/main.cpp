#include<iostream>
using namespace std;

void Merge(int a[], int low, int mid, int high) {
	int i, j, k;
	int len1, len2;

	len1 = mid - low + 1;      //for example: mid = (0+3)/2 = 1; n1 = 1-0+1 = 2; n2 = 3-1 = 2;
	len2 = high - mid;

	int* L = new int[len1];
	int* R = new int[len2];

	for (i = 0, k = low; i < len1; ++i, ++k) {               //拷贝左部分
		L[i] = a[k];
	}

	for (i = 0, k = mid + 1; i < len2; ++i, ++k) {           //拷贝右部分
		R[i] = a[k];
	}

	for (k = low, i = 0, j = 0; i < len1 && j < len2; ++k) {
		if (L[i] < R[j]) {          //递增的顺序合并
			a[k] = L[i];
			++i;
		}
		else {
			a[k] = R[j];
			++j;
		}

	}


	if (i < len1) {          //左半部分较长，拷贝剩余
		for (j = i; j < len1; ++j, ++k) {
			a[k] = L[j];
		}
	}

	if (j < len2) {        //右半部分较长，拷贝剩余
		for (i = j; i < len2; ++i, ++k) {
			a[k] = R[i];
		}
	}

	delete[] L;
	delete[] R;
}

void MergeSorting(int a[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSorting(a, low, mid);          //递归左部分
		MergeSorting(a,mid+1,high);         //递归右部分
		Merge(a,low,mid,high);
	}
}

int main() {
	int array[] = {5, 4, 9, 8, 7, 6, 0, 1, 3, 2};
	int len = sizeof(array) / sizeof(array[0]);
	MergeSorting(array,0,len-1);
	
	for (auto i : array) {
		cout << array[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}