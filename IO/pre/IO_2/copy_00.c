#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
/*
 * 作用拷贝
 * 使用方式$./copy 源文件  目的文件
 * */
#define TYPE_BUF char
int main(int argc,char **argv)
{
	// argv[1] source file
	// argv[2] dst    file
	FILE *src_file = NULL;
	FILE *dst_file = NULL;

	src_file = fopen(argv[1],"r");
	if(NULL == src_file )
	{
		printf("%d\n",errno);
		return -1;
	}
	dst_file = fopen(argv[2],"w");
	if(NULL == dst_file )
	{
		printf("%d\n",errno);
		return -1;
	}
	TYPE_BUF buf[10];
	int num = 0;
	int new_num = 0;
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		num = fread(buf,sizeof(TYPE_BUF),sizeof(buf)/sizeof(TYPE_BUF),src_file);
		if(num < sizeof(buf))
		{
			if(0 != feof(src_file))
			{
				printf(" e o f\n");
				fclose(src_file);
				fclose(dst_file);
				return 0;
			}else{
				printf("err\n");
				fclose(src_file);
				fclose(dst_file);
				return 0;
			}

		}
		new_num = fwrite(buf,sizeof(TYPE_BUF),num,dst_file);
		if(new_num<num)
		{
			printf("err\n");
			fclose(src_file);
			fclose(dst_file);
			return 0;
		}
	}
	printf("ok!!!\n");
	fclose(src_file);
	fclose(dst_file);
	return 0;
}
