/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:49:36 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/25 19:49:55 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_symbols {
	short int		sign;
	short int		length;
	short int		precision;
	short int		width;
	char			type;
	char			plus;
	char			minus;
	char			nul;
	char			space;
	char			sharp;
}					t_symbols;

int					(*g_operations[251]) (t_symbols *save, va_list argp);

int					ft_printf(const char *format, ...);

int					ft_validation(const char *s, int i);
int					ft_valid_type(const char *s, int i);
int					ft_valid_flag(const char *s, int i);
int					ft_valid_width(const char *s, int i);
int					ft_valid_precision(const char *s, int i);
int					ft_valid_size(const char *s, int i);
int					ft_create_array(const char *s, va_list argp);
char				*ft_refill(char *s);
void				ft_putnstr(char const *s, int i, int j);

char				*ft_itol(size_t n);
void				ft_putchar(char c);
void				ft_fill_array_operation();
size_t				ft_strlen(char *s);

void				ft_get_type(char *symbols, t_symbols *save, int *i);
void				ft_get_precisions(char *symbols, t_symbols *save, int *i);
void				ft_get_width(char *symbols, t_symbols *save, int *i);
void				ft_get_flags(char *symbols, t_symbols *save, int *i);
int					ft_get_value(char *symbols, va_list argp);

int					char_to_string(t_symbols *save, va_list argp);
int					string_to_string(t_symbols *save, va_list argp);
int					digits_to_string(t_symbols *save, va_list argp);
int					unsigned_to_string(t_symbols *save, va_list argp);
int					float_to_string(t_symbols *save, va_list argp);
int					sixteen_to_string(t_symbols *save, va_list argp);
char				*ft_for_x(long long int num);
char				*ft_for_bigx(long long int num);
int					octal_to_string(t_symbols *save, va_list argp);
int					pointer_to_string(t_symbols *save, va_list argp);
char				*ft_for_o(long long int num);
int					percent_to_string(t_symbols *save, va_list argp);
char				*ft_strjoin(char *s1, char *s2);

char				*ft_for_xsh(long long int num);
char				*ft_for_xch(long long num);
char				*ft_for_bigxsh(long long int num);
char				*ft_for_bigxch(long long num);
char				*ft_for_osh(long long int num);
char				*ft_for_och(long long int num);
char				*ft_for_oul(long long int num);
char				*ft_for_xul(long long int num);
char				*ft_for_bigxul(long long num);

void				ft_print_unsigned(t_symbols *save, int lenght,
		char *result, int len);
void				ft_print_decimal(t_symbols *save, int lenght,
		char *result, long long int num);
void				ft_print_hexa(t_symbols *save, int lenght,
		char *result, int long long num);
void				ft_print_float(t_symbols *save, int lenght,
		int len, char *result);
long double			ft_get_float(t_symbols *save, va_list argp);
void				ft_print_octal(t_symbols *save, long long int num,
		char *result, int lenght);

#endif
