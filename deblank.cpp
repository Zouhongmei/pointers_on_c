/*
** 从一个字符串中删除多余的空格
*/

#include <stdio.h>

void
deblank( char string[] )
{
	int i = 0; // i：控制输出的下标
	int j = 0; // j：遍历字符串的下标
	int n_blank = 0; // 记录空格个数
	
	// 删除开头的空格
	while( string[j] == ' ' )
	{
		j ++;
	}
	
	// 删除中间和尾部多余的空格
	while( string[j] != '\0' )
	{
		if( string[j] != ' ' ) 
		{
			n_blank = 0;
			
			// 把 j 位置的字符复制到 i 的位置，同时 j 的位置替换成空格
			if( i != j ) {
				string[i] = string[j];
				string[j] = ' ';
			}
			i ++;
			j ++;
			continue;
		}
		else {
			n_blank ++;
			// 如果空格个数大于1，则i的位置不变，j+1一直到不是空格为止
			if( n_blank > 1 ){
				j ++;
				continue;
			}
			else {
				i ++;
				j ++;	
			}
		}
	}
	
	string[i-1] = '\0';
}

int 
main()
{
	char str[100];
	gets( str );
	
	deblank( str );
	
	puts( str );
	
	return 0;
}