#include "monty.h"

/**
 * open_file - opens a file
 * @name: the file namepath
 * Return: void
 */

void open_file(char *name)
{
	FILE *fd = fopen(name, "r");

	if (name == NULL || fd == NULL)
		err_handler(2, name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number, fmt = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buff, &len, fd) != -1; line_number++)
	{
		fmt = parse_line(buff, line_number, fmt);
	}
	free(buff);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @line_number: line number
 * @fmt:  storage fmt. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buff, int line_number, int fmt)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buff == NULL)
		err_handler(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (fmt);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, line_number, fmt);
	return (fmt);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @fmt:  storage fmt. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *val, int ln, int fmt)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap},
		{"add", add_nodes},
		{"sub", subtract_nodes},
		{"div", divide_nodes},
		{"mul", multiply_nodes},
		{"mod", mod_nodes},
		{"pchar", printc},
		{"pstr", prints},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, val, ln, fmt);
			flag = 0;
		}
	}
	if (flag == 1)
		err_handler(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @val: string representing a numeric val.
 * @ln: line numeber for the instruction.
 * @fmt: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *opcode, char *val, int ln, int fmt)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err_handler(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_handler(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (fmt == 0)
			func(&node, ln);
		if (fmt == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
