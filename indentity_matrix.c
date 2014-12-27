/*
** 判断一个10*10的矩阵是否为单位矩阵
*/

#include <stdio.h>
#define  ROW  10
#define  COL  10

/*
** 函数接受一个10*10的矩阵
** 判断其是否为单位矩阵
** 返回值：
**      是单位矩阵，返回1
**      不是单位矩阵，返回0
*/
int 
indentity_matrix( int (*matrix) [10] )
{
	int row, col;
	for( row = 0; row < ROW; ++ row )
		for( col = 0; col < COL; ++ col )
		{
			// 如果对角线上出现不是1的数，返回0
			if( col == row && matrix[row][col] != 1 )
				return 0;
			// 如果其余位置出现不是0的数，返回0
			if( col != row && matrix[row][col] != 0 )
				return 0;
			/*
			** 上面两个if语句可合并成以下形式：
			** if( matrix[ row ][ col ] != ( row == col ) )
			**     return 0;
			*/
		}
	
	// 能够执行到这里，说明是单位矩阵，返回1
	return 1;
}

int 
main()
{
	int m[ROW][COL];
	int i, j;
	
	for( i = 0; i < ROW; ++ i )
		for( j = 0; j < COL; ++ j )
			scanf( "%d", *( m + i ) + j );
	
	printf( "%d", indentity_matrix( m ) );
	
	return 0;
}