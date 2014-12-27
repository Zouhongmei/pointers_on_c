/*
** 八皇后问题
*/

#include <stdio.h>
#define  TRUE  1
#define  FALSE 0

/*
** 棋盘，8*8的二维矩阵，为全局变量
** 将有皇后的地方设置为TRUE
** FALSE，则没有皇后
*/
int chessboard[8][8] = { 0 };

int conflict( int row, int col );
void print_board();
void place_queen( int row );

int main()
{
	place_queen( 0 );
	return 0;
}

/*
** 函数功能：
**     给定某一行，在该行的每一列上放置皇后，检查是否相互攻击
*/
void 
place_queen( int row )
{
	int col;
	
	/*
	** 尝试在该行的每一列上放置皇后
	*/
	for( col = 0; col < 8; ++ col )
	{
		chessboard[ row ][ col ] = TRUE;
		
		/*
		** 检查放上的皇后是否与其他皇后冲突
		** 第1行的皇后是第1个放置的，肯定不与其他冲突
		** 第1行和第2~7行刚放上的皇后不与其他冲突时，用递归放置下一个皇后
		** 第8行放上的皇后不与其他冲突时，打印答案
		*/
		if( row == 0 || !conflict( row, col ) )
		{
			if( row < 7 )
				place_queen( row + 1 );
			else
				print_board();
		}
		
		// 当前位置放上皇后与其他冲突时，将该位置重置为FALSE
		chessboard[ row ][ col ] = FALSE;
	}
}

/*
** 函数功能：
**     检查在棋盘某个位置放上皇后是否与其他皇后冲突
**   说明：
**     由于是一行一行从上往下放置皇后的，只需要检查
**     当前位置之前的皇后，当前位置之后还没有放置皇后
** 函数返回：
**     有冲突，返回TRUE；无冲突，返回FALSE
*/
int
conflict( int row, int col )
{
	int i;
	for( i = 1; i < 8; ++ i )
	{
		// 检查当前棋子的上方直线上是否有皇后
		if( row - i >= 0 && chessboard[ row - i ][ col ] )
			return TRUE;
			
		// 检查当前棋子的左侧直线上是否有皇后
		if( col - i >= 0 && chessboard[ row ][ col - i ] )
			return TRUE;
			
		// 检查当前棋子的右侧直线上是否有皇后
		if( col + i < 8 && chessboard[ row ][ col + i ] )
			return TRUE;
			
		// 检查当前棋子左上角对角线上是否有皇后
		if( row - i >= 0 && col - i >= 0 
			&& chessboard[ row - i ][ col - i ] )
				return TRUE;
				
		// 检查当前棋子右上角对角线上是否有皇后
		if( row - i >= 0 && col + i < 8 
			&& chessboard[ row - i ][ col + i ] )
				return TRUE;		
	}
	
	// 执行到这里说明没有冲突，返回FALSE
	return FALSE;
}

/*
** 函数功能：
**     打印棋盘
*/
void
print_board()
{
	int row;
	int col;
	static int solution_count;  // 静态变量，计算第几个答案
	solution_count ++;
	printf( "Solution %d:\n", solution_count );
	
	/*
	** 遍历棋盘，并打印
	*/
	for( row = 0; row < 8; ++ row )
	{
		for( col = 0; col < 8; ++ col )
		{
			if( chessboard[ row ][ col ] )
				printf( " Q" );
			else
				printf( " +" );
		}
		putchar( '\n' );
	}
	putchar( '\n' );
}