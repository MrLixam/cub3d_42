/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:09:29 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 03:04:52 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*			LIBFT			*/

/*	put functions to simplify write() calls	*/
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_putunbr_fd(unsigned int n, int fd);

/*	miscellaneous utils functions	*/

//convert a string to an int, atoi_error() is used to check for errors
int		ft_atoi(const char *nptr);
int		*atoi_error(void);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
size_t	ft_len_arr(char **foo);
void	ft_free_arr(char **arr);

/*	memory manipulation	*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/*	single char operations	*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*	string manipulation	*/
//get a string's length
size_t	ft_strlen(const char *str);
//duplicate a string or duplicate a substring
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//create a new string from 2 strings
char	*ft_strjoin(char const *s1, char const *s2);
//search a string for the first or last occurence of a char
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
//concatenate a string to the end of another string
size_t	ft_strlcat(char *dest, const char *src, size_t size);
//copy a string over a given memory space
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
//compare 2 strings
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//find a substring in a given string
char	*ft_strnstr(const char *big, const char *little, size_t len);
//cut out a pattern out of the start and end of a string
char	*ft_strtrim(char const *s1, char const *set);
//iterate a function over a string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

//all relative to chained lists, names are quite clear
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*			FT_PRINTF			*/

//format and print strings (honnestly use printf man)
int		ft_printf(const char *format, ...);
size_t	ft_puthex(unsigned int nbr, char mode);
size_t	ft_putptr(unsigned long long nbr);
size_t	ft_ptr(unsigned long long ptr);

/*			GET_NEXT_LINE		*/

//get a single line from a file, with memory management! 
char	*get_next_line(int fd);
char	***gnl_storage(void);
void	gnl_release(void);
void	gnl_release_fd(int fd);
size_t	gnl_count_lines(char *path);
char	**gnl_full_file(char *path);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		gnl_fd_max(void);

#endif
