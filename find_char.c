/* 
** 查找所有在一个给定字符串集合中出现的字符。
** 查找 source 字符串中匹配 chars 字符串中任何字符的第 1 个字符，
** 函数返回一个指向 source 中第 1 个匹配所找到的位置的指针。
** 如果 source 中的所有字符均不匹配 chars 中的任何字符，
** 函数返回一个NULL指针。
*/

#include <stdio.h>

/*
** 函数，查找字符
*/
char 
*find_char( char const *source, char const *chars )
{
	char const *sp = source; 
	char const *cp;
	
	for( ; *sp != '\0'; sp ++ ) {
		for( cp = chars; *cp != '\0'; cp ++ ) {
			if( *sp == *cp )
				return ( char * )sp; // 将 sp 的类型转换成 char *
		}
	}
	return NULL;
}

int 
main()
{
	char *sp = "Welcome to Hangzhou";
	char *cp = "BlT";
	
	char *res = find_char( sp, cp );
	
	printf( "%s\n", res );
	
	return 0;
}