/*
**
*/
#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

char *
edit( char *pattern, char const *digits )
{
	if( pattern == NULL || digits == NULL )
		return NULL;
		
	char pad = *pattern;
	char *rtrn = NULL;
	int signif = FALSE;
	
	while( *++pattern != '\0' && *digits != '\0' )
	{
		if( *pattern == '#' )
		{
			if( signif == FALSE )
			{
				if( *digits == '0' || *digits == ' ' )
				{
					*pattern = pad;
					digits ++;
				}
				else {
					*pattern = *digits++;
					signif = TRUE;
					rtrn = pattern;
				}
			} else {
				if( *digits == ' ' ) {
					*pattern = '0';
					digits ++;
				} else
					*pattern = *digits++;
			}
		}
		else if( *pattern == '!' )
		{
			if( signif == FALSE )
			{
				if( *digits == ' ' )
				{
					*pattern = '0';
					digits ++;
				} else
					*pattern = *digits++;
				signif = TRUE;
				rtrn = pattern;
			} else
				*pattern = *digits++;
		}
		else
		{
			if( signif == FALSE )
				*pattern = pad;
			else
				continue;
		}
	}
	if( *pattern != '\0' )
		*( pattern + 1 ) = '\0';
	return rtrn;
}

int
main()
{
	char pattern[100], digits[100];
	gets( pattern );
	gets( digits );
	char *after = edit( pattern, digits );
	puts( pattern );
	puts( after );
	return 0;
}