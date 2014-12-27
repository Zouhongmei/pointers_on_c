/*
** 2014-12-17, by ZHM
** 对数据进行加密
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  TRUE  1
#define  FALSE 0

// 字母表
static char ALPHA[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
** prepare_key
**   函数功能：
**       将需要使用的密匙单词转换成一个包含编好码的字符数组
**       函数将密匙单词全部转换成大写字母，并从单词中去除重
**       复的字母，然后将字母表中剩余的字母填充到key数组中。
**   函数参数：
**       key：需要使用的密匙单词，最后编码好的密匙也保存在key中
**   函数返回：
**       如果处理成功，返回TRUE
**       如果key参数为空或包含非字母字符，返回FALSE
*/
int
prepare_key( char *key )
{
	char *repeat_chr;  // 指向找到的重复字母的位置
	char *KEY = key;  // KEY指向最后编好码的字符串
	char *temp = key; // 循环遍历中的临时变量
	char *pALPHA = ALPHA; // 指向字母表
	
	/*
	** 如果key参数为空，返回FALSE
	*/
	if( key == NULL )
		return FALSE;
	
	/*
	** 将重复的字母去除
	*/
	while( ( *key = toupper( *key ) ) != '\0' )
	{
		// 如果key参数包含非字母字符，返回FALSE
		if( !isalpha( *key ) )
			return FALSE;
		
		temp = key;
		/*
		** 用strrchr函数找到当前字母后面与当前字母重复的字母
		** 找到后将重复的字母删除，后面的字母往前移
		*/
		while( ( repeat_chr = strrchr( temp + 1, *temp ) ) != NULL )
		{
			while( *repeat_chr != '\0' )
			{
				*repeat_chr = *( repeat_chr + 1 );
				repeat_chr ++;
			}	
		}
		key ++;
	}
	
	/*
	** 将字母表中剩余的字母填充到key中
	** 从当前密匙后面开始填充，直到26个字母完成
	*/
	int i;
	for( i = strlen( KEY ); i < 26; ++ i )
	{
		// 找到字母表中不与KEY匹配的字母
		while( strchr( KEY, *pALPHA ) != NULL )
			pALPHA ++;
		*key++ = *pALPHA++;	
	}
	*key = '\0'; // 最后加上NUL字节
	
	return TRUE; // 处理完成，返回TRUE
}

/*
** encrypt
**   函数功能：
**       使用产生的密匙对data中的字符进行加密，data中非字母不作修改，
**       字母字符用key中的字符一一取代，字母的大小写状态保留。
**   函数返回：
**       无返回值，直接对data进行修改
*/
void
encrypt( char *data, char const *key )
{
	while( *data != '\0' )
	{
		if( islower( *data ) )
			*data = tolower( key[ *data - 'a' ] );
		if( isupper( *data ) )
			*data = key[ *data - 'A' ];
		data ++;
	}
}

/*
** decrypt
**   函数功能：
**       解密加过密的字符串
*/
void 
decrypt( char *data, char const *key )
{
	unsigned int address; // 字符在字母表中的下标
	while( *data != '\0' )
	{
		if( islower( *data ) )
		{
			address = strchr( key, toupper( *data ) ) - key;
			*data = tolower( ALPHA[ address ] );
		}
		if( isupper( *data ) )
		{
			address = strchr( key, *data ) - key;
			*data = ALPHA[ address ];
		}
		data ++;
	}
}

int 
main()
{
	char key[27];
	gets( key );
	char data[100];
	gets( data );
	
	if( prepare_key( key ) )
	{
		puts( key );
	
		encrypt( data, key );
		puts( data );
		
		decrypt( data, key );
		puts( data );
	}
	
	return 0;
}