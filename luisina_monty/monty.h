#ifndef MONTY_H
#define MONTY_H

/* libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */
int main(int argc, char **argv);
int add_dnodeint(stack_t **head, const int n);
void delete_node(stack_t **head);
void free_dlist(stack_t **head);
void tokenize(stack_t *head, char *line);
void (*get_op_func(char *token))(stack_t **stack, unsigned int line_counter);
int is_digit(const char *n);
void push(stack_t **head, unsigned int line_counter, const char *n);
void pop(stack_t **head, unsigned int line_counter);
void pall(stack_t **head, unsigned int line_counter);
void pint(stack_t **head, unsigned int line_counter);
void _add(stack_t **head, unsigned int line_counter);
void swap(stack_t **head, unsigned int line_counter);
void nop(stack_t **head, unsigned int line_counter);

#endif

