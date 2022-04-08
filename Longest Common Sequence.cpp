#include<iostream>
#include<string>

using namespace std;
string get_longest_subsequence(string s1,string s2);
void maximum_common_subsequence(string s, int** direction_matrix, int rows, int cols, string& result);

int main()
{
	//string s1 = "BDCABA", s2 = "ABCBDAB";
	string s1, s2;
	cout << "请输入两个字符串" << endl;
	cin >> s1 >> s2;

	string result_1 = get_longest_subsequence(s1, s2);
	string result_2 = get_longest_subsequence(s2, s1);

	if (result_1.length() == result_2.length())
	{
		if (result_1 == result_2)
		{
			cout << "最长公共子序列为：" << result_1 << endl;
		}
		else
		{
			cout << "最长公共子序列为：" << result_1 << "、" << result_2 << endl;
		}
	}
	else if (result_1.length() > result_2.length())
	{
		cout << "最长公共子序列为：" << result_1 << endl;
	}
	else
	{
		cout << "最长公共子序列为：" << result_2 << endl;
	}

	return 0;
}
	

string get_longest_subsequence(string s1, string s2)
{
	int** value_matrix = nullptr, ** direction_matrix = nullptr;
	//获取数组的行、列
	int cols = s1.length() + 1;
	int rows = s2.length() + 1;

	//进行两个二维数组的内存申请
	value_matrix = new int* [rows];
	direction_matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		value_matrix[i] = new int[cols];
		direction_matrix[i] = new int[cols];
	}

	//对方向数组进行赋值
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			direction_matrix[i][j] = 0;
			value_matrix[i][j] = 0;
		}
			

	//进行对应计算
	for (int i = 1; i < rows; i++)
		for (int j = 1; j < cols; j++)
		{
			if (s1[j - 1] == s2[i - 1])
			{
				value_matrix[i][j] = value_matrix[i - 1][j - 1] + 1;
				direction_matrix[i][j] = 1;
			}
			else if (value_matrix[i - 1][j] >= value_matrix[i][j - 1])
			{
				value_matrix[i][j] = value_matrix[i - 1][j];
				direction_matrix[i][j] = 2;
			}
			else
			{
				value_matrix[i][j] = value_matrix[i][j - 1];
				direction_matrix[i][j] = 3;
			}
		}

	//对结果进行显示
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << value_matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------------------------" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << direction_matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------------------------" << endl;

	//用result获取结果
	string result;
	maximum_common_subsequence(s1, direction_matrix, rows - 1, cols - 1, result);

	int result_length = result.length();
	string temp = result;
	for (int i = 0; i < result_length; i++)
	{
		result[i] = temp[result_length - 1 - i];
	}
	
	//释放指针
	delete[] value_matrix;
	delete[] direction_matrix;

	return result;
}



//寻找最长公共子序列
/*
* 参数：进行比较的两个字符串中一个、符号数组、符号数组长度、符号数组宽度、用来保存最大公共子序列倒序的字符
*/
void maximum_common_subsequence(string s, int** direction_matrix, int rows, int cols, string& result)
{
	//如果寻找到了第一行/列，则退出
	if (rows == 0 || cols == 0)
		return;
	//如果是相同的则输出
	if (direction_matrix[rows][cols] == 1)
	{
		result+= s[cols - 1];
		maximum_common_subsequence(s, direction_matrix, rows - 1, cols - 1, result);
	}
	else if (direction_matrix[rows][cols] == 2)
	{
		maximum_common_subsequence(s, direction_matrix, rows - 1, cols, result);
	}
	else
	{
		maximum_common_subsequence(s, direction_matrix, rows, cols - 1, result);
	}
}
