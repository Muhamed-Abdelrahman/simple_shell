#include "shell.h"

/**
 * __myexit - exits the shell
 * @info: is var
 *  Return: exits with a given exit status
 */
int __myexit(info_t *info)
{
	int check;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		check = __erratoi(info->argv[1]);
		if (check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			__eputs(info->argv[1]);
			__eputchar('\n');
			return (1);
		}
		info->err_num = __erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * __mycd - changes the current directory
 * @info: is var
 *  Return: Always 0
 */
int __mycd(info_t *info)
{
	char *s1, *dire, buffer[1024];
	int chdir_ret;

	s1 = getcwd(buffer, 1024);
	if (!s1)
		__puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dire = __getenv(info, "HOME=");
		if (!dire)
			chdir_ret = /* TODO: what should this be? */
				chdir((dire = __getenv(info, "PWD=")) ? dire : "/");
		else
			chdir_ret = chdir(dire);
	}
	else if (__strcmp(info->argv[1], "-") == 0)
	{
		if (!__getenv(info, "OLDPWD="))
		{
			__puts(s1);
			__putchar('\n');
			return (1);
		}
		__puts(__getenv(info, "OLDPWD=")), __putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dire = __getenv(info, "OLDPWD=")) ? dire : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		__eputs(info->argv[1]), __eputchar('\n');
	}
	else
	{
		__setenv(info, "OLDPWD", __getenv(info, "PWD="));
		__setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * __myhelp - changes the current directory
 * @info: is var
 *  Return: Always 0
 */
int __myhelp(info_t *info)
{
	char **arg__array;

	arg__array = info->argv;
	__puts("help call works. Function not yet implemented \n");
	if (0)
		__puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
