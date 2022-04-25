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
			//如果体积小于j即背包中可以装下
			if (volume[i-1] <= j)
			{
				//获得装下和不装下的情况最大的值
				Prize[i][j] = (value[i-1] + Prize[i-1][j - volume[i-1]]>Prize[i-1][j] ? value[i-1] + Prize[i - 1][j - volume[i-1]] : Prize[i - 1][j]);
			}
			//背包中装不下
			else 
			{
				Prize[i][j] = Prize[i-1][j];
			}
		}
	}
	
	int temp = count;
	//从后向前根据关系进行输出
	for (int i = number; i >0; i--)
	{
		//如果不相等则说明第i个物品是装进背包的
		if (Prize[i][temp] != Prize[i - 1][temp])
		{
			temp -= volume[i - 1];
			cout << "选取商品：" << i << endl;
		}
	}
	cout << "选取的商品总价值为：" << Prize[number][count] << endl;
	
	//释放空间
	for (int i = 0; i <= number; i++)
	{
		delete Prize[i];
	}
	delete []Prize;
	return 0;
}
