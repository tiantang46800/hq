#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	int ret = -1;
	struct tm * tim = NULL;
	char *str_time = "%d  %d-%d-%d %d:%d:%d\n";
	char buf[strlen(str_time)];
	FILE *fp = NULL;
	time_t tt  = 0;
	int i = 0;
	int sek = 0;
	char *mem = NULL;
	int num_sek ;
	fp = fopen("test.txt","r");
	if(fp != NULL )
	{

		ret = fseek(fp,0,SEEK_END);
		if( 0 != sek )
		{
			perror("fseek");
			return -1;
		}
		sek = ftell(fp);
		mem = malloc(sek);
		if(NULL == mem )
		{
			perror("malloc");
			return -1;
		}
		memset(mem,'\0',sek);
		rewind(fp);
		ret = fread(mem,1,sek,fp);
		if ( ret != sek )
		{
			perror("fread");
			return -1;
		}
		num_sek = 2;
		while(1)
		{
			if('\n' == mem[sek-num_sek])
				break;
			num_sek++;
		}
		i = mem[sek-num_sek+1]-'0';
		fclose(fp);
	}else
		i=1;
	fp = fopen("test.txt","a");
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
		sprintf(buf,str_time,i,1900+tim->tm_year,1+tim->tm_mon,tim->tm_mday,tim->tm_hour,tim->tm_min,tim->tm_sec);
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
		i++;
		sleep(1);
		fflush(fp);
	}
	fclose(fp);
}
