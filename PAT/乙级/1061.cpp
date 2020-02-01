#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	int stu, num;
	cin >> stu >> num;
	int score[num] = {0};
	for (int i = 0; i < num; ++i)
	{
		cin >> score[i];
	}
	int answer[num] = {0};
	for (int i = 0; i < num; ++i)
	{
		cin >> answer[i];
	}
	int in[num] = {0};
	int out[stu] = {0};
	for (int i = 0; i < stu; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> in[j];
			if (in[j] == answer[j])
			{
				out[i] += score[j];
			}
		}
	}
	for (int i = 0; i < stu; ++i)
	{
		if (i == stu-1)
			cout << out[i];
		else
			cout << out[i] << endl;
	}
	return 0;
}