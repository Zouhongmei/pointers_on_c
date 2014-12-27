/* 
** 如果文件中有两行或更多行相邻的文本内容相同，
** 那么打印其中一行，其余行不打印。
*/

#include <stdio.h>
#include <string.h>

int 
main()
{
	char last[128], curren[128];
	int count = 1;
	
	gets( last );
	
	while( gets( curren ) != NULL )
	{
			// 如果两行相等，count++
		if( ! strcmp( curren, last ) )
			count ++;
			
			// 如果不相等，count = 1
		else
			count = 1;
		if( count == 2 )
			puts( curren );
		strcpy( last, curren );
	}
	
	return 0;
}