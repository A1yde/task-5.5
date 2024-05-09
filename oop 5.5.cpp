#include<iostream>
#include<vector>

using namespace std;

void out(vector<vector<int>> vec);
void findpos(vector<vector<int>> vec);

int main()
{
	int rows, cols;
	cout << "Enter matrix rows:";
	cin >> rows;
	cout << "Enter matrix cols:";
	cin >> cols;

	vector<vector<int>> vec;
	for (int i = 0; i < rows; i++)
	{
		vector<int> temp;
		for (int j = 0; j < cols; j++)
		{
			int n;
			cout << "Enter number";
			cin >> n;
			temp.push_back(n);
		}
		vec.push_back(temp);

	}
	out(vec);
	findpos(vec);

	return 0;

}

void out(vector<vector<int>> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{                  
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void findpos(vector<vector<int>> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int min_val = vec[i][0];
		int col = 0;

		for (int j = 1; j <vec[i].size(); j++)
		{
			if (vec[i][j] < min_val)
			{
				min_val = vec[i][j];
				col = j;
			}
		}




		bool point = true;
		for (int k = 0; k < vec.size(); k++)
		{
			if (vec[k][col] < min_val)
			{
				point = false;
				break;
			}
		}


		if (point)
		{
			cout << "Saddle point found at (" << i << ", " << col << "): " << min_val << endl;
		}
	}
}