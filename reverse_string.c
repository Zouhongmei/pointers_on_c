#include <stdio.h>

/*
** 将字符串的字符反向排列
** 不使用数组下标
** 不使用字符操作库函数
** 不用新的数组临时存储参数
*/
void 
reverse_string( char *string )
{
	char *s_head = string; // s_head指向第一个字符
	char *s_end = string; 
	char temp;
	
	/*
	** 将s_end指向最后一个字符，'\0'前面一个
	*/
	while( *s_end++ != '\0' )
		;
	s_end -= 2;
	
	/*
	** 交换字符
	*/
	while( s_head < s_end )
	{
		temp = *s_head;
		*s_head = *s_end;
		*s_end = temp;
		s_head ++;
		s_end --;
	}
}

int 
main()
{
	char str[] = "ABCDEFGH";
	
	reverse_string( str );
	
	puts( str );
}