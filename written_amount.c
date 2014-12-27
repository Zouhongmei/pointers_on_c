/*
** 把非负整数数值转化为单词形式
** 3.0版本，在2.0的基础上改进：
**       1000000 多输出 THOUSAND 的问题
*/

#include <stdio.h>
#include <string.h>

void written_amount( unsigned int amount, char *buffer );

int 
main()
{
	unsigned int num1, num2;
	scanf( "%u%u", &num1, &num2 );
	char b1[100] = { 0 };
	char b2[100] = { 0 };
	
	written_amount( num1, b1 );
	
	puts( b1 );
	
	written_amount( num2, b2 );
	
	puts( b2 );
	
	return 0;
}

/*
** 函数功能：把amount的值转化为单词形式，结果存储在buffer中
*/
void 
written_amount( unsigned int amount, char *buffer )
{
	/*
	** 数字对应的单词，分为4组
	*/
	char word_1_9[10][6] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
							"SIX", "SEVEN", "EIGHT", "NINE" };
	char word_10_19[10][10] = {"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN",
							"SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN" };
	char word_ty[10][8] = { "", "", "TWENTY", "THIRTY", "FORTY", "FIFTY", 
							"SIXTY", "SEVENTY", "EIGHTY", "NINETY" };
	char word_div[4][9] = { "HUNDRED", "THOUSAND", "MILLION", "BILLION" };
	
	/*
	** 如果amount=0,则直接输出ZERO
	*/
	if( amount == 0 )
	{
		strcat( buffer, word_1_9[ 0 ] );
		return ;
	}
	
	/*
	** amount不等于0，用下面的方法处理
	*/
	static int count = 0;  // 记录千分位的个数
	unsigned int tmp = amount / 1000; 
	
	/*
	** 用递归函数，直到数值< 1000
	*/
	if( tmp )
	{
		count ++;  // 千分位的个数增加
		written_amount( tmp, buffer ); // 递归，处理下一个千分位
	}
	
	int val = amount % 1000; // 3位3位地进行转化单词
	
	if( val == 0 )
	{
		count = 0;
		return ;
	}
	/*
	** 值大于100，先把百位上的数的单词存到buffer中
	** 后面加上 HUNDRED
	** 把值%100，变成两位数，后续继续处理
	*/
	if( val >= 100 )
	{
		strcat( buffer, word_1_9[ val / 100 ] );
		strcat( buffer, " " );
		strcat( buffer, word_div[ 0 ] );
		val %= 100;
	}
	
	/*
	** 值在20至99之间，先把几十对应的单词加到buffer中
	** 再%10，后续处理个位上的数
	*/
	if( val >= 20 && val <= 99 )
	{
		strcat( buffer, " " );
		strcat( buffer, word_ty[ val / 10 ] );
		val %= 10;
	}
	
	/*
	** 值在10到19之间，直接把对应的单词加到buffer中
	*/
	if( val >= 10 && val <= 19 )
	{
		strcat( buffer, " " );
		strcat( buffer, word_10_19[ val % 10 ] );
	}
	
	/*
	** 值在0到9之间，把对应的单词加到buffer中
	*/
	if( val > 0 && val <= 9 )
	{
		strcat( buffer, " " );
		strcat( buffer, word_1_9[ val ] );
	}
	
	/*
	** 一个千位处理完后，后面加上对应的分位单词"THOUSAND"、"MILLION"等
	*/
	if( count > 0 )
	{
		strcat( buffer, " " );
		strcat( buffer, word_div[ count-- ] );
		strcat( buffer, " " );
	}
}