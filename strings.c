#include "main.h"
/**
 * _strcmp - compares two strings.
 *
 * @s1: input const string
 * @s2: input const strings
 * Return: returns an integer indicating the result of the comparison
 *	0, if the s1 and s2 are equal, negative val if s1 < s2
 *	A postive val if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}
/**
 * _strcat - concat a string to another
 * @des: The destination string
 * @src: The source string
 * Return: On success, the resulting string
 */
char *_strcat(char *des, char *src)
{
	int i = 0;

	while (*des != '\0')
	{
		des++;
		i++;
	}
	while (*src != '\0')
	{
		*des = *src;
		des++;
		i++;
		src++;
	}
	*des = '\0';
	des -= i;
	return (des);
}
/**
 * _strcpy - copies a string to another
 * @src: The source string
 * @des: The destination string
 * Return: On success, the destination string
*/
char *_strcpy(char *des, char *src)
{
	int l = 0, i;

	while (src[l] != '\0')
		l++;
	for (i = 0; i <= l; i++)
		des[i] = src[i];
	return (des);
}
/**
 * _strlen - determines the length of a string
 * @str: the pointer pointing to a string
 * Return: length of the string
*/
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}
/**
 * _strdup - duplicates a string to another one
 * @str: the string
 * Return: buffer
 */
char *_strdup(char *str)
{
	int len = 0, i = 0;
	char *buff;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
		len++;
	buff = malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	while (str[i] != '\0')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
