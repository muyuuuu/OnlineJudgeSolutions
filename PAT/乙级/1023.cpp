// 2 2 0 0 0 3 0 0 1 0
// 10015558
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string str1;
	string in;
	int num[10] = {0};
    int flag = 0;
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &num[i]);
    }
    // cout << num[5] << endl;
	for (int i = 0; i <= 9; i += 1)
	{
		if (num[i] != 0)
		{
			for (int j = 0; j < num[i]; ++j)
			{
				in = to_string(i);
				str1.append(in); 
                // cout << str1 << endl;
			}
		}
	}	
	if (str1.find('0', 0) == string::npos)
    {
        cout << str1;
        return 0;
    }
    else
    {
    	int position = 0;
    	for (int i = 0; i < str1.size(); ++i)
    	{
    		if (str1[i] - '0' != 0)
    		{
    			position = i;
    			break;
    		}
    	}
    	str1[0] = str1[position];
    	str1[position] = '0';
    }
    cout << str1;
    return 0;
}