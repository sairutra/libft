/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 23:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2023/10/22 14:02:53 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// These are header guards that prevent the double definitions in the 
// source file. This prevents library dependency from double copying
// libraries. if libft is already defined if won't define it again.
// name is LIBFT_H because the name should be the full filename of the 
// header file, in all caps, with underscores for spaces and ​punctuation.

#ifndef LIBFT_H
# define LIBFT_H

//these inclusions are needed to be able to use the write function from
// unistd library. and malloc and free from the stdlib library.

# include <stdlib.h>
# include <unistd.h>

// Bonus struct

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

// string functions

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_toupper(int input);
int		ft_tolower(int input);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

// memory functions
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// is functions
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);

// write functions
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int d, int fd);
void	ft_putstr_fd(char *s, int fd);

// function pointers
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));

// bonus functions
t_list  *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
