#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: argument counter
 * @argv: each argument
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	ssize_t chars_read;
	size_t len = 0;
	stack_t *head = NULL;
	FILE *fileopen;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileopen = fopen(argv[1], O_RDONLY);
	if (fileopen == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	chars_read = getline(&line, &len, fileopen);
	if (chars_read == -1)
	{
		fclose(fileopen);
		exit(EXIT_FAILURE);
	}
	tokenize(head, line);
	free_dlist(&head);
	fclose(fileopen);
	return (0);
}

/**
 * tokenize - tokenizes the line
 * @head: head of the dlinkedlist
 * @line: line to be tokenized
 * Return: void
 */
void tokenize(stack_t *head, char *line)
{
	char *line_dup = NULL, *token = NULL, *delim = "\n";
	unsigned int line_counter = 1;
	int flag = 0;

	line_dup = strdup(line);
	token = strtok(line_dup, delim);
	while (token != NULL)
	{
		if (flag == 1)
		{
			push(&head, line_counter, token);
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
				get_op_func(token)(&head, line_counter);
			else
			{
				free_dlist(&head);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, token);
				exit(EXIT_FAILURE);
			}
		}
		line_counter++;
	}
}
