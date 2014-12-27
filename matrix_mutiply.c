/*
** 矩阵相乘
*/

#include <stdio.h>

/*
** 函数功能：将矩阵m1与m2相乘，结果保存在矩阵r中
** 函数参数：m1为x行y列的矩阵，m2为y行z列的矩阵，r为x行z列的矩阵
** 函数没有返回值，结果直接存储在r矩阵中
*/
void
matrix_mutiply( int *m1, int *m2, int *r, int x, int y, int z )
{
	int row, col;
	int i;
	int multp1, multp2;
	for( row = 0; row < x; ++ row )
		for( col = 0; col < z; ++ col )
		{	
			*r = 0;
			for( i = 0; i < y; ++ i )
			{
				multp1 = *( m1 + row * y + i );
				multp2 = *( m2 + i * z + col );
				*r += multp1 * multp2;
			}
			r ++;
		}
}

int 
main()
{
	int a[3][2] = { 2, -6,
					3, 5,
					1,-1};
	int b[2][4] = { 4, -2, -4, -5,
					-7, -3, 6, 7 };
	
	int c[3][4] = { 0 };
	
	matrix_mutiply( &a[0][0], &b[0][0], &c[0][0], 3, 2, 4 );
	
	int i, j;
	for( i = 0; i < 3; ++ i )
	{
		for( j = 0; j < 4; ++ j )
			printf( "%d ", c[i][j] );
		printf( "\n" );
	}
	
	return 0;
}