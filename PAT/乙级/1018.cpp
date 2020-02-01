#include "iostream"
#include <string>
using namespace std;

int main()
{
	int len = 0;
	scanf("%d", &len);
	int win = 0, draw = 0, lose = 0;
	int ac=0, aj=0, ab=0; 
	int bc=0, bj=0, bb=0;
	char a, b;
	for(int i = 0; i < len; i++)
	{
		cin >> a >> b;
		if ((a == 'C' && b == 'C') || (a == 'B' && b == 'B') || (a == 'J' && b == 'J'))
		{
			draw++;
		}
		if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C'))
		{
			win++;
		}
		if (a == 'C' && b == 'J')
		{
			ac++;
		}
		if (a == 'J' && b == 'B')
		{
			aj++;
		}
		if (a == 'B' && b == 'C')
		{
			ab++;
		}
		if (a == 'C' && b == 'B')
		{
			bb++;
		}
		if (a == 'J' && b == 'C')
		{
			bc++;
		}
		if (a == 'B' && b == 'J')
		{
			bj++;
		}
	}
	lose = len - win - draw;
	cout<<win<<" "<<draw<<" "<<lose<<endl;
	cout<<lose<<" "<<draw<<" "<<win<<endl;
	// cout<<aj<<"  "<<ab<<"  "<<ac<<endl;
	while(1)
	{
		if(ab >= aj && ab >= ac)
		{
			printf("%c ", 'B');
			break;
		} 
		if(ac >= aj && ac >= ab) 
		{
			printf("%c ", 'C');
			break;
		}
		if(aj >= ab && aj >= ac)
		{
			printf("%c ", 'J');
			break;
		} 
	}
	while(1)
	{
		if(bb >= bj && bb >= bc)
		{
			printf("%c", 'B');
			break;
		} 
		if(bc >= bj && bc >= bb) 
		{
			printf("%c", 'C');
			break;
		}	
		if(bj >= bb && bj >= bc)
		{
			printf("%c", 'J');
			break;
		} 
	}
	return 0;
}