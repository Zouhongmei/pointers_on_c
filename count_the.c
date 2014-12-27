/*
** 2014-12-16，by ZHM
** 计算字符串中单词“the”的个数
*/
#include <stdio.h>
#include <string.h>

/*
** count_the
**   函数功能：
**       在str字符串中扫描，对单词“the”出现的次数进行计数。
**       区分大小写，“The”和“THE”不计算在内。
**       各单词由一个或多个空格字符分隔。
**   函数返回：
**       函数无返回值，计算个数直接写到标准输出上。
*/
void 
count_the( char *str )
{
	static char whitespace[] = " \t\f\r\v\n"; 
	int count = 0; // count计算the的个数
	char *word; // 分割出来的单词
	
	/*
	** 用strtok函数将str字符串分割成一个个单词
	** 将每个单词与the进行比较，相等则计数加1
	*/
	for( word = strtok( str, whitespace ); word != NULL;
			word = strtok( NULL, whitespace ) )
	{
		if( strcmp( word, "the" ) == 0 )
			count ++;
	}
	
	printf( "%d", count ); // 打印结果。
}

int
main()
{
	char str[101];
	gets( str );
	count_the( str );
	return 0;
}