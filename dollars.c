/*
** 2014-12-18, by ZHM
*/
#include <stdio.h>
#include <string.h>

/*
** dollars
**    函数功能：
**        把一个数字字符串（代表以美分为单位的金额）转换为美元形式
**        打印大数额时，用','将数字进行分隔
**    函数参数：
**        dest：结果字符串保存到dest中
**        src：指向需要被格式化的字符（假定全是数字）
*/
void
dollars( char *dest, char const *src )
{
	/*
	** 将dest字符串初始化为"$0.00"
	*/
	strncpy( dest, "$0.00", 5 );
	*( dest + 5 ) = '\0';
	
	// 如果src字符串为空，直接返回，dest为"$0.00"
	if( src == NULL )
		return;
	
	int len = strlen( src ); // len为src字符串的长度
	int count = 0; // 计算小数点前面输出了几位数字
	int i;
	
	/*
	** 如果src字符串的长度比3小，则整数部分为0，
	** 整数部分不用处理，只处理小数部分
	*/
	if( len < 3 )
	{
		strncpy( dest + 5 - len, src, len ); // 将src的数字复制到相应的小数位上
		*( dest + 5 ) = '\0';
	}
	
	/*
	** 如果src字符串的长度大于等于3，先将整数部分复制到dest中，
	** 再加上小数点，复制最后两位到小数部分
	*/
	else {
		dest ++; // 第1个字符'$'不变，src中的数字复制到dest第2个字符后面
		while( len-- >= 3 )
		{
			// 如果剩余的整数部分数字个数是3的倍数，且前面已经有数字，则加一个','
			if( ( len + 1 - 2 ) % 3 == 0 && count != 0 )
				*dest++ = ',';
			*dest++ = *src++; 
			count ++;
		}
		/*
		** 处理小数部分
		*/
		*dest++ = '.';
		strncpy( dest, src, 3 ); // 将小数点后2位以及NUL字节复制到dest末尾
	}
}

int
main()
{
	char dest[100], src[100];
	gets( src );
	dollars( dest, src );
	puts( dest );
	return 0;
}

