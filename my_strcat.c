/*
** 2014-12-15, by ZHM
** 不会溢出目标数组的 my_strcat 函数
*/

#include <stdio.h>
#include <string.h>

/*
** my_strcat
**   函数功能：
**       类似strcat函数，不会溢出目标数组
**   函数参数：
**       dst：目标字符串数组
**       src：要连接到dst后面的字符串数组
**       dst_size：目标字符串dst数组的长度
**   函数返回：
**       指向目标字符串dst的指针
*/
char *
my_strcat( char *dst, char *src, int dst_size )
{
	char *rslt = dst;
	int len1 = 0;
	
	/*
	** 计算dst中原来字符串的长度
	** 找到dst中原来字符串的NUL字节位置
	*/
	while( *dst++ != '\0' )
		len1 ++;
	dst --;	
	
	/*
	** 将src字符串连接到dst的末尾
	*/
	int i;
	for( i = len1; i < dst_size; ++ i )
	{
		*dst++ = *src;
		if( *src == '\0' )
			break;
		src ++;
	}
	
	/*
	** 最后补上NUL字节
	*/
	if( i == dst_size )
		*( dst - 1 ) = '\0';
	
	return rslt;
}

int
main()
{
	char s1[10], s2[20];
	gets( s1 );
	gets( s2 );
	
	my_strcat( s1, s2, 10 );
	
	puts( s1 );
	
	return 0;
}