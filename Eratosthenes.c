/*
** 用Eratosthenes筛选法输出质数
*/
#include <stdio.h>

void Eratosthenes( char *mark, int len );

int 
main()
{
	char mark[2000];
	int i;
	
	/*
	** 将数组所有元素设置成'1'
	*/
	for( i = 0; i < 2000; ++i )
		*( mark + i ) = '1';
	
	Eratosthenes( mark, 2000 );
	
	/*
	** 下标0对应的质数是2，直接输出
	*/
	printf( "%d ", 2 );
	int c = 1; // c用来计算输出个数，控制每输出10个换行 
	
	for( i = 1; i < 2000; ++ i )
	{
		if( *( mark + i ) == '1' )
		{
			printf( "%d ", 2 * i + 1 ); // 数组中的元素只对应奇数，所以下标i对应2*i+1
			c ++;
			if( c % 10 == 0 )
				printf( "\n" );
			else
				printf( " " );
		}	
	}
	
	return 0;
}

/*
** Eratosthenes函数，筛选质数
*/
void 
Eratosthenes( char *mark, int len )
{	
	int i, j;
	for( i = 1; i < len; ++ i )
	{
		if( *( mark + i) == '1' )
		{
			for( j = i + 1; j < len; ++ j )
			{
				// 把2*i+1的倍数剔除，即设置为'0'
				if( ( 2 * j + 1 ) % ( 2 * i + 1) == 0 )
					*( mark + j ) = '0';
			}
		}
	}
}