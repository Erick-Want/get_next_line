#include <stdio.h>

int	fibonacci()
{
	static int	i = 1;

	printf("Inicial: %d\n", i);
	i = i + i;
	printf("Final: %d\n\n", i);
	return (i);
}
int	main()
{
	int i;

	i = 0;
	while (i < 5)
	{
		fibonacci();
		i++;
	}
	return (0);
}

// int fun()
// {
//   static int count = 0;
//   count++;
//   return count;
// }

// int main()
// {
//   printf("%d ", fun());
//   printf("%d ", fun());
//   printf("%d ", fun());
//   return 0;
// }
