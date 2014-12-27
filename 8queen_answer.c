/*
** Solve the Eight Queens Problem.
*/
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

/*
** The chessboard. If an element is TRUE, there is a queen on that square;
** if FALSE, no queen.
*/
int board[8][8];

/*
** print_board
**
** Print out a valid solution.
*/
void
print_board()
{
	int row;
	int column;
	static int n_solutions;
	n_solutions += 1;
	printf( "Solution #%d:\n", n_solutions );
	for( row = 0; row < 8; row += 1 ){
		for( column = 0; column < 8; column += 1 ){
			if( board[ row ][ column ] )
				printf( " Q" );
			else
				printf( " +" );
		}
		putchar( '\n' );
	}
	putchar( '\n' );
}

/*
** conflicts
**
**     Check the board for conflicts with the queen that was just placed.
**     NOTE: because the queens are placed in the rows in order, there is no
**     need to look at rows below the current one as there are no queens there!
*/
int
conflicts( int row, int column )
{
	int i;
	for( i = 1; i < 8; i += 1 ){
		/*
		** Check up, left, and right. (Don’t have to check down; no
		** queens in those rows yet!)
		*/
		if( row - i >= 0 && board[ row - i ][ column ] )
			return TRUE;
		if( column - i >= 0 && board[ row ][ column - i ] )
			return TRUE;
		if( column + i < 8 && board[ row ][ column + i ] )
			return TRUE;
			
		/*
		** Check the diagonals: up and left, up and right. (Don’t have
		** to check down; no queens there yet!)
		*/
		if( row - i >= 0 && column - i >= 0
			&& board[ row - i ][ column - i ] )
				return TRUE;
		if( row - i >= 0 && column + i < 8
			&& board[ row - i ][ column + i ] )
				return TRUE;
	}
	
	/*
	** If we get this far, there were no conflicts!
	*/
	return FALSE;
}

/*
** place_queen
**
**     Try to place a queen in each column of the given row.
*/
void
place_queen( int row )
{
	int column;
	
	/*
	** Try each column, one by one.
	*/
	for( column = 0; column < 8; column += 1 ){
		board[ row ][ column ] = TRUE;
		
		/*
		** See if this queen can attack any of the others (don’t need to
		** check this for the first queen!).
		*/
		if( row == 0 || !conflicts( row, column ) )
			/*
			** No conflicts -- if we’re not yet done, place the next
			** queen recursively. If done, print the solution!
			*/
			if( row < 7 )
				place_queen( row + 1 );
			else
				print_board();
	
		/*
		** Remove the queen from this position.
		*/
		board[ row ][ column ] = FALSE;
	}
}

int
main()
{
	place_queen( 0 );
	return EXIT_SUCCESS;
}	