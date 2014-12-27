/*
** 2014-12-15, by ZHM
** 指向目标数组末尾的strcpy函数
*/
#include <stdio.h>
#include <string.h>

/*
** my_strcpy_end
**   函数功能：
**       将src字符串复制到dst字符串数组中，返回
**       目标字符串末尾的指针，即指向NUL字节的指针
*/
char *
my_strcpy_end( char *dst, char *src )
{
	while( *src != '\0' )
		*dst++ = *src++;
	return dst;
}

int
main()
{
	char s1[100], s2[100];
	gets( s1 );
	char *r = my_strcpy_end( s2, s1 );
	int i;
	for( i = 1; i <= strlen( s2 ); ++ i )
		putchar( *( r - i ) );
	return 0;
}