#include <stdio.h>
#include <string.h>
#include <time.h>
int main(int argc,char **argv)
{
	int ret = -1;
	struct tm * tim = NULL;
	char *str_time = "%d  %d-%d-%d %d:%d:%d\n";
	char buf[strlen(str_time)];
	FILE *fp = NULL;
	fp = fopen("test.txt","a+");
	time_t tt  = 0;
	while(1)
	{
		tt = time(NULL);
		tim = localtime(&tt);
		if(NULL == tim )
		{
			perror("localtime");
			return -1;
		}
		memset(buf,'\0',sizeof(buf));
		sprintf(buf,str_time,1,1900+tim->tm_year,1+tim->tm_mon,tim->tm_mday,tim->tm_hour,tim->tm_min,tim->tm_sec);
		//printf("%s",buf);
		if(NULL == fp )
		{
			perror("fopen");
			return -1;
		}
		ret = fwrite(buf,1,sizeof(buf)-1,fp);
		if( ret < (sizeof(buf)-1))
		{
			perror("fwrite");
			fclose(fp);
			return -1;
		}
		sleep(1);
	}
	fclose(fp);
}
