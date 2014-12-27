/*
** 判断一个矩阵是否为单位矩阵
** 矩阵为任意大小
*/

#include <stdio.h>
#define  SIZE 4

/*
** 函数接受任意大小矩阵参数，判断它是否为单位矩阵
** 形参：
**      第1个参数为一个整型指针，指向矩阵中第一个元素&matric[0][0]
**      第2个参数为矩阵的大小
** 返回：
**      是单位矩阵，返回1
**      不是单位矩阵，返回0
*/
int 
indentity_matrix_anysize( int *matrix, int mtx_size )
{
	int row, col;
	for( row = 0; row < mtx_size; ++ row )
		for( col = 0; col < mtx_size; ++ col )
		{
			if( row == col && *( matrix + row * mtx_size + col ) != 1 )
				return 0;
			if( row != col && *( matrix + row * mtx_size + col ) != 0 )
				return 0;
		}
	return 1;
}

int
main()
{
	int matrix[SIZE][SIZE];
	
	int i, j;
	for( i = 0; i < SIZE; ++ i )
		for( j = 0; j < SIZE; ++ j )
			scanf( "%d", & matrix[i][j] );
	
	printf( "%d", indentity_matrix_anysize( matrix[0], SIZE ) );
	
	return 0;
}