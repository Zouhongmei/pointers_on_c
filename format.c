/*
** 2014-12-19, by ZHM
*/
#include <stdio.h>
#include <string.h>
#define TRUE  1
#define FALSE 0

/*
** format
**   函数功能：
**       按照一个指定的格式字符串对一个数字字符串进行格式化
**       digit_string中的数字根据一开始在format_string中找到
**       的字符从右到左逐个复制到format_string中
**   函数返回：
**       处理后的字符串串保存在format_string中，
**       格式化过程出现错误，返回FALSE
**       格式化处理成功，返回TRUE
*/
int
format( char *format_string, char const *digit_string )
{
	/*
	** 如果digit_string或者format_string为NULL，则返回FALSE
	*/
	if( digit_string == NULL || format_string == NULL )
		return FALSE;
		
	char *pformat = format_string;
	int len = strlen( digit_string );
	int flag = 0; // flag用来标记小数点，0表示没有小数点
	int count = 0; // count用来记录'#'字符的个数
	
	/*
	** 使pformat指向format_string的NUL字节
	** 同时对format_string中的'#'字符计数
	*/
	while( *pformat++ != '\0' )
	{
		if( *( pformat - 1 ) == '#' )
			count ++;
		if( *( pformat - 1 ) == '.' )
			flag = 1; // 如果format_string字符串中有小数点，flag标记为1
	}
	pformat -= 1;
	
	/*
	** 如果数字字符串中的数字多于格式字符串中的'#'字符的个数
	** 返回FALSE
	*/
	if( len > count )
		return FALSE;
		
	char const *pdigit = digit_string + len; // pdigit指针指向数字字符串的NUL字节
	
	/*
	** 从右到左逐个处理，直到到字符串开头
	*/
	while( pformat-- != format_string )
	{
		if( pdigit != digit_string ) // 数字字符串没有到开头
		{
			if( *pformat == '#' ) // 遇到#字符
				*pformat = *--pdigit; // 数字字符复制到格式字符串中
			else if( *pformat == '.' ){  // 遇到小数点
				flag = 2;  // 将flag标记为2，数字字符不变，处理下一个格式字符
				continue;
			}
			else if( *pformat == ',' ) // 遇到','
				continue;  // 下一次循环
		} 
		else{  // 数字字符串到开头
			if( *pformat == '.' ){ // 遇到小数点
				flag = 2;  // 将flag标记为2
				*--pformat = '0'; // 小数点前一位赋值为'0'
			}
			else if( flag == 1 ) // 格式字符串中有小数点，但还没遇到小数点
				*pformat = '0';  // 小数部分加上'0'
			else if( flag == 0 || flag == 2 ) // 格式字符串中没有小数点，或者已经遇到过小数点
				*pformat = ' ';  // 剩余的赋值为' '
		}
	}
	return TRUE;  // 处理成功，返回TRUE
}

int
main()
{
	char format_str[100], digit_str[100];
	gets( format_str );
	gets( digit_str );
	if( format( format_str, digit_str ) )
		puts( format_str );
	return 0;
}