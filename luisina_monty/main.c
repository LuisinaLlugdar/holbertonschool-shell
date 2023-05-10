#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: argument counter
 * @argv: each argument
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd, flag = 0;
	unsigned int line_counter = 1;
	char *token, *line = NULL, *line_dup = NULL;
	ssize_t chars_read, len = 0;
	stack_t *h = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	chars_read = getline(&line, &len, fd);
	if (chars_read == -1)
	{
		free(chars_read);
		close(fd);
		exit(EXIT_FAILURE);
	}
	line_dup = strdup(line);
	token = strtok(line_dup, "\n");
	while (token != NULL)
	{
		if (flag == 1)
		{
			push(&h, line_counter, token);
			flag = 0;
			token = strtok(NULL, "\t ");
			line_counter++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			flag = 1;
			token = strtok(NULL, "\t ");
			continue;
		}
		else
		{
			if (get_op_func(token) != 0)
				get_op_func(token)(&h, line_counter);
			else
			{
				free_dlist(&h);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, token);
				exit(EXIT_FAILURE);
			}
		}
		line_counter++;
	}
	free_dlist(&h); free(chars_read);
	close(fd);
	return (0);
}
