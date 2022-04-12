/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:49:05 by ekern             #+#    #+#             */
/*   Updated: 2022/04/12 16:31:11 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <strings.h>

/* Part 1 */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int l, size_t n);
void		ft_bzero(void *str, int n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dest, const char *src, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *mb, int sc, size_t n);
int			ft_memcmp(const void *p1, const void *p2, size_t n);
char		*ft_strnstr(const char *src, const char *rc, size_t n);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t n);
char		*ft_strdup(const char *src);

/* Part 2 */

char		*ft_substr(const char *src, unsigned int start, size_t n);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *src, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *src, char (*f)(unsigned int, char)); //
void		ft_striteri(char *src, void (*f)(unsigned int, char*)); //
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *src, int fd);
void		ft_putendl_fd(char *src, int fd);
void		ft_putnbr_fd(int n, int fd);

/* Part 3 : my functions  */

int			*fc_dec_to_binary(int dec);
long		ft_atol(const char *str);

#endif
