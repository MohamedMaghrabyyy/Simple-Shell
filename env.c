#include "shell.h"
/**
 * unsetenv - unset an environmental variable
 * @name: name of the environmental variable to unsert
 * Return: 0 (on success) and -1 (on failure)
 */
/**
 * setenv - set or modifiy an environmental varibale
 * @name: name of the environmental variable to set
 * @value: value of the env variable
 * @overwrite: determines wether teh user wants teh env variables'
 * value to be overwrriten if the name already exists or not
 *
 * Return: 0 (on success) and -1 (on failure)
 */
int setenv(const char *name, const char *value, int overwrite)
{
	char **env = environ;
	ssize_t i;
	char *cur_env;
	char *cur_name;
	int flag = -1;
	char *new_env;

	if (!name || name[0] == '\0' || findchar(name, '='))
		return (-1);
	if (!overwrite)
		return (-1);
	for (i = 0; env[i]; i++)
	{
		cur_env = malloc(sizeof(char) * _strlen(env[i]));
		if (!cur_env)
			return (-1);
		_strcpy(cur_env, env[i]);
		cur_name = strtok(cur_env, "=\n");
		if (!cur_name)
			return (-1);
		if (_strcmp(cur_name, name) == 0)
		{
			if (overwrite)
			{
				_strcpy(env[i], name);
				_strcat(env[i], "=");
				_strcat(env[i], value);
				flag = 0;
				free(cur_env);
				break;

			}
		}
		free(cur_env);

	}
	if (flag == 0)
		return (0);
	for (i = 0; env[i]; i++)
		;
	new_env = malloc(_strlen(name) + _strlen(value) + 3);
	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);
	env[i] = new_env;
	i++;
	env[i] = NULL;
	return (0);

}
/**
 * _getenv - returns the value of a given env variable
 * @name: name of the env variable to get value of
 * Return: value of env var
 */
char *_getenv(const char *name)
{
	char **env = environ;
	char *value = NULL;
	char *var, *name_tok, *val_tok;

	while (*env != NULL)
	{
		var = malloc(strlen(*env) + 2);
		if (var == NULL)
			return (NULL);
		_strcpy(var, *env);
		name_tok = strtok(var, "=");
		val_tok = strtok(NULL, "=");
		if (name_tok && val_tok && _strcmp(name_tok, name) == 0)
		{
			value = malloc(sizeof(char) * 200);
			_strcpy(value, val_tok);
			free(var);
			break;
		}
		free(var);
		env++;
	}
	return (value);
}
