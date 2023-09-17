#include "shell.h"

/**
 * __myhistory - displays the history list,
 * @info: is var
 *  Return: Always 0
 */
int __myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *pp, cc;
	int rett;

	pp = __strchr(str, '=');
	if (!pp)
		return (1);
	cc = *pp;
	*pp = 0;
	rett = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pp = cc;
	return (rett);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *pp;

	pp = __strchr(str, '=');
	if (!pp)
		return (1);
	if (!*++pp)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *pp = NULL, *aa = NULL;

	if (node)
	{
		pp = __strchr(node->str, '=');
		for (aa = node->str; aa <= pp; aa++)
			__putchar(*aa);
		__putchar('\'');
		__puts(pp + 1);
		__puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: is var
 *  Return: Always 0
 */
int __myalias(info_t *info)
{
	int ii = 0;
	char *pp = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (ii = 1; info->argv[ii]; ii++)
	{
		pp = __strchr(info->argv[ii], '=');
		if (pp)
			set_alias(info, info->argv[ii]);
		else
			print_alias(node_starts_with(info->alias, info->argv[ii], '='));
	}

	return (0);
}
