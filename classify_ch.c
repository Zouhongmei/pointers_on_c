/*
** 从标准输入读取一些字符，统计下列各类字符所占的百分比。
** 控制字符、空白字符、数字、小写字母、大写字母、标点符号
** 不可打印字符
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
main()
{
	char ch;
	int ch_cnt = 0;      // 统计所有字符的个数
	int cntrl_cnt = 0;   // 统计控制字符的个数
	int space_cnt = 0;   // 统计空白字符的个数
	int digit_cnt = 0;   // 统计数字字符的个数
	int lower_cnt = 0;   // 统计小写字母的个数
	int upper_cnt = 0;   // 统计大写字母的个数
	int punt_cnt = 0;    // 统计标点符号的个数
	int unprint_cnt = 0; // 统计不可打印字符的个数
	
	/*
	** 逐个读取字符，直到遇到EOF结束，并统计各类字符的个数
	*/
	while( ( ch = getchar() ) != EOF )
	{
		ch_cnt ++;
		if( iscntrl( ch ) )
			cntrl_cnt ++;
		if( isspace( ch ) )
			space_cnt ++;
		if( isdigit( ch ) )
			digit_cnt ++;
		if( islower( ch ) )
			lower_cnt ++;
		if( isupper( ch ) )
			upper_cnt ++;
		if( ispunct( ch ) )
			punt_cnt ++;
		if( !isprint( ch ) )
			unprint_cnt ++;
	}
	
	/*
	** 按照 xx.xx% 的格式打印出各类字符所占的百分比
	*/
	printf( "Control character: %.2f%%\n", ( double )cntrl_cnt / ( double )ch_cnt * 100 );
	printf( "Space character: %.2f%%\n", ( double )space_cnt / ( double )ch_cnt * 100 );
	printf( "Digit character: %.2f%%\n", ( double )digit_cnt / ( double )ch_cnt * 100 );
	printf( "Lower character: %.2f%%\n", ( double )lower_cnt / ( double )ch_cnt * 100 );
	printf( "Upper character: %.2f%%\n", ( double )upper_cnt / ( double )ch_cnt * 100 );
	printf( "Punctuation character: %.2f%%\n", ( double )punt_cnt / ( double )ch_cnt * 100 );
	printf( "Unprintable character: %.2f%%\n", ( double )unprint_cnt / ( double )ch_cnt * 100 );
	
	return 0;
}