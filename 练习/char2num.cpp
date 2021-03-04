#include "stdio.h"
#include "string.h"

# define maxn 1000

int main(int argc, char const *argv[])
{
	char s[maxn];
	scanf("%s", s);
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] - '1' == 0) count = count + 1;
	}
	printf("%d", count);
	return 0;
}