/*
** 把一个给定的值存储到一个整数中指定的几个位。
** 整数中的位从右到左进行编号，起始位置不会小于
** 结束位的位置。
*/
#include <stdio.h>

/*
** 函数返回值是存储后的值
*/
unsigned 
store_bit_field( unsigned original_value, unsigned value_to_store,
		unsigned starting_bit, unsigned ending_bit )
{
	unsigned answer; // 存储返回值
	
	/*
	** 创建一个掩码（mask），将需要存储的位置相对应的那几位设置为1
	*/
	unsigned mask = 0;
	unsigned i;
	for( i = ending_bit; i <= starting_bit; ++ i ) {
		mask <<= 1;
		mask |= 1;
	}
	mask <<= ending_bit;
	
	/* 
	** 用掩码的反码对原值执行AND操作，将那几位设置为0，存储在temp中
	*/
	unsigned temp;
	temp = ( ~ mask ) & original_value;
	
	/*
	** 将新值左移，使它与那几个需要存储的位对齐
	*/
	value_to_store <<= ending_bit;
	
	/*
	** 把移位后的值与掩码进行位AND操作，确保除需要存储的位之外的其余位置都设置为0
	*/
	value_to_store &= mask;
	
	/*
	** 把上一步的结果值与temp进行位OR操作，得到最终结果
	*/
	answer = value_to_store | temp;
	
	return answer;
}

/*
** 主函数进行测试
*/
int 
main()
{
	printf( "%x", store_bit_field( 0xffff, 0x123, 15, 4 ) );
	
	return 0;
}
