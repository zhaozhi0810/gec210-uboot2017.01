/* 在BL0阶段，Irom内固化的代码读取nandflash或SD卡前16K的内容，
 * 并比对前16字节中的校验和是否正确，正确则继续，错误则停止。
 
 zhao  20170820 修改，可以适应大文件，但是只计算大文件的头16k字节的校验和
       相当于文件拷贝，并添加一个16字节的头信息
 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE                 (16*1024)
#define IMG_SIZE                (16*1024)
#define SPL_HEADER_SIZE         16
#define SPL_HEADER              "S5PC110 HEADER  "

int main (int argc, char *argv[])
{
	FILE		*fp;
	char		*Buf, *a;
	int		BufLen;
	int		nbytes, fileLen;
	unsigned int	checksum, count;
	int		i;
	
	// 1. 3个参数
	if (argc != 3)
	{
        printf("This is add 16bytes header for s5pv210 bin file application\n");
		printf("Usage: %s <source file> <destination file>\n",argv[0]);
		return -1;
	}



	// 3. 读源bin到buffer
	// 3.1 打开源bin
	fp = fopen(argv[1], "rb");
	if( fp == NULL)
	{
		printf("source file open error\n");
		free(Buf);
		return -1;
	}
	// 3.2 获取源bin长度
	fseek(fp, 0L, SEEK_END);
	fileLen = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	
	
	// 3.3 源bin长度不得超过16K-16byte
	count = (fileLen < (IMG_SIZE - SPL_HEADER_SIZE))
		? fileLen : (IMG_SIZE - SPL_HEADER_SIZE);
	

	// 2. 分配文件长度+16的buffer

	Buf = (char *)malloc(fileLen+16);
	if (!Buf)
	{
		printf("Alloc buffer failed!\n");
		return -1;
	}

	memset(Buf, 0x00, fileLen+16);

	
	
	// 3.4 buffer[0~15]存放"S5PC110 HEADER  "
//	memcpy(&Buf[0], SPL_HEADER, SPL_HEADER_SIZE);



	// 3.5 读源bin到buffer[16]，读取文件大小的长度
	nbytes = fread(Buf + SPL_HEADER_SIZE, 1, fileLen, fp);
	if ( nbytes != fileLen )
	{
		printf("source file read error\n");
		free(Buf);
		fclose(fp);
		return -1;
	}
	fclose(fp);

	// 4. 计算校验和，只计算前16k-16的校验和
 	// 4.1 从第16byte开始统计buffer中共有几个1
	a = Buf + SPL_HEADER_SIZE;
	for(i = 0, checksum = 0; i < count; i++)
		checksum += (0x000000FF) & *a++;
	// 4.2 将校验和保存在buffer[8~15]


	a = Buf + 8;
	*( (unsigned int *)a ) = checksum;
	a = Buf;
	*( (unsigned int *)a ) = count+16;

	// 5. 拷贝buffer中的内容到目的bin
	// 5.1 打开目的bin
	fp = fopen(argv[2], "wb");
	if (fp == NULL)
	{
		printf("destination file open error\n");
		free(Buf);
		return -1;
	}
	// 5.2 将16k的buffer拷贝到目的bin中
	a = Buf;
	nbytes	= fwrite( a, 1, fileLen+16, fp);
	if ( nbytes != fileLen+16 )
	{
		printf("destination file write error\n");
		free(Buf);
		fclose(fp);
		return -1;
	}

	free(Buf);
	fclose(fp);

	return 0;
}
