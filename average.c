/*
** 用可变参数求平均值
*/

#include <stdio.h>
#include <stdarg.h>

float
average( int n, ... )
{
	/*
	** a用于访问参数列表的不确定部分
	*/
	va_list a;
	int i;
	float sum = 0;
	
	/*
	** 开始访问可变参数
	*/
	va_start( a, n );
	
	/*
	** 用va_arg宏取可变参数列表的值，加到sum中
	*/
	for( i = 0; i < n; ++i )
	{
		sum += va_arg( a, int );
	}
	
	/*
	** 用va_end完成处理可变参数
	*/
	va_end( a );
	
	return sum / n;
}

int
main()
{
	float avg = average( 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 );
	
	printf( "%f", avg );
	
	return 0;
}