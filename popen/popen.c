#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_system_output(char *cmd, char *output, int size)
{
    FILE *fp=NULL;
    fp = popen(cmd, "r");
    if (fp)
    {
        if(fgets(output, size, fp) != NULL)
        {
            if(output[strlen(output)-1] == '\n')
                output[strlen(output)-1] = '\0';
        }
        pclose(fp);
    }
    return 0;
}

int main()
{
	char output[1024]={0};
	get_system_output("lspci | grep Ethernet", output, 1024);
	printf("the result: %s\n", output);
}
