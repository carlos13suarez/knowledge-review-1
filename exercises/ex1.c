#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct operation
{
	int (*add)(int n, ...);
	int (*sub)(int n, ...);
	int (*mul)(int n, ...);
	int (*div)(int n, ...);
} operation_t;

int add(int n, ...)
{
	va_list num_arguments;
	int i = 0, sum = 0;

	va_start(n, num_arguments);

	for(i = 0; i < n; i++)
		sum += va_arg(num_arguments, int);

	va_end(num_arguments);

	return (sum);
}

int sub(int n, ...)
{
	va_list num_arguments;
	int i = 0, substraction = 0;

	va_start(n, num_arguments);
	
	substraction = va_arg(num_arguments, int);

	for(i = 0; i < n; i++)
		substraction -= va_arg(num_arguments, int);

	va_end(num_arguments);

	return (substraction);
}


int mul(int n, ...)
{
	va_list num_arguments;
	int i = 0, product = 0;

	va_start(n, num_arguments);

	for(i = 0; i < n; i++)
		product *= va_arg(num_arguments, int);

	va_end(num_arguments);

	return (product);
}


int div(int n, ...)
{
	va_list num_arguments;
	int i = 0, division = 0;

	va_start(n, num_arguments);

	for(i = 0; i < n; i++)
		division /= va_arg(num_arguments, int);

	va_end(num_arguments);

	return (division);
}


/**
 *
 *
 */
int main(int argc, char *argv[])
{
	int i = 0, result = 0;
	int *nums = malloc((argc - 2) *  sizeof(int));

	if (!nums)
		return (1);

	while (argv[i] != NULL)
	{
		nums[i] = atoi(argv[i]);
		if (nums[i] == 0 && argv[i] != "0")
		{
			printf("ERROR: argument is not a number");
			return (1);
		}
		i++;
	}

	operation_t *operators = malloc(sizeof(operation_t));

	char *valid_operations[] = {"add", "sub", "mul", "div"};

	for (i = 0; i < 4; i++)
	{
		if(argv[1] == "add")
			result = operators->add(argv[2], ...);
	}

	printf("Answer: %d\n", result);
	return (0);
}
