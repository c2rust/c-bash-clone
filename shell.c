#include <stdio.h>
#include <string.h>

int echo_main(int argc, char** argv)
{
  printf("echo argc = %d", argc);
  if (argc > 1)
    printf("echo argv[1] = %s\n", argv[1]);
  return 0;
}

struct operation
{
	char name[8];
	int (*pf)(int, char **);
} op[] =
{
	{ "echo", echo_main },
	// add more opeation here
};

int command_do(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < sizeof(op)/sizeof(op[0]); i++)
	{
		if (strcmp(argv[0], op[i].name) == 0)
		{
			op[i].pf(argc, argv);
			break;
		}
	}

	return 0;
}

void shell_parse(char *buf)
{
	int argc;
	char *argv[8];
	int state = 0;
	int i = 0;

	argc = 0;
	// parse buf	
	while (*buf)
	{
		char c = *buf;
		if(c == ' ' && state == 0)	// "   add 100"
			state = 0;
		else
		if(c != ' ' && state == 0)	// "add 100"
		{
			argv[argc++] = buf;
			state = 1;
		}
		else
		if(c == ' ' && state == 1)	// "a dd 100"
		{
			*buf = '\0';
			state = 0;
		}
		else
		if(c != ' ' && state == 1)	// "add 100"
		{
			state = 1;
		}
		buf++;
		if (*buf == '\n')
			*buf = '\0';
	}

	argv[argc] = NULL;
#if 0
	printf("argc = %d\n", argc);
	for (i = 0; i <= argc; i++)
		printf("argv[%d] : %s\n", i, argv[i]);
#endif
	command_do(argc, argv);
}
