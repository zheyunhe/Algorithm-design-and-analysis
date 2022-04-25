#include<iostream>
#include<string>
using namespace std;

struct goods 
{
	string name;
	double value;
	double volume;
	double cost_performence;
	double use_rate;
};

void Merge(goods *r, int low, int mid, int high)
{
	goods* temp = new goods[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high)
	{
		if (r[i].cost_performence <= r[j].cost_performence)
		{
			temp[k++] = r[i++];
		}
		else
		{
			temp[k++] = r[j++];
		}
	}
	while (i <= mid) temp[k++] = r[i++];
	while (j <= high) temp[k++] = r[j++];
	for (int i = low, k = 0; i <= high; i++)
	{
		r[i] = temp[k++];
	}
	delete[]temp;
}

void MergeSort(goods *r, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(r, low, mid);
		MergeSort(r, mid + 1, high);
		Merge(r, low, mid, high); //先拆分，在融合
	}
}




int main()
{
	int number, count;
	cout << "请输入商品总数和背包容量：" << endl;
	cin >> number >> count;

	goods* p;
	p = new goods[number];

	//初始化商品的价值和体积数组
	cout << "请输入各商品名称、价值和体积：" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> p[i].name >> p[i].value >> p[i].volume;
	}

	for (int i = 0; i < number; i++)
	{
		p[i].cost_performence = p[i].value / p[i].volume;
	}
	//对商品数组根据性价比进行排序
	MergeSort(p,0,number-1);
	
	double prize=0;
	for (int i = number - 1; i >= 0; i--)
	{
		if (count != 0)
		{
			if (count < p[i].volume)
			{
				p[i].use_rate = count / p[i].volume;
				cout << "选择物品：" << p[i].name << "的获取率：" << p[i].use_rate << endl;
				prize += p[i].value * p[i].use_rate;
				count = 0;
			}
			else
			{
				p[i].use_rate = 1;
				cout << "选择物品：" << p[i].name <<"的获取率：" <<p[i].use_rate << endl;
				prize += p[i].value;
				count -= p[i].volume;
			}
		}
	}
	cout << "选择的商品总价值为：" << prize << endl;
	delete []p;
	return 0;
}
