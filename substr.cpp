/*
** 从一个字符串中提取一个子字符串
*/

#include <stdio.h>
#include <string.h>

// 函数，从一个字符串中提取一个子字符串，返回子字符串的长度
int 
substr( char dst[], char src[], int start, int len )
{
	int dlen = 0;
	
	// start的位置越过src数组的尾部，或start或len<0，dst数组为空
	if( start > strlen(src) || start < 0 || len < 0)
	{
		dst[0] = '\0';
		dlen = 0;
	} 
	else {
		for( int i = 0; i < len; ++ i ) // 复制子字符串
		{
			if( src[ i + start ] != '\0' )
			{
				dst[i] = src[ i + start ];
				dlen ++;
			}
			else 
				break;
		}
	}
	dst[dlen+1] = '\0';
	
	// 返回dst数值中字符串的长度
	return dlen;
}

int 
main()
{
	char src[100] = {"abcdefghijklmnopqrstuvwxyz"};
	char dst[100];
	int l;
	
	l = substr( dst, src, 27, 10 );
	printf( "%d\n%s", l, dst );
	
	return 0;
}