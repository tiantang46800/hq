#include <stdio.h>
#include <unistd.h>
/*
 * 作用拷贝
 * 使用方式$./copy 源文件  目的文件
 * */
int main(int argc,char **argv)
{
	// argv[1] source file
	// argv[2] dst    file
	src_file = fopen(argv[1]);
	dst_file = fopen(argv[2]);
	while(1)
	{
		fread(src_file);
		fwrite(dst_file);
		if(end of file)
			break;
	}
	return 0;
}
