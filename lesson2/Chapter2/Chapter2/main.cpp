#include <iostream>
using namespace std;

int main()
{
	unsigned u = 10;  //��ʾunsigned int���͵�����
	int i_value1 = 10;
	int i = 42;
	cout << typeid(i).name() << endl;
	cout << i + i << endl;  //���-84
	cout << u + i << endl;  //���int��32λ��������Ϊ4294967264
	cout << u - i_value1 << endl;
	system("pause");
	return 0;
}

