#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "Shell -> ";
	char *ptr_txt = NULL, *txt_copy = NULL;
	size_t n = 0;
	ssize_t charNB;
	const char *delim = " \n";

	(void)ac;
	(void)argv;
	(void)delim;
	(void)txt_copy;

	while (1)
	{
		printf("%s", prompt);
		charNB = getline(&ptr_txt, &n, stdin);
		if (charNB == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		printf("%s\n", ptr_txt);

		free(ptr_txt);
	}

	return (0);
}
