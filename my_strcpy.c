/*
** 2014-12-15, by ZHM
** 不会溢出目标数组的my_strcpy函数
*/
#include <stdio.h>
#include <string.h>

/*
** my_strcpy
**   函数功能：
**       类似strcpy函数，不会溢出目标数组
**       如果src的长度大于dst_size，则只复制dst_size-1个字符，
**       并在数组的最后一个位置加上'\0'
**   函数参数：
**       dst：目标字符串数组
**       src：要复制的字符串数组
**       dst_size：目标字符串dst的长度
**   函数返回：
**       指向目标字符串的指针。
*/
char *
my_strcpy( char *dst, char *src, int dst_size )
{
	int i;
	char *rslt = dst;
	
	for( i = 0; i < dst_size; ++ i )
	{
		*dst++ = *src;
		if( *src == '\0' )
			break;
		src ++;
	}
	
	if( i == dst_size )
		* ( dst - 1 ) = '\0';
	
	return rslt;
}

int
main()
{
	char s1[20], s2[11];
	gets( s1 );
	
	my_strcpy( s2, s1, 11 );
	
	puts( s2 );
	
	return 0;
}