/*
** EPITECH PROJECT, 2019
** my
** File description:
** header
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include "structs.h"

#ifndef FPTR_
#define FPTR_

struct s_subs
{
    char sign;
    char hashtag;
    char padding;
    int nbr;
    int len;
};
typedef struct s_subs subs;

struct s_params
{
    char flag;
    int (*fptr)(va_list, subs *);
};
typedef struct s_params params;

#endif /* FPTR_ */

//cut_to.c
int cut_to(char *s);
int echo_error(int which_qoute, int qoutes);

//set_unset.c
int set(shell_t *shell, char **av, int ac);
void show_set(var_t *var);
void unset(shell_t *shell, char **av, int ac);
int count_to(char *s, char f);
int count_from(char *s, char f);
int cut_from(char *s);

//main.c
var_t *put_var(var_t *envp, char *name, char *value);

//echo.c
void echo(char *line);
char *get_output(char *output, char *new, int which_qoute);
int c_flag_echo(char c);
int echo_in_loop(const char *new, int *i, int *j, char *output);
char *check_octal(char *output, char *new, int *j, int *i);

//echo_flags.c
char *flags(char *output, char c, int *j, int *i);
char *flags_two(char *output, char c, int *j, int *i);
int is_valid_flag(char c);
char *flags_fvb(char *output, char c, int *j, int *i);
int get_len_of_line(const char *output, int j);

//echo_clean.c
void check_space(char c, int *space, int *set_space);
int mcs_in_loop(int *qoute, char *new, char s, int *j);
char *my_clean_string(char *s);
int oct_to_dec(int o);
int get_oct_num(char *new, int i);


//prompt.c
void prompt(var_t *envp);

//seperators.c
command_t *get_sep_cmds(char *cmd);

//pipe_error.c
int check_cmd(char *cmd);
int check_fl_cmd(char *cmd);
int count_cmds(char *cmd);
int count_pipes(char *cmd);

//shell.c
int shell_main(shell_t *shell);
void show_env(var_t *element, int argc, char **argv, int *ret);
void my_exit(int argc, char **argv, int *ret);
void handle_signal(int sig);

//shell_builtins.c
int shell_loop_builtins(shell_t *shell, char *cmd);

//setenv.c
var_t *set_env(var_t *envp, int argc, char **av, int *ret);
var_t *append(var_t *envp, char *name, char *value);

//unsetenv.c
var_t *unset_env(var_t *envp, int argc, char **av, int *ret);

//cd.c
char *get_value(var_t *envp, char *str);
var_t *my_cd(var_t *envp, char **av, int *ret);

//path.c
int search(DIR *dir, char *cmd);
char **get_paths_env(var_t *envp, char **paths);
char *find_executable(char **paths, char *cmd);

//redirections.c
void rm_redirect(char **argv);
char *get_from_av(char **argv, int path);
int output_redirect(char *path, char const *sep);
int two_input_redirect(char *path);
int check_input_redirect(char *path);

//prep_cmd.c
int check_cmd(char *cmd);
int pipe_error(char *cmds, char **pipes);
int check_pipes(char **pipes);
void exec_cmds(shell_t *shell);
int simple_exec(shell_t *shell, char *arg);

//exec_parts.c
exec_struct_t init_struct(char **av);
void if_path(exec_struct_t *my_struct, char **av);
void after_exec(exec_struct_t *my_struct);
void do_exec(shell_t *shell, char **av, exec_struct_t *exe);

//exec.c
int signal_handler(int status);
int my_exec(shell_t *shell, char **av);
char **prep_env(var_t *envp);

//pipe.c
void pipe_prepare_link(int len, int i, int *pipefds);
int pipe_exec(shell_t *shell, char **pipes);
void clear_pipe_buffer(char *buffer);

//pipe_builtin.c
int pipe_builtin_exec(var_t *envp, char **cmds, int i, int *pipefds);
int count_builtins(char **cmds);

//error.c
int my_errputstr(char const *str);
void my_error(char *message, char *argument);
void my_error_exit(char *message, char *argument);

//which_where.c
int my_which(char **paths, int ac, char ** av);
int my_where(char **paths, int ac, char **av);

//alias.c
char *strcat_command(char **av);
int set_first_alias(var_t *head, var_t *new);
int double_alias(var_t *new, var_t *ptr);
void my_alias(var_t *alias, int ac, char **av);

//alias_exec.c
char **exec_aliases(var_t *head, char *cmd);

//shellvar_parser.c
char *parse_input(char *input, var_t *var, var_t *env);

//repeat.c
int my_repeat(shell_t *shell, char **cmd);

int my_alphacmp(char const *s1, char const *s2);

int my_arraylen(char **array);

char *my_malloc_strcat(char *dest, char const *src);

char **my_str_to_special_array(char const *str, char const *sep);

char *my_strnmcpy(char *dest, char const *src, int m, int n);

char *my_strmcpy(char *dest, char const *src, int m);

int p_flag_2(subs *sub, long long nb);

int put_x_flag(subs *sub, unsigned int nb);

int put_o_flag(subs *sub, unsigned int nb);

int put_cap_x_flag(subs *sub, unsigned int nb);

subs *mod_loop(char *flags, subs *sub_flags, int match, int i);

subs *modifier(char *str, int i);

void put_d_flag(int nb,  subs *sub);

int count_base(unsigned int nbr, int len);

int count_digit(unsigned int nbr);

int percent_flag(va_list list, subs *sub);

int p_flag(va_list list, subs *sub);

int cap_x_flag(va_list list, subs *sub);

int u_flag(va_list list, subs *sub);

int o_flag(va_list list, subs *sub);

int x_flag(va_list list, subs *sub);

int s_flag(va_list list, subs *sub);

int b_flag(va_list list, subs *sub);

int cap_s_flag(va_list list, subs *sub);

int c_flag(va_list list, subs *sub);

int d_flag(va_list list, subs *sub);

int count_args(char *str);

int put_params(char *flags, va_list list);

int my_printf(char *str, ...);

char *my_strcat_char(char *src, char c);

int my_int_arraylen(int * const *array);

int my_putnbr_base(unsigned int n, char const *base);

int my_put_unsigned(unsigned int nb);

int my_showmem(char const *str, int size);

int my_str_isupper(char const *str);

int my_compute_power_rec(int nb, int p);

int my_showstr(char const *str);

int my_strlen(char const *str);

void my_sort_int_array(int *array2, int size);

char *my_strlowcase(char *str);

int my_find_prime_sup(int nb);

char *my_strcapitalize(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_getnbr(char const *str);

char *my_strcat(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

int my_strncmp(char const *s1, char const *s2, int n);

int my_isneg(int n);

int my_strcmp(char const *s1, char const *s2);

int my_is_prime (int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strstr(char *str, char const *to_find);

void my_putchar(char c);

int my_str_isalpha(char const *str);

int *my_strupcase(char *str);

int my_put_nbr(int nb);

int my_str_islower(char const *str);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_str_isnum(char const *str);

char *my_revstr(char *str);

int my_str_isprintable(char const *str);

char *concat_params(int argc, char **argv);

int my_show_word_array(char * const *tab);

char *my_strdup(char const *src);

char **my_str_to_word_array(char const *str);

int my_compute_square_root(int nb);

int get_len(int argc, char **argv);

int check_negativ(int i, char const *str, int nb);

int check_nb(char const *str , int i, int nb);

int is_alnum(char character);

int counts_words(char const *str);

int counts_character(char const *str, int toto);

int count_digits(int nb);

int conv(int inter);
