#include<iostream>
#include<string>
#include<set>
using namespace std;

//获得所有最长子序列
void get_all_longest_commen_subsequence(string s1,string s2,int** value_matrix, int rows,int cols, string &result);
//反转序列
string reverse(string s);

set<string>sequence;
int main()
{
	int** value_matrix = nullptr;
	string s1, s2;
	cout << "请输入两个序列：" << endl;
	cin >> s1 >> s2;

	//获取数组的行、列
	int rows = s1.length() + 1;
	int cols = s2.length() + 1;

	//进行二维数组的内存申请并进行相应计算
	value_matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		value_matrix[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || j == 0)
				value_matrix[i][j] = 0;

			else if (s1[i - 1] == s2[j - 1])
				value_matrix[i][j] = value_matrix[i - 1][j - 1] + 1;

			else
				value_matrix[i][j] = value_matrix[i - 1][j] > value_matrix[i][j - 1] ? value_matrix[i - 1][j] : value_matrix[i][j - 1];
		}
	cout << endl;
	cout << "所有最长公共子序列为：" << endl;
	string result;
	get_all_longest_commen_subsequence(s1, s2, value_matrix, rows - 1, cols - 1, result);
	
	for (set<string>::iterator result = sequence.begin(); result != sequence.end(); result++)
		cout << *result << endl;
	
	//释放指针
	delete[] value_matrix;
	return 0;
}
	

void get_all_longest_commen_subsequence(string s1, string s2, int** value_matrix, int rows, int cols, string &result)
{
	string temp;

	for (int i = rows, j = cols; i != 0 && j != 0; ) 
	{
		//如果两个序列对对应的元素相等，则各往前进一个元素，否则直接结束函数
		if (s1[i - 1] == s2[j - 1])
		{
			result+=s1[i - 1];
			i--;
			j--;
		}
		else 
		{
			if (value_matrix[i - 1][j] == value_matrix[i][j]) 
			{
				temp = result;
				get_all_longest_commen_subsequence(s1, s2, value_matrix, i-1, j, result);
				result = temp;
			}
			if (value_matrix[i][j - 1] == value_matrix[i][j]) 
			{
				temp = result;
				get_all_longest_commen_subsequence(s1, s2, value_matrix, i, j-1, result);
				result = temp;
			}
			return;
		}
	}
	sequence.insert(reverse(result));
}

/*
*反转序列
*/
string reverse(string s)
{
	string result;
	for (int i = 0; i < s.length(); i++)
	{
		result += s[s.length() - 1 - i];
	}
	return result;
}
