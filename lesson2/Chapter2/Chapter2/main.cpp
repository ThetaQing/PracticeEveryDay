#include <iostream>
using namespace std;

int main()
{
	unsigned u = 10;  //表示unsigned int类型的数据
	int i_value1 = 10;
	int i = 42;
	cout << typeid(i).name() << endl;
	cout << i + i << endl;  //输出-84
	cout << u + i << endl;  //如果int是32位，输出结果为4294967264
	cout << u - i_value1 << endl;
	system("pause");
	return 0;
}

