#include <iostream>

#include "Sales_item.h"

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
	cout << "Please enter two integer��";  //�����û�������������
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

/*�������ƣ�SumInputNumber()
*������������
*�������ܣ����������������ݵĺ�
*��������ֵ����
*/

void SumInputNumber()
{
	float sum = 0, value = 0;
	cout << "Please enter the number you want to sum up" << endl;
	while (cin >> value)  //���κ���ĸ�����������Ctrl+z
	{
		sum += value;
		cout << "Next Number, to end please enter a letter" << endl;
	}
	cout << "sum:" << sum << endl;
	
}

/*�������ƣ�ReadSalesItem()
*������������
*�������ܣ���������ÿ��������ۼ�¼֮�Ͳ�ͳ��ÿ�����м������ۼ�¼��ע��ͬһ��������ۼ�¼�벻Ҫ�Ͽ����롣
��������ֵ����
*/

void ReadSalesItem()
{
	Sales_item item , item_sum;
	int count = 1;  //��ʼ��Ϊ1����Ϊ��һ������û�м���whileѭ��
	cout << "Enter the book saling history:" << endl;
	if (cin >> item)  //�ж������Ƿ���ȷ������
	{
		item_sum = item; //��ʼ��item_sum
		cout << "Enter Ctrl+z to end up the progress����";

		while (cin >> item)
		{
			if (item_sum.isbn() == item.isbn())  //�ж��Ƿ�Ϊͬһ����
			{
				item_sum += item;
				count++;

			}
			else  //�������ͬһ���飬�������һ�����ͳ�ƽ����������͸�ֵ
			{
				cout << "count of book: " << item_sum.isbn() << "is: " << count << endl;
				cout << "sum of items: " << item_sum << endl;
				item_sum = item;
				count = 0;

			}
			cout << "Enter Ctrl+z to end up the progress����" << endl;  //�û���ʾ

		}
		cout << "count of book: " << item_sum.isbn() << "is: " << count << endl;  //��ӡ���һ����Ľ��
		cout << "sum of items: " << item_sum << endl;

	}
	else
	{
		cerr << "No Right Data?!" << endl;  //�����û���û����ȷ����
	}
	
	
}
int main()
{
	ReadSalesItem();
	system("pause");
//return 0;
}