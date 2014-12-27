/*
** 查找任意数目的整型参数中的最大值
*/

#include <stdio.h>
/*
** 要实现可变参数列表，需要包含stdarg.h文件
** stdarg.h中声明了va_list, va_start, va_arg 和 va_end
*/
#include <stdarg.h>

int max_list( int n, ... );

int 
main()
{
	printf( "%d", max_list( 10, 23, 89, 56, 83, 91, 100, -1) );
}

/*
** 接受任意个正整数，返回最大值
** 参数列表必须以负值结尾，提示列表的结束
*/
int 
max_list( int n, ... )
{
	va_list val;
	int max = 0;
	int i;
	int current;
	
	/*
	** 准备访问可变参数
	*/
	va_start( val, n );
	
	/*
	** 取出可变列表中的值
	** 负值提示列表结束
	*/
	while( ( current = va_arg( val, int ) ) >= 0 )
	{	
		if( max < current )
			max = current;
	}
	
	/*
	** 完成处理可变列表
	*/
	va_end( val );
	
	return max;
}