#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float col;
	char c;
	cin>>col>>c;
	int row = round(col/2);
	for (int i = 0; i < row; i++)
	{
		if (i == 0 || i == row - 1)
		{
			for(int j = 0; j < col; j++)
				printf("%c", c);
			if (i == 0)
				printf("\n");
		}
		else
		{
			for (int j = 0; j < col; j++)
			{
				if (j == 0)
					printf("%c", c);
				if (j == col - 1)
					printf("%c\n", c);
				if (j != 0 && j != col - 1)
					printf("%c", 32);
			}
		}
	}
	return 0;
}