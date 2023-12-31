#include "shell.h"


/**
 * _listlen - ...
 * @x: ..
 * Return: ...
 */
size_t _listlen(const stringlist_t *x)
{
	size_t j = 0;

	while (x)
	{
		x = x->next_node;
		j++;
	}
	return (j);
}

/**
 * listToStrings - ...
 * @firstNode: ...
 * Return: ...
 */
char **listToStrings(stringlist_t *firstNode)
{
	stringlist_t *currentNode = firstNode;
	size_t x = _listlen(firstNode), z;
	char **strs;
	char *string;

	if (!firstNode || !x)
		return (NULL);

	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);

	for (x = 0; currentNode; currentNode = currentNode->next_node, x++)
	{
		string = malloc(strl(currentNode->string) + 1);
		if (!string)
		{
			for (z = 0; z < x; z++)
				free(strs[z]);
			free(strs);
			return (NULL);
		}

		string = copyStrings(string, currentNode->string);
		strs[x] = string;
	}
	strs[x] = NULL;
	return (strs);
}


/**
 * _elelist - ...
 * @x: ...
 * Return: ...
 */
size_t _elelist(const stringlist_t *x)
{
	size_t j = 0;

	while (x)
	{
		Puts(convert_number(x->number, 10, 0));
		ptchr(':');
		ptchr(' ');
		Puts(x->string ? x->string : "(Null)");
		Puts("\n");
		x = x->next_node;
		j++;
	}

	return (j);
}

/**
 * nodeStartWith - ...
 * @headNode: ...
 * @srchprfx: ...
 * @chr: ...
 * Return: ...
 */
stringlist_t *nodeStartWith(stringlist_t *headNode, char *srchprfx, char chr)
{
	char *t = NULL;

	while (headNode)
	{
		t = startsWith(headNode->string, srchprfx);
		if (t && ((chr == -1) || (*t == chr)))
			return (headNode);

		headNode = headNode->next_node;
	}

	return (NULL);
}

/**
 * node_index - node index
 * @firstNode: ...
 * @currentNode: ....
 * Return: node
 */
ssize_t node_index(stringlist_t *firstNode, stringlist_t *currentNode)
{
	size_t x = 0;

	while (firstNode)
	{
		if (firstNode == currentNode)
			return (x);
		firstNode = firstNode->next_node;
		x++;
	}
	return (-1);
}
