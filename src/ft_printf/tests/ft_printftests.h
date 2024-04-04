/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printftests.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 23:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/30 15:02:35 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFTESTS_H
# define FT_PRINTFTESTS_H

//these inclusions are needed to be able to use the write function from
// unistd library. and malloc and free from the stdlib library.

# include <stdio.h>
# include "../inc/ft_printf.h"

# define NORMFOLDER "../../ft_printf"
# define NORMLOGS "logs/norminette_output.txt"
# define NORMLOCLOGS "logs/norminette_location.txt"

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

int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * col);
int compare_length(int test_count, int ft_outcome, int outcome);
int compare_files(int test_count);
void category_c();
void category_s();
void category_p();
void category_d();
void category_i();
void category_u();
void category_x();
void category_X();


#endif
