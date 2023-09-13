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
	list_t *nnode = info->env;
	char *p;

	while (nnode)
	{
		p = starts_with(nnode->str, name);
		if (p && *p)
			return (p);
		nnode = nnode->next;
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
	int i;

	if (info->argc == 1)
	{
		__eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
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
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
