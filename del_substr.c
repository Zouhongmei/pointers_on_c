#include <stdio.h>

/*
** 函数，删除一个字符串的一部分。
** 如果 substr 未在 str 出现，则函数返回0；
** 如果 substr 在 str 中出现，则在 substr 中删除 str, 函数返回1；
** 如果 substr 在 str 中出现多次，只删除第一次的出现的位置。
*/
int
del_substr( char *str, char const *substr )
{
	char const *p = substr; // 指针p用来遍历substr字符串
	int match; // match用来标记字符串是否匹配
	char *sp, *find;
	
	/*
	** 用指针find来遍历str字符串，进行查找
	*/
	for( find = str; *find != '\0'; ++find )
	{
		sp = find; // 指针sp用来和substr字符串进行比较，每次循环开始，find赋值给sp
		p = substr; // 每次循环开始，p从substr第一个字符开始遍历
		
		/*
		** 查找str字符串中从sp开始的部分是否与substr字符串匹配
		*/
		while( *p != '\0' )
		{	
			// 如果有一个字符串不匹配，match标记为0，退出while循环
			if( *p != *sp )
			{
				match = 0;
				break;
			}
			p ++;
			sp ++;
		}
		
		// 找到匹配的字符串，match标记为1，退出for循环
		if( *p == '\0' )
		{
			match = 1;
			break;
		}
	}
	
	/*
	** 如果找到匹配，则删除str中的子字符串
	*/
	if( match )
	{
		while( *sp != '\0' )
		{
			*find++ = *sp++;
		}
		*find = '\0';
	}
	
	return match;	
}

int
main()
{
	char str[] = "ABCDEFG";
	char *substr = "FGH";
	int n;
	n = del_substr( str, substr );
	printf( "%d\n%s", n, str );
	return 0;
}