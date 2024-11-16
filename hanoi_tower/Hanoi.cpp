#include <iostream> 
using namespace std;

int cnt = 0;

void Hanoi(int n, char from, char temp, char to)
// n : ���ݰ���, from : ���� ��ġ, temp : �ӽ� ���, to :������
{
	// �ڵ� �ۼ�
	if (n == 1) {
		cnt++;
		cout << "#" << cnt << " Move a disk from " << from << " to " << to << endl;
	}
	else { // ��ĭ�� ä�� ���α׷��� �ϼ��ϼ���.
		Hanoi(n - 1, from, to, temp);
		cnt++;
		cout << "#" << cnt << " Move a disk from " << from << " to " << to << endl;
		Hanoi(n - 1, temp, from, to);
	}
}


void main()
{
	int n; //������ ��

	cout << "������ ������ �Է��ϼ��� : ";
	cin >> n;

	Hanoi(n, 'A', 'B', 'C');    // n���� ������ 'A'���� 'C'�� �̵�

	cout << "��ü ���� �̵� ��(���ݼ� : " << n << ") = " << cnt << endl;
}