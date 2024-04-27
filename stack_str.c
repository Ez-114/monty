#include "monty.h"

/**
 * printc - Prints the char_value value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void printc(stack_t **stack, unsigned int line_number)
{
	int char_value;

	if (stack == NULL || *stack == NULL)
		string_err_handler(11, line_number);

	char_value = (*stack)->n;
	if (char_value < 0 || char_value > 127)
		string_err_handler(10, line_number);
	printf("%c\n", char_value);
}

/**
 * prints - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void prints(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int char_value;
	stack_t *current_node;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	current_node = *stack;
	while (current_node != NULL)
	{
		char_value = current_node->n;
		if (char_value <= 0 || char_value > 127)
			break;
		printf("%c", char_value);
		current_node = current_node->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current_node = *stack;
	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	(*stack)->prev = current_node;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current_node = *stack;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	current_node->prev->next = NULL;
	current_node->prev = NULL;
	(*stack)->prev = current_node;
	(*stack) = current_node;
}
