#include <stdio.h>

void shell_parse(char *buf);

int main(int argc, char *argv[])
{
	int i = 0;
	char buf[64];

	printf("demo how to do a Bash Clone\n");

	//scanf("%s", buf);
	//gets(buf);
	while (1)
	{
		printf("BASHCLONE# ");
		fgets(buf, 64, stdin);
		//printf("buf = %s\n", buf);
		
		shell_parse(buf);
	}

	return 0;
}
