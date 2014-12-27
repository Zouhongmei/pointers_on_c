/*
** 实现一个简易的printf函数
** 它能处理%d, %f, %s,%c格式码
*/

#include <stdarg.h>  //处理可变参数列表
#include <stdio.h>

int putchar( int c );
int printf_int( int i ){;}      // 假定printf_int函数用于打印int类型的值
int printf_float( float f ){;}  // 假定printf_float函数用于打印float类型的值

int my_printf( char *fmt, ... );

int 
main()
{
	my_printf( "integer test: %d\n", 134 );  // 由于printf_int函数是假定的，实际不能打印数值
	my_printf( "float test: %f\n", 0.5 );    // 由于printf_float函数是假定的，实际不能打印数值
	my_printf( "string test: %s\n", "abcdefg" );
	my_printf( "char teat: %c\n", 'A' );
	my_printf( "%d %f %s %c\n", 100, 4.124, "ABC", 'h' );
	return 0;
}

/*
** 函数，实现简易的printf函数
*/
int
my_printf( char *fmt, ... )
{
	va_list prtf_list;
	char *fp;    // 指向fmt字符串
	char *sval;  // 要输出的字符串
	int ival;    // 要输出的整数
	float fval;  // 要输出的浮点数
	char cval;
	
	va_start( prtf_list, fmt );
	
	for( fp = fmt; *fp != '\0'; ++ fp )
	{
		/*
		** 如果没遇到%，则直接输出字符
		** 并处理下一个字符
		*/
		if( *fp != '%' )
		{
			putchar( *fp );
			continue;
		}
		
		/*
		** 如果遇到%，则看下一个字符
		** 根据格式输出
		*/
		switch( *++fp )
		{
			case 'd':
				ival = va_arg( prtf_list, int );   // 从参数列表中获取一个int类型的值
				printf_int( ival );
				break;
			case  'f':
				fval = va_arg( prtf_list, double );  // 从参数列表中获取一个float类型的值
				printf_float( fval );
				break;
			case 's':
				// 从参数列表中获取一串字符，并逐个输出
				for( sval = va_arg( prtf_list, char * ); *sval != '\0'; ++ sval )
					putchar( *sval );
				break;
			case 'c':
				cval = va_arg( prtf_list, int );    //从参数列表中获取一个字符并输出
				putchar( cval );  
				break;
			default:
				break;
		}
	}
	
	va_end( prtf_list );
	
	return ;
}