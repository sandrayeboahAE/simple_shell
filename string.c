#include "shell.h"

/**
 * _strdup - function duplicates a string
 * @str: string
 * Return: pointer to duplicated string
 */

char *_strdup(const char *str);
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - function performs lexicogarphic comparison of two strangs.
 * @s1: first strang
 * @s2: second strang
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}


/**
 * _strlen - function returns the length of a string
 * @s: string whose length to check
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int len 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - function concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src);
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}

/**
 * _strcpy - function copies strings
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src);
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0'
	return (dest);
}
