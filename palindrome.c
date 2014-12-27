/*
** 2014-12-16, by ZHM
** 判断回文
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define  TRUE  1
#define  FALSE 0

/*
** palindrome
**   函数功能：
**       判断string字符串是否是回文，
**       忽略所有非字母字符，不区分大小写
**   函数返回：
**       是回文，返回TRUE
**       不是回文，返回FALSE
*/
int 
palindrome( char *string )
{
	char *head = string; // head从第一个字符向后遍历
	char *end = string + strlen( string ) - 1; // end从最后一个字符向前遍历
	char h, e; // h表示head指向的字符，e表示end指向的字符，用tolower全部转换为小写字母
	
	/*
	** 判断回文
	** 将字母字符前后依次进行比较，直到end<=head结束循环
	*/
	while( end-- > head++ )
	{
		if( isalpha( h = tolower( *head ) ) )
		{
			if( isalpha( e = tolower( *end ) ) )
			{
				if( h != e ) // 如果h和e都是字母，h!=e，则不是回文，返回FALSE
					return FALSE;
			} else
				end --; // 如果e不是字母，end指向前一个字符
		} else
			head ++; // 如果h不是字母，head指向后一个字符
	}
	
	/*
	** 如果执行到这一步，说明string是回文，返回TRUE
	*/
	return TRUE;
}

int
main()
{
	char str[100];
	gets( str );
	if( palindrome( str ) )
		printf( "TRUE\n" );
	else
		printf( "FALSE\n" );
	
	return 0;
}