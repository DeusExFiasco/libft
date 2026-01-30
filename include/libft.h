/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik <kixik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:48:54 by kixik             #+#    #+#             */
/*   Updated: 2026/01/30 18:56:03 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

		// ~~ LIBRARY / HEADER INCLUDES ~~ //

// C Standard libraries
# include <stdlib.h> // malloc and free
# include <unistd.h> // read and write
# include <limits.h> // MIN_INT and other constants
# include <stdarg.h> // Variadic functions
# include <stdint.h> // Useful numeric types 
# include <fcntl.h> // File descriptor read flags
# include <stdbool.h> // Boolean type and true/false
# include <math.h> // math functions when allowed
# include <stdio.h> // printf and other stdio functions (testing)

// Sub-header includes
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_gc.h"

		// ~~ CONSTANT DEFINES ~~ //

// ANSI Colors
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
// Color reset
# define RESET   "\x1b[0m"

		// ~~ LINKED LISTS ~~ //

// Linked list node
typedef struct s_list_node
{
	void				*content;
    struct s_list_node  *prev;
	struct s_list_node	*next;
}	t_list_node;

typedef struct s_list
{
	t_list_node	*head;
	t_list_node	*tail;
	size_t		size;
}	t_list;

		// ~~ FUNCTION PROTOTYPES ~~ //

// Conversion functions
char		*ft_itoa(int n);
float		ft_atof(char *str);
int			ft_atoi(const char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);

// Memory manipulation functions
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);

// Character boolean functions
bool		ft_isalnum(int c);
bool		ft_isalpha(int c);
bool		ft_isascii(int c);
bool		ft_isdigit(int c);
bool		ft_isprint(int c);

// String manipulation functions
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *dest, const char *src);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Various util functions
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

// Bonus linked list functions
t_list_node	*ft_lstnew(void *content);
void		ft_lstadd_front(t_list_node **lst, t_list_node *new);
int			ft_lstsize(t_list_node *lst);
t_list_node	*ft_lstlast(t_list_node *lst);
void		ft_lstadd_back(t_list_node **lst, t_list_node *new);
void		ft_lstdelone(t_list_node *lst, void (*del)(void *));
void		ft_lstclear(t_list_node **lst, void (*del)(void *));
void		ft_lstiter(t_list_node *lst, void (*f)(void *));
t_list_node	*ft_lstmap(t_list_node *lst, void *(*f)(void *),
				void (*del)(void *));

// ft_fprintf implementation (used to be only printf)
int			ft_printf(const char *str, ...);
int			ft_fprintf(int fd, const char *str, ...);

// get_next_line implementation
char		*get_next_line(int fd);

// ft_gc garbage collection functions
void		*gc_malloc(size_t size);
void		gc_free(void *ptr);
void		gc_collect(void);

#endif
