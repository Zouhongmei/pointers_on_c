/*
** 求两个整数的最大公约数
*/

#include <stdio.h>

int gcd( int M, int N );

int 
main()
{
	int m, n;
	scanf( "%d%d", &m, &n );
	printf( "%d", gcd( m, n ) );
	return 0;
}

/*
** 求两个整数的最大公约数
** 如果两个参数中任一个数不大于0，函数返回0
*/
int 
gcd( int M, int N )
{
	int R, t;
	
	/*
	** 如果M，N任一个数不大于0，函数返回0
	*/
	if( M <= 0 || N <= 0 )
		return 0;
	
	/*
	** 保证M>=N
	** 这部分多余了感谢@garbageMan的指正
	if( M < N )
	{	
		t = M;
		M = N;
		N = t;
	}
	*/
	
	/*
	** 求最大公约数
	*/
	while( ( R = M % N ) > 0 )
	{
		M = N;
		N = R;
	}
	
	return N;
}