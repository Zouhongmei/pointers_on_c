/*
** 2014/12/08, by ZHM
*/
#include <stdio.h>
#include <stdarg.h>

/*
** 函数功能：
**     允许用户访问“伪数组”，它的下标可以任意指定，并有完整的错误检查
** 函数参数：
**     arrayinfo：一个可变长度整型数组，包含一些关于伪数组维数的信息，
**                arrayinfo[0] 指定伪数组的维数，1<=arrayinfo[0]<=10
**                arrayinfo[1]和arrayinfo[2]给出第1维的上限和下限，以此类推
**     ... : 可变参数列表，包含与伪数组维数相等个数的参数。
**           用于标识伪数组中某个特定位置的下标值
** 函数返回：
**     返回伪数组的offset量，用于表示一个向量（一位数组）的下标
**     如出现以下错误情况，则返回-1
**         1. 维数不处于1和10之间；2. 下标小于下限值；
**         3. 下标大于上限值；4. 上限值小于对应的下限值。
*/
int 
array_offset( int arrayinfo[], ... )
{
	/*
	** 检查伪数组的维数是否在1-10之间
	*/
	int N = arrayinfo[0]; // N表示伪数组的维数
	if( N < 1 || N > 10 )
		return -1;
	
	/*
	** 用va_参数宏访问列表，并将值存入数组s中
	*/
	va_list var_arg;
	int s[N];     // s数组存放下标参数
	
	va_start( var_arg, arrayinfo[0] );
	
	int i;
	for( i = 0; i < N; ++ i )
		s[i] = va_arg( var_arg, int );	
		
	va_end( var_arg );
	
	/*
	** 伪数组的目标位置用一个距离伪数组起始位置的整型偏移量表示
	** 以下部分通过公式计算伪数组的目标位置
	*/
	int lo, hi;  // lo表示下限，hi表示上限
	int lo_index, hi_index; // 在arrayinfo数组中lo和hi对应的索引值
	int loc = 0;  // 表示伪数组的目标位置
	int j;
	
	for( j = 0, lo_index = 1, hi_index = 2; j < N; ++ j, lo_index += 2, hi_index += 2 )
	{
		lo = arrayinfo[lo_index];
		hi = arrayinfo[hi_index];
		if( hi < lo || s[j] < lo || s[j] > hi )  // 判断是否存在错误情况
			return -1;
			
		// 计算目标位置
		loc = loc * ( hi - lo + 1 ) + s[j] - lo;
	}
	
	return loc;
}

int
main()
{
	int arrayinfo[] = { 3, 4, 6, 1, 5, -3, 3 };
	int a, b, c;
	scanf( "%d%d%d", &a, &b, &c );
	int offset = array_offset( arrayinfo, a, b, c );
	printf( "%d", offset );
	return 0;
}