#include <stdio.h>
#include <string.h>
#include <time.h>
int main(int argc,char **argv)
{
	struct tm * tim = NULL;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	if(NULL == tim )
	{
		perror("localtime");
		return -1;
	}
	char *str_time = "%d  %d-%d-%d %d:%d:%d\n";
	char buf[strlen(str_time)];
	memset(buf,'\0',sizeof(buf));
	sprintf(buf,str_time,1,1900+tim->tm_year,1+tim->tm_mon,tim->tm_mday,tim->tm_hour,tim->tm_min,tim->tm_sec);
	printf("%s",buf);

}
