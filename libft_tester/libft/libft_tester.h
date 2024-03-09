/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_tester.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 23:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2024/03/07 17:05:19 by spenning      ########   odam.nl         */
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

# define NORMFOLDER "../../libft"
# define NORMLOGS "logs/norminette_output.txt"
# define NORMLOCLOGS "logs/norminette_location.txt"

# define ATOI "ft_atoi.c"
# define BZERO "ft_bzero.c"
# define CALLOC "ft_calloc.c"
# define ISALNUM "ft_isalnum.c"
# define ISALPHA "ft_isalpha.c"
# define ISASCII "ft_isascii.c"
# define ISDIGIT "ft_isdigit.c"
# define ISPRINT "ft_isprint.c"
# define ITOA "ft_itoa.c"
# define MEMCHR "ft_memchr.c"
# define MEMCMP "ft_memcmp.c"
# define MEMCPY "ft_memcpy.c"
# define MEMMOVE "ft_memmove.c"
# define MEMSET "ft_memset.c"
# define PUTCHAR "ft_putchar_fd.c"
# define PUTENDL "ft_putendl_fd.c"
# define PUTNBR "ft_putnbr_fd.c"
# define PUTSTR "ft_putstr_fd.c"
# define SPLIT "ft_split.c"
# define STRCHR "ft_strchr.c"
# define STRDUP "ft_strdup.c"
# define STRITERI "ft_striteri.c"
# define STRJOIN "ft_strjoin.c"
# define STRLCAT "ft_strlcat.c"
# define STRLCPY "ft_strlcpy.c"
# define STRLEN "ft_strlen.c"
# define STRMAPI "ft_strmapi.c"
# define STRNCMP "ft_strncmp.c"
# define STRNSTR "ft_strnstr.c"
# define STRRCHR "ft_strrchr.c"
# define STRTRIM "ft_strtrim.c"
# define SUBSTR "ft_substr.c"
# define TOLOWER "ft_tolower.c"
# define TOUPPER "ft_toupper.c"



int atoi_test();
int bzero_test();
int calloc_test();
int isto_test(char * function_name, int (*f)(int), int (*ft)(int));
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
int strlen_test();
int strmapi_test();
int strncmp_test();
int strnstr_test();
int strrchr_test();
int substr_test();
int strtrim_test();
#endif

