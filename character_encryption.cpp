/*
** 从标准输入读取字符，并把它们写到标准输出中
** 所有非字母字符都完全按照它的输入形式输出
** 字母字符在输出前进行加密，加密方法：将字母修改成距其13个位置的字母
*/

#include <stdio.h>

int 
main()
{
	char ch;
	
	// 读入字符串，以回车结束
	while( ( ch = getchar() ) != '\n' )
	{
		// 前13个字符向后加13
		if( ( ch >= 'A' && ch <= 'M' ) || ( ch >= 'a' && ch <= 'm' ) )
		{
			ch += 13;
		}
		// 后13个字符向前减13
		else if( ( ch >= 'N' && ch <= 'Z' ) || ( ch >= 'n' && ch <= 'z') )
		{
			ch -= 13;
		}
		putchar( ch );
	}
	
	return 0;
}