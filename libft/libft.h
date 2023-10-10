/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:40:03 by davidga2          #+#    #+#             */
/*   Updated: 2023/09/13 00:02:38 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Libft base functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// get_next_line functions addons
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

// ft_printf functions addons
int		ft_printf(char const *str, ...);
void	ft_putchar_count(char c, int *ctr);
void	ft_putstr_count(char *s, int *ctr);
void	ft_putnbr_count(int n, int *ctr);
void	ft_putnbr_base(size_t n, char *base_str, int is_ptr, int *ctr);

// so_long functions addons
char	**ft_matrixdup(char **original);
void	ft_free_matrix(char **matrix);
void	ft_print_matrix(char **matrix, char *var_name);

// ft_printf_error (Prints in the fd number 2. Used in so_long)
# define DEC_BASE "0123456789"
# define HEX_BASE_L "0123456789abcdef"
# define HEX_BASE_U "0123456789ABCDEF"

int		ft_printf_error(char const *str, ...);
void	ft_putchar_count_error(char c, int *ctr);
void	ft_putstr_count_error(char *s, int *ctr);
void	ft_putnbr_count_error(int n, int *ctr);
void	ft_putnbr_base_error(size_t n, char *base_str, int is_ptr, int *ctr);

// Libft bonus - Linked lists
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Extra linked list functions
void	ft_lstprint_str(t_list *lst, char *name);
void	ft_lstprint_int(t_list *lst, char *name);
t_list	*ft_lstcreate(size_t n);

// Push_swap addons
long	ft_atol(const char *str);
void	ft_lstprint_long(t_list *lst, char *name);
void	ft_putnbrlong_count(long n, int *ctr);

// Pipex addons
char	*ft_strdoublejoin(char *str1, char *str2, char *str3);

#endif
