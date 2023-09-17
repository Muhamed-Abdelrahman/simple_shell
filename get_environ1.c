#include "shell.h"

/**
 * __myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int __myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * __getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *__getenv(info_t *info, const char *name)
{
	list_t *nodel = info->env;
	char *p;

	while (nodel)
	{
		p = starts_with(nodel->str, name);
		if (p && *p)
			return (p);
		nodel = nodel->next;
	}
	return (NULL);
}

/**
 * __mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int __mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		__eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (__setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * __myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int __myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		__eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		__unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *nodel = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_nodel_end(&nodel, environ[j], 0);
	info->env = nodel;
	return (0);
}
