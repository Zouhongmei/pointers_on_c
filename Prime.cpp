/* 打印1~100之间的所有质数 */

#include <stdio.h>
#include <math.h>

// 函数，判断是否是质数
int 
Isprime( int n )
{
	if( n == 1 )
		return 0;
	else
		for( int i = 2; i < sqrt( n ); ++ i )
		{
			if( n % i == 0 )
				return 0;
		}
	
	return 1;
}

int 
main()
{
	// 打印1~100之间的所有质数
	for( int i = 1; i <= 100; ++i )
	{
		if( Isprime( i ) )
			printf( "%d ", i );
	}
	
	return 0;
}