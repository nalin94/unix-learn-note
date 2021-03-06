#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("usage: main filename\n");
		exit(-1);
	}

	char buf[101] = {0};
	char* file_name = argv[1];//"test.txt";
	FILE* pf = fopen(file_name, "a+");
	if(pf == NULL)
	{
		printf("文件打开错误:%s\n", strerror(errno));
		exit(-1);
	}	
	size_t rc = 0;
	while(1)
	{
		size_t tmp = fread(buf, 1, sizeof(buf)-1, pf);// 每次读取1*(sizeof(buf)-1)个字节到buf
		rc += tmp;
		//printf("tmp = %d\n", tmp);
		if(tmp == 0)
		{
			break;
		}
		buf[tmp] = '\0';
		printf("%s", buf);
	}
	
	printf("一共读了%d字节\n", rc);
	fclose(pf);

	return 0;
}
