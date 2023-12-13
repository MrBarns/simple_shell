#include "main.h"


/**
 * _strcmp - Compares two strings.
 *
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         Negative byte difference if s1 < s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}


/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */

int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length] != '\0'; length++)
		;
	return (length);
}


/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
	unsigned int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}


/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */

char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}


/**
 * _getenv - gets the environment variable from process environment vector
 *
 * @name: environment variable to search
 * @environ: environment vector
 *
 * Return: value in variable vector if found, NULL otherwise
 */

char *_getenv(char *name, char **environ)
{
	char *result, *key;

	for (; environ != NULL; environ++)
	{
		key = *environ;
		result = strtok(key, "=");
		if (_strcmp(result, name) == 0)
		{
			result = strtok(NULL, "=");
			return (result);
		}
	}
	return (NULL);
}
