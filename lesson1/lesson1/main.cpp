
#include <iostream>


using namespace std;

/* 函数名 : PrintIntegerArangeTwoInteger()
* 函数参数：无
* 函数功能: 控制台打印用户输入的任意两个正整数之间的所有整数
*函数返回值：无
*/
int PrintIntegerArangeTwoInteger()
{
	int v1 =0 ; int v2 = 0;
	int temp = 0;
	cout << "Hello,World" << endl;
	cout << "Please enter two integer：";
	cin >> v1 >> v2;
	if (v1 < v2)
	{
		temp = v1;
		v1 = v2;
		v2 = temp;
	}

	while (v1 >= v2)
	{
		cout << v2 << endl;
		v2++;

	}
	return 0;
}
int main()
{
	PrintIntegerArangeTwoInteger();		
	system("pause");
//return 0;
}