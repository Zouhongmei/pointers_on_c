/* 
** 数组 bit_array[] 用来存储所有的位
** 正数 bit_number 用来标识需要访问的位
*/

/* 
** 把指定位设置为1
*/
void 
set_bit( char bit_array[], unsigned bit_number )
{
	bit_array[ bit_number ] = 1;
}

/* 
** 把指定位清零
*/
void 
clear_bit( char bit_array[], unsigned bit_number )
{
	bit_array[ bit_number ] = 0;
}

/*
** 如果value的值为0，则把指定位清零
** 否则设置为1
*/
void 
assign_bit( char bit_array[], unsigned bit_number, int value )
{
	if( value == 0 )
		bit_array[ bit_number ] = 0;
	else
		bit_array[ bit_number ] = 1;
}

/*
** 如果指定位不是0，函数返回真，否则返回假
*/
int 
test_bit( char bit_array[], unsigned bit_number )
{
	if( bit_array[ bit_number ] )
		return 1;
	else
		return 0;
}