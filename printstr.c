#include "shell.h"


/**
 * Printstrer - input
 * @string: ...
 */
void Printstrer(char *string)
{
	int x = 0;

	if (!string)
		return;

	while (string[x] != '\0')
	{

		erprchar(string[x]);
		x++;
	}
}

/**
 * erprchar - ...
 * @ch: print
 * Return: ...
 */
int erprchar(char ch)
{
	static int x;
	static char mybuff[writeBufferSize];

	if (ch == bufferFlush || x >= writeBufferSize)
	{
		write(2, mybuff, x);
		x = 0;
	}

	if (ch != bufferFlush)
		mybuff[x++] = ch;
	return (1);/* Always return 1 */
}

/**
 * WFileDescreptor - ...
 * @x: ...
 * @fileDes: ...
 * Return: ...
 */
int WFileDescreptor(char x, int fileDes)
{
	static int z;
	static char mybuff[writeBufferSize];


	if (x == bufferFlush || z >= writeBufferSize)
	{
		write(fileDes, mybuff, z);
		z = 0;/* Reset buffer index after flushing */
	}

	if (x != bufferFlush)
		mybuff[z++] = x;

	return (1);
}

/**
 * chcnt - ...
 * @string: ...
 * @fileDes: ...
 * Return: ...
 */
int chcnt(char *string, int fileDes)
{
	int x = 0;

	if (!string)
		return (0);

	while (*string)
	{
		x += WFileDescreptor(*string++, fileDes);
	}
	return (x);
}
