/*
** 计算Hermite Polynomials(厄密多项式)的值
*/

#include <stdio.h>

int hermite( int n, int x );

int 
main()
{
	int n, x;
	scanf( "%d%d", &n, &x );
	printf( "%d", hermite( n, x ) );
	return 0;
}

/*
** 计算厄密多项式的值，递归函数版本
*/
int 
hermite( int n, int x )
{
	int result;
	
	if( n <= 0 )
		result = 1;
	else {
		if( n == 1 )
			result = 2 * x;
		else
			result = 2 * x * hermite( n - 1, x ) 
				- 2 * ( n - 1 ) * hermite( n - 2, x );
	}		
	return result;
}