/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:48:53 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/06 17:00:59 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "ansi_escape_codes.h"

# define MAX_INT	2147483647
# define MIN_INT	-2147483648
# define BUFF_SIZE	51
# define FD_MAX		4864
# define MAX_BASE	36
# define MIN_BASE	2
# define DIGITS		"0123456789abcdefghijklmnopqrstuvwxyz"
# define EPSILON	0.00000000001

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src, \
					size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src, \
					int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2, \
					size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src, \
					size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int				ft_iswspace(int c);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_chrjoin(char c1, char c2);
size_t				ft_strclen(const char *s, char c);
size_t				ft_strlcpy(char *restrict dst, const char *restrict src, \
					size_t dstsize);
char				*ft_joindel(char *s1, char *s2);
size_t				ft_strcount(const char *s, char c);
char				*ft_itoafree(int n);
int				get_next_line(const int fd, char **line);
void				ft_swap(int *a, int *b);
char				*ft_strnrev(char *str, size_t start, size_t end);
char				*ft_strrev(char *str);
char				*ft_strlwr(char *str);
char				*ft_strupr(char *str);
char				*ft_strpbrk(const char *s, const char *charset);
size_t				ft_strcspn(const char *s, const char *charset);
size_t				ft_strspn(const char *s, const char *charset);
char				*ft_imaxtoa(intmax_t n, int base);
intmax_t			ft_atoimax(const char *str, char **endptr, int base);
char				*ft_uimaxtoa(uintmax_t n, int base);
uintmax_t			ft_atouimax(const char *str, char **endptr, int base);
char				*ft_rmchr(char *str, char c);
int				ft_abs(int n);
intmax_t			ft_imaxabs(intmax_t n);
double				ft_fabs(double n);
long double			ft_fabsl(long double n);
double				ft_pow(double base, int exp);
long double			ft_powl(long double base, int exp);
char				*ft_ftoa(long double n, int precision);
double				ft_sqrt(double x);
long double			ft_sqrtl(long double x);
double				ft_ceil(double x);
long double			ft_ceill(long double x);
double				ft_floor(double x);
long double			ft_floorl(long double x);
double				ft_round(double x);
long double			ft_roundl(long double x);
int				ft_fequal(double x, double y);
int				ft_fequall(long double x, long double y);
double				ft_fmax(double x, double y);
long double			ft_fmaxl(long double x, long double y);
double				ft_fmin(double x, double y);
long double			ft_fminl(long double x, long double y);
intmax_t			ft_max(intmax_t x, intmax_t y);
intmax_t			ft_min(intmax_t x, intmax_t y);
double				ft_fmod(double x, double y);
long double			ft_fmodl(long double x, long double y);
double				ft_modf(double value, double *iptr);
long double			ft_modfl(long double value, long double *iptr);
long double			ft_setprecision(long double x, int precision);
double				ft_trunc(double x);
long double			ft_truncl(long double x);
char				*ft_strtok(char *restrict str, const char *restrict sep);

#endif
