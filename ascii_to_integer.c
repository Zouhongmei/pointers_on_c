/*
** 把数字字符串转化为整数
*/

#include <stdio.h>

int ascii_to_integer( char *string );

int 
main()
{
	char string[100];
	gets( string );
	printf( "%d", ascii_to_integer( string ) );
	return 0;
}

/*
** 字符串包含一个或多个数字，函数把数字
** 字符转换为整数，并返回整数。
** 如果字符串中包含非数字字符，函数返回0
*/
int 
ascii_to_integer( char *string )
{
	char *sp = string;
	int result = 0;
	
	while( *sp != '\0' )
	{
		/*
		** 如果字符串中包含非数字字符，函数返回0
		*/
		if( *sp < '0' || *sp > '9' )
			return 0;
		/*
		** 把当前值乘以10后加上新转化的数字
		*/
		result = result * 10 + *sp - '0';
		
		sp ++;
	}
	
	return result;
}