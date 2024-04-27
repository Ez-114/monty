#include "monty.h"


/**
 * add_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *current_node;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	current_node = head;
	head = *new_node;
	head->next = current_node;
	current_node->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current_node = *stack;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;

	if (stack == NULL || *stack == NULL)
		more_err_handler(7, line_number);

	current_node = *stack;
	*stack = current_node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current_node);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err_handler(6, line_number);
	printf("%d\n", (*stack)->n);
}
