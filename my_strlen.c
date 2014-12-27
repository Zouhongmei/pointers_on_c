/*
** 2014-12-15, by ZHM
** my_strlen 函数类似于strlen函数
** 它能够处理由于strn---函数而创建的未以NUL字节结尾的字符串。
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/*
** my_strlen
**   函数功能：
**       计算字符串长度，包括未以NUL结尾的字符串
**   函数参数：
**       string：要计算长度的字符串
**       size：需要进行长度测试的字符串数组的长度
**   函数返回：
**       如果size长度内包含'\0'字符，返回'\0'前面的字符串的长度
**       如果size长度内不包含'\0'字符，返回size的长度
*/
size_t 
my_strlen( char const *string, int size )
{
	register size_t length;
	
	for( length = 0; length < size; ++ length )
	{
		if( *string++ == '\0' )  // 遇到'\0'，后面的字符忽略不计
			break;
	}
	return length;
}

int
main()
{
	char s1[100], s2[100];
	gets( s1 );
	int n;
	scanf( "%d", &n );
	
	strncpy( s2, s1, n );
	
	printf( "%d", my_strlen( s2, n ) );
	
	return 0;
}