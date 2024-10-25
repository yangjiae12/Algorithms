#include <iostream>
using namespace std;

#define SWAP(x, y, t) (t=x, x=y, y=t)

double L[15] = { 10, 4, 0, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data(double L[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		cout << " " << L[i];
	cout << endl;
}

void Max_heap(double L[], int root, int n)
{
	int child, root_data;

	root_data = L[root];
	child = root * 2 + 1;

	while (child <= n - 1)
	{
		if (child < n - 1 && L[child] < L[child + 1]) {
			child = child + 1;
		}
		if (root_data > L[child])
		{
			break;
		}
		else {
			L[(child - 1) / 2] = L[child];
			child = child * 2 + 1;
		}
	}
	L[(child - 1) / 2] = root_data;
}

void HeapSort(double L[], int n)
{
	int i, temp;

	// �ִ� ���� ���� ����
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
		Max_heap(L, i, n);

	// ���� ����
	// ����ū��(0��° ����)�� ������(n-1��°)���� �ű�� heap �籸��
	for (i = n - 2; i >= 0; i--)
	{
		//�� ���� L[0],L[i+1] ��ȯ
		SWAP(L[0], L[i + 1], temp);
		Max_heap(L, 0, i);
	}
}

void main()
{
	// ó�� ���¸� ������
	cout << "Input Data : ";
	print_data(L, 15);

	/* sort the elements of array L[] in ascending order */
	HeapSort(L, 15);

	// ���ĵ� ����� ������
	cout << "\nSorted Data : ";
	print_data(L, 15);

}
