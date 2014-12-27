/* 
** 把一个数的二进制位模式从左到右变换一下
*/

#include <stdio.h>

unsigned int reverse_bits( unsigned int value );

int 
main()
{
	unsigned int a;
	/* 
	** unsigned int 类型用 %u
	*/
	scanf( "%u", &a ); 
	printf( "%u", reverse_bits( a ) );
	
	return 0;
}

/* 
** 函数的返回值是把value的二进制位模式从左到右变换后的值
*/
unsigned int 
reverse_bits( unsigned int value )
{
	unsigned int answer; // 存放返回值
	unsigned int i;  // 计算循环次数
	
	answer = 0;
	
	/*
	** i不是0就继续运行。循环与机器的字长无关，避免了可移植性
	*/
	for( i = 1; i != 0; i <<= 1 ) {
		/*
		** 把旧的 answer 左移 1 位，为下一个位留下空间
		** 如果 value 的最后一位是 1，answer 就与 1 进行 or 操作
		** 然后把 value 右移至下一位
		*/
		answer <<= 1;
		if( value & 1 )
			answer |= 1;
		value >>= 1;
	}
	
	return answer;
}