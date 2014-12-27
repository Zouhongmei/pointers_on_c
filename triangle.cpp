/* 输入三角形的三边长，判断三角形形状 */

#include <stdio.h>

int 
main()
{
	int a, b, c;
	
	// 输入三角形的三边长
	scanf( "%d%d%d", &a, &b, &c );
	
	// 判断是否能组成三角形
	if( a + b > c && b + c > a && a + c > b )
	{
		// 判断三角形形状
		if( a == b )
		{
			if( b == c )
				printf( "equilateral triangle\n" );
			else
				printf( "isosceles triangle\n" );
		} else {
			if( a == c || b == c )
				printf( "isosceles triangle\n" );
			else
				printf( "scalene triangle\n" );
		}
	} else 
		printf( "can't form a triangle\n" );
	
	return 0;
}