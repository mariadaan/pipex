/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:02:54 by mdaan         #+#    #+#                 */
/*   Updated: 2021/10/06 19:56:47 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
**	Part 1: libc functions
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			ft_strcpy(char *dst, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_inset(char *s1, char c);
int				ft_setinset(char *s1, char *s2);
int				ft_modstr(char *s, char c);
int				ft_strlend(const char *s, char end);
char		*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_has_digit(char *str);
int				ft_onlydigits(char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
int				get_findex(char *str, char c);
int				get_lindex(char *str, char c);

char			*create_line(char *str, char *needle);

/*
**	Part 2: Additional functions
*/

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			**free_2darray(char **array);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putbasenbr(unsigned int num, int base);
void			ft_put2darray(char **array, int height);
char			*ft_move_ptr(const char *s, int c);
int				ft_count_rows(char **array);
int				get_str_index(char **array, char *str);

/*
**	Bonus part: list functions
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
**	Read functions
*/

int				read_till_end(int fd, char **line);

/*
**	Debug functions
*/

int				printnum(char *name, int num);
int				printfloat(char *name, float num);
int				printstr(char *name, char *str);
int				printchar(char *name, char c);
int				printco(char *name, int x, int y);
int				printflco(char *name, double x, double y);

/*
**	Useful str functions
*/
char			*ft_concat(char *str1, char *str2);
char			*ft_concat_three(char *str1, char *str2, char *str3);

#endif
