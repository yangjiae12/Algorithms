#include <iostream> 
using namespace std;

int cnt = 0;

void Hanoi(int n, char from, char temp, char to)
// n : 원반개수, from : 원래 위치, temp : 임시 장소, to :목적지
{
	// 코드 작성
	if (n == 1) {
		cnt++;
		cout << "#" << cnt << " Move a disk from " << from << " to " << to << endl;
	}
	else { // 빈칸을 채워 프로그램을 완성하세요.
		Hanoi(n - 1, from, to, temp);
		cnt++;
		cout << "#" << cnt << " Move a disk from " << from << " to " << to << endl;
		Hanoi(n - 1, temp, from, to);
	}
}


void main()
{
	int n; //원반의 수

	cout << "원반의 갯수를 입력하세요 : ";
	cin >> n;

	Hanoi(n, 'A', 'B', 'C');    // n개의 원반을 'A'에서 'C'로 이동

	cout << "전체 원반 이동 수(원반수 : " << n << ") = " << cnt << endl;
}