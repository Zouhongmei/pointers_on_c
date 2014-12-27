/*
** 2014-12-15, by ZHM
*/
#include <stdio.h>
#include <string.h>

/*
** count_chars
**   函数功能：
**       计算str字符串中包含chars字符串中任何字符的个数
**   函数返回：
**       str中匹配chars中包含的字符的数量
*/
int 
count_chars( char const *str, char const *chars )
{
	int count = 0;
	int cn;
	char *r = ( char * )str;
	/*
	** 用strspn函数找到r起始部分连续匹配chars任意字符的字符数
	** r指向下一个要查找的位置
	*/
	while( *r != '\0' )
	{
		cn = strspn( r, chars );
		if( cn != 0 )
		{
			r += cn;
			count += cn;
		}
		else
			r ++;
	}
	return count;
}

int 
main()
{
	char s1[50], s2[50];
	gets( s1 );
	gets( s2 );
	
	printf( "%d", count_chars( s1, s2 ) );
	
	return 0;
}