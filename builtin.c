#include "shell.h"

/**
 * exitEmulator - ...
 * @infolist: ...
 * Return: ...
 */
int exitEmulator(infolist_t *infolist)
{
	int checkExit;

	if (infolist->argument_v[1])
	{
		checkExit = StringToInteger(infolist->argument_v[1]);

		if (checkExit == -1)
		{
			infolist->my_status = 2;
			PrintError(infolist, "Illegal number: ");
			errPrintStr(infolist->argument_v[1]);
			errPrintChar('\n');
			return (1);
		}
		infolist->err_code = StringToInteger(infolist->argument_v[1]);
		return (-2);
	}

	infolist->err_code = -1;
	return (-2);
}

/**
 * cdEmulator - ...
 * @infolist: ...
 *  Return: ...
 */
int cdEmulator(infolist_t *infolist)
{
char *str, *directory, myBuff[1024];
int ret_dir;

str = getcwd(myBuff, 1024);/*get current working directory.*/
if (!str)
	Puts("TODO: >>getcwd failure emsg here<<\n");
if (!infolist->argument_v[1])
{
	directory = getEnv(infolist, "HOME=");
	if (!directory)
		ret_dir =
		chdir((directory = getEnv(infolist, "PWD=")) ? directory : "/");
	else
	ret_dir = chdir(directory);
}
else if (compareStrings(infolist->argument_v[1], "-") == 0)
{
	if (!getEnv(infolist, "OLDPWD="))
	{
		Puts(str);
		PutCharacter('\n');
		return (1);
	}
	Puts(getEnv(infolist, "OLDPWD=")), PutCharacter('\n');
	ret_dir =
		chdir((directory = getEnv(infolist, "OLDPWD=")) ? directory : "/");
}
else
	ret_dir = chdir(infolist->argument_v[1]);
if (ret_dir == -1)
{
	PrintError(infolist, "can't cd to ");
	errPrintStr(infolist->argument_v[1]), errPrintChar('\n');
}
else
{
	init_env_var(infolist, "OLDPWD", getEnv(infolist, "PWD="));
	init_env_var(infolist, "PWD", getcwd(myBuff, 1024));
}
return (0);
}

/**
 * helpEmulator - ...
 * @infolist: ...
 * Return: ...
 */
int helpEmulator(infolist_t *infolist)
{
	char **arrayArgument;

	arrayArgument = infolist->argument_v;
Puts("This is for the help command.but Functionality not implemented yet.\n");

	if (0)
		Puts(*arrayArgument);
	return (0);
}
