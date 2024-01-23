/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 23:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 15:30:26 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		read_buffer(int fd, char **stat_buf);
int		check_nextline(char *stat_buf);
char	*return_str(char **stat_buf, size_t gnl);
char	*realloc_statbuf(char	**stat_buf, size_t gnl, size_t stat_buf_len);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
int		free_all(char **buffer, int ret);

#endif
