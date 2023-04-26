#ifndef SIMPLES_H
#define SIMPLES_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
typedef struct info_s
{
char **environ;
char **argv;
int err_num;
int status;
} info_t;
#define INFO_INIT \
/* build.c */
int exit_shell(info_t *info);
int change_dir(info_t *info);
int show_help(info_t *info);
/*build1.c */
int print_history(info_t *info);
int unset_alias_str(info_t *info, char *str);
int set_alias_str(info_t *info, char *str);
int print_alias_str(list_t *node);
int my_alias(info_t *info);
#endif
