/*
** 计算1995年美国公民的个人收入所得税
*/

#include <stdio.h>
#include <float.h> // 该头文件中包含double类型能表示的最大的数DBL_MAX

double single_tax( double income );

/*
** 将表格中划分的区间存在数组中
*/
static double const income_limit[] = { 0, 23350, 56550, 117950, 256500, DBL_MAX };
static double const   base_tax[] = { 0, 3502.5, 12798.5, 31832.5, 81710.5 };
static double const percentage[] = { 0.15, 0.28, 0.31, 0.36, 0.396 };

int main()
{
	double income;
	scanf( "%lf", & income );
	printf( "%lf", single_tax( income ) );
	
	return 0;
}

/*
** 函数，计算相应收入对应上交的税额
** 题目中函数原型的数据类型为float，但测试中发现float不够精确
*/
double 
single_tax( double income )
{
	int range;
	double tax;
	
	/*
	** 获取税额对应的计算区间
	*/
	for( range = 1; income > income_limit[ range ]; ++ range )
		;
	range --;
	
	/*
	** 税额计算公式
	*/
	tax = base_tax[ range ] + ( income - income_limit[ range ] ) * percentage[ range ];
	
	return tax;
}