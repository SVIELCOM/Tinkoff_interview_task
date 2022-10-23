#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_DEPTH 10
#define MAX_FOLDER_NAME_LENGHT 20
#define MAX_INPUT_STRING_LENGHT 100

// function declaration
int push(char stack[MAX_STACK_DEPTH][MAX_FOLDER_NAME_LENGHT], int *top, char data[MAX_FOLDER_NAME_LENGHT]);
int pop(char stack[MAX_STACK_DEPTH][MAX_FOLDER_NAME_LENGHT], int *top, char data[MAX_FOLDER_NAME_LENGHT]);

int main()
{
	char stack[MAX_STACK_DEPTH][MAX_FOLDER_NAME_LENGHT];
	char io_string[MAX_INPUT_STRING_LENGHT];
	char delim[] = "/";
	char double_dots[] = "..";
	char one_dot[] = ".";
	char temp_data[MAX_FOLDER_NAME_LENGHT];

	int top;
	top = -1; // Initialize Stack

	printf("\nEnter string : ");
	scanf("%s", io_string);
	printf("\nEntered string is: %s\n", io_string);
	char *token = strtok(io_string, delim); // the first token
	while (token != NULL)
	{
		printf("Next token is %s\n", token);
		if (!strcmp(token, double_dots))
		{
			pop(stack, &top, temp_data);
			printf("Poped %s\n", temp_data);
		}
		else if (strcmp(token, one_dot))
		{
			push(stack, &top, token);
			printf("Pushed %s\n", token);
		}

		token = strtok(NULL, delim); // next token
	}
	printf("Output string is: ");
	for (int i = 0; i <= top; i++)
	{
		//printf("/");
		printf("/%s", stack[i]);
	}
	printf("\n");
	return 0;
}

int push(char stack[MAX_STACK_DEPTH][MAX_FOLDER_NAME_LENGHT], int *top, char data[MAX_FOLDER_NAME_LENGHT])
{
	if (*top == MAX_STACK_DEPTH - 1)
		return (-1);
	else
	{
		*top = *top + 1;
		strcpy(stack[*top], data);
		return (1);
	}
}
int pop(char stack[MAX_STACK_DEPTH][MAX_FOLDER_NAME_LENGHT], int *top, char data[MAX_FOLDER_NAME_LENGHT])
{
	if (*top == -1)
		return (-1);
	else
	{
		strcpy(data, stack[*top]);
		*top = *top - 1;
		return (1);
	}
}
