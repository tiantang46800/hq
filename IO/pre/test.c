#include <stdio.h>
#include <unistd.h>
int main(int argc,char **argv)
{
	int i=0;
	i=0;
	while(1)
	{
		printf("%10d",i);
		i++;
		usleep(8000);
	}
	return 0;
}
