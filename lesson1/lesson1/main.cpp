#include <iostream>

#include "Sales_item.h"

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
	cout << "Please enter two integer：";  //提醒用户输入两个整数
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

/*函数名称：SumInputNumber()
*函数参数：无
*函数功能：计算所有输入数据的和
*函数返回值：无
*/

void SumInputNumber()
{
	float sum = 0, value = 0;
	cout << "Please enter the number you want to sum up" << endl;
	while (cin >> value)  //按任何字母键结束输入或按Ctrl+z
	{
		sum += value;
		cout << "Next Number, to end please enter a letter" << endl;
	}
	cout << "sum:" << sum << endl;
	
}

/*函数名称：ReadSalesItem()
*函数参数：无
*函数功能：计算输入每本书的销售记录之和并统计每本书有几条销售记录，注意同一本书的销售记录请不要断开输入。
函数返回值：无
*/

void ReadSalesItem()
{
	Sales_item item , item_sum;
	int count = 1;  //初始化为1，因为第一次输入没有计入while循环
	cout << "Enter the book saling history:" << endl;
	if (cin >> item)  //判断输入是否正确！！！
	{
		item_sum = item; //初始化item_sum
		cout << "Enter Ctrl+z to end up the progress……";

		while (cin >> item)
		{
			if (item_sum.isbn() == item.isbn())  //判断是否为同一本书
			{
				item_sum += item;
				count++;

			}
			else  //如果不是同一本书，先输出上一本书的统计结果，再清零和赋值
			{
				cout << "count of book: " << item_sum.isbn() << "is: " << count << endl;
				cout << "sum of items: " << item_sum << endl;
				item_sum = item;
				count = 0;

			}
			cout << "Enter Ctrl+z to end up the progress……" << endl;  //用户提示

		}
		cout << "count of book: " << item_sum.isbn() << "is: " << count << endl;  //打印最后一本书的结果
		cout << "sum of items: " << item_sum << endl;

	}
	else
	{
		cerr << "No Right Data?!" << endl;  //警告用户，没有正确输入
	}
	
	
}
int main()
{
	ReadSalesItem();
	system("pause");
//return 0;
}