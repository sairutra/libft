/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_tester.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 23:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2024/03/05 19:48:23 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

//these inclusions are needed to be able to use the write function from
// unistd library. and malloc and free from the stdlib library.

# include <stdio.h>
# include "../../libft.h"
# include <stdlib.h>
# include <limits.h>
# include <string.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[1;32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define BMAG   "\x1B[1;35m"
# define CYN   "\x1B[36m"
# define BCYN   "\x1B[1;36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

int atoi_test();
int bzero_test();
int calloc_test();
int is_test(char * function_name, int (*f)(int), int (*ft)(int));
int itoa_test();
int memchr_test();
int memcmp_test();
int memcpy_test();
int memmove_test();
int memset_test();
int putchar_test();
int putendl_test();
int putstr_test();
int putnbr_test();
int split_test();
int strchr_test();
int strdup_test();
int striteri_test();
int strjoin_test();
int strlcat_test();
int strlcpy_test();
int strlen_test()
#endif

