#include<iostream>
using namespace std;

int main()
{
	//商品的价值数组
	double* value;
	//商品的体积数组
	int* volume;
	
	int number, count;
	cout << "请输入商品总数和背包容量：" << endl;
	cin >> number >> count;
	
	//申请number个空间，方便后续操作
	value = new double[number];
	volume = new int[number];

	//初始化商品的价值和体积数组
	cout << "请输入各商品价值和体积：" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> value[i]>>volume[i];
	}

	//存储总价值的数组
	double** Prize;
	Prize = new double*[number+1];
	for (int i = 0; i <= number; i++)
	{
		Prize[i] = new double[count+1];
	}
	//初始化
	for (int i = 0; i <= count; i++)
	{
		Prize[0][i] = 0;
	}
	for (int i = 0; i <= number; i++)
	{
		Prize[i][0] = 0;
	}
	//动态规划
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= count; j++)
		{
			if (volume[i-1] <= j)
			{
				Prize[i][j] = (value[i-1] + Prize[i-1][j - volume[i-1]]>Prize[i-1][j]? value[i-1] + Prize[i - 1][j - volume[i-1]] : Prize[i - 1][j]);
			}
			else 
			{
				Prize[i][j] = Prize[i-1][j];
			}
		}
	}
	for (int i = number; i >1; i--)
	{
		if (Prize[i][count] != Prize[i - 1][count])
		{
			count -= volume[i - 1];
			cout << "选取商品：" << i << endl;
		}
	}
	if (Prize[1][count] != 0)
	{
		cout << "选取商品：" << 1 << endl;
	}
	return 0;
}
