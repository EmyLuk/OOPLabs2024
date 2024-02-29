#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

char sir[105];
int  i, n, s = 0;
int fun(char a[], int poz);
int main()
{
	FILE* file;
	auto succes = fopen_s(&file, "in.txt", "r");
	if (file == NULL) {
		printf("File - Opening Error!");
		return 0;
	}
	while (fgets(sir, 102, file))
	{
		n = strlen(sir);
		for (i = 0; i < n; i++)
		{
			if (sir[i] >= '0' && sir[i] <= '9')
			{
				int cnt = fun(sir, i);
				printf("%d\n", cnt);
				s = s + cnt;

			}
		}

	}

	printf("%d\n", s);
	fclose(file);

	return 0;
}
int fun(char sir[], int poz)
{
	i = poz; int nr = 0;
	while (sir[i] >= '0' && sir[i] <= '9')
	{
		nr = nr * 10 + int(sir[i] - '0');
		i++;
	}
	return nr;
}