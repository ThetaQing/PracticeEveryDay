
#include <iostream>


using namespace std;

/* ������ : PrintIntegerArangeTwoInteger()
* ������������
* ��������: ����̨��ӡ�û��������������������֮�����������
*��������ֵ����
*/
int PrintIntegerArangeTwoInteger()
{
	int v1 =0 ; int v2 = 0;
	int temp = 0;
	cout << "Hello,World" << endl;
	cout << "Please enter two integer��";
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