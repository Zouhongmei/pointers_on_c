#include <stdio.h>

void copy_n( char dst[], char src[], int n )
{
	int i;
	for( i = 0; i < n && src[i] != '\0'; ++i )
	{
		dst[i] = src[i];
	}

	for( ; i < n; ++ i )
	{
		dst[i] = '\0';
	}
}

int 
main()
{
	char src[100], dst[100];
	gets( src );
	copy_n( dst, src, 10 );
	
	for( int i = 0; i < 10; ++ i )
		printf( "%c", dst[i] );
		
	return 0;
}