#include "shell.h"

void handle_exit(char **argv);
void handle_env(char **env);
void handle_echo(int argc, char **argv);
void handle_setenv(int argc, char **argv);
void handle_cd(int argc, char **argv, char **env);
void execute_command(char **argv, char **envp);
char *construct_command(char *token, char *argv0);
char *get_path_copy(char *path);

int main(int argc, char **argv, char **env)
{
    char *prompt = NULL, *token = NULL, *comment = NULL;
    char *home_path = _getenv("HOME");
    char *path = _getenv("PATH");
    size_t len = 0;
    ssize_t nread;
    int input_is_terminal = isatty(STDIN_FILENO);

    while (1)
    {
        if (input_is_terminal)
            _printf("$ ");
        
        nread = getline(&prompt, &len, stdin);
        if (nread == -1)
        {
            _printf("\n");
            break;
        }

        if (prompt == NULL || prompt[0] == '\n' || prompt[0] == '#')
            continue;

        comment = strtok(prompt, "#");
        if (!comment)
            continue;

        argv = malloc(sizeof(char *) * 100);
        if (!argv)
        {
            perror("malloc");
            break;
        }

        int i = 0;
        token = strtok(comment, " \n");
        while (token != NULL)
        {
            argv[i++] = token;
            token = strtok(NULL, " \n");
        }
        argv[i] = NULL;
        argc = i;

        if (_strcmp(argv[0], "exit") == 0)
                handle_exit(argv);
        
        else if (_strcmp(argv[0], "env") == 0)
                handle_env(env);
        
        else if (_strcmp(argv[0], "echo") == 0)
                handle_echo(argc, argv);
        
        else if (_strcmp(argv[0], "setenv") == 0)
                handle_setenv(argc, argv);
        
        else if (_strcmp(argv[0], "cd") == 0)
                handle_cd(argc, argv, env);
        
        else
                execute_command(argv, env);
        

        free(argv);
    }

    free(prompt);
    return 0;
}

void handle_exit(char **argv)
{
    int exit_status = 0;
    if (argv[1] != NULL)
        exit_status = _atoi(argv[1]);
    exit(exit_status);
}

void handle_env(char **env)
{
    for (int j = 0; env[j]; j++)
        _printf("%s\n", env[j]);
}

void handle_echo(int argc, char **argv)
{
    if (argc > 1)
    {
        if (_strcmp(argv[1], "$$") == 0)
                _printf("%d\n", getpid());
        
        else if (argv[1][0] == '$')
        {
            char *echo_var = _getenv(argv[1] + 1);
            if (echo_var)
                _printf("%s\n", echo_var);
            else
                perror(argv[0]);
        }
        else
        {
            for (int i = 1; i < argc; i++)
                _printf("%s ", argv[i]);
            _printf("\n");
        }
    }
}

void handle_setenv(int argc, char **argv)
{
    if (argc != 3)
    {
        perror(argv[0]);
        return;
    }
    if (setenv(argv[1], argv[2], 1) == -1)
        perror(argv[0]);
}

void handle_cd(int argc, char **argv, char **env)
{
    char *home_path = _getenv("HOME");
    char *old_pwd = _getenv("OLDPWD");
    char *token = argv[1];
    char *cwd;

    if (argc == 1 || _strcmp(token, "$HOME") == 0)
        if (chdir(home_path) == -1)
                perror(argv[0]);
    
    else if (_strcmp(argv[1], "-") == 0)
        if (chdir(old_pwd) == -1)
                perror(argv[0]);
    
    else if (chdir(token) == -1)
        perror(argv[0]);
    

    cwd = getcwd(NULL, 0);
    if (cwd)
    {
        if (setenv("PWD", cwd, 1) == -1)
            perror(argv[0]);
        free(cwd);
    }
    else
        perror(argv[0]);
    
}

void execute_command(char **argv, char **envp)
{
    char *path = _getenv("PATH");
    char *path_cpy = get_path_copy(path);
    char *command = NULL;
    int flag = 0;

    if (!path_cpy)
        return;

    char *token = strtok(path_cpy, ":\n");
    while (token)
    {
        command = construct_command(token, argv[0]);
        if (command && access(command, X_OK) == 0)
        {
            flag = 1;
            break;
        }
        free(command);
        token = strtok(NULL, ":\n");
    }

    if (flag)
    {
        pid_t pid = fork();
        if (pid == -1)
                perror(argv[0]);
        
        else if (pid == 0)
                if (execve(command, argv, envp) == -1)
                        perror(argv[0]);
        else
                if (wait(NULL) == -1)
                        perror(argv[0]);
        
        free(command);
    }
    else
        perror(argv[0]);
    

    free(path_cpy);
}

char *construct_command(char *token, char *argv0)
{
    char *command = malloc(_strlen(token) + _strlen(argv0) + 2);
    if (command)
    {
        _strcpy(command, token);
        _strcat(command, "/");
        _strcat(command, argv0);
    }
    return command;
}

char *get_path_copy(char *path)
{
    if (!path)
        return NULL;
    char *path_cpy = malloc(_strlen(path) + 1);
    if (path_cpy)
        _strcpy(path_cpy, path);
    return path_cpy;
}
