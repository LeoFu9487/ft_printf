/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:55:19 by yfu               #+#    #+#             */
/*   Updated: 2021/01/26 09:55:32 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../Libft/libft.h"

/*
** [flags][width][.precision][length]specifier
**
** flags : '-' '+' ' ' '#' '0'
**
** length : l ll h hh
**
** specifier : cspdiuxX%nf g e
**             0123456789101112
*/

typedef struct	s_form
{
	int flag[5];
	int width;
	int precision;
	int length;
	int convention;
}				t_form;

int				ft_printf(const char *input, ...);
void			ft_get_form(char **str, va_list *arg, t_form *form);
void			ft_get_form_length(char **str, t_form *form);
void			ft_get_convention(char **str, t_form *form);
void			ft_out(t_form form, va_list *arg, int *cnt);
void			ft_itoa_base(void *num, const char *base);
int				ft_get_len(unsigned long num, unsigned long base_len);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			ft_itoa_base_ull(unsigned long long num, const char *base);
void			ft_putll(long long int num);
void			ft_putwchar(wchar_t c);
void			ft_putull(unsigned long long num);
void			ft_putdouble(double num, t_form form, int len);
double			ft_round_up(double *num, int precision);
void			ft_0(t_form form, va_list *arg, int *cnt);
void			ft_0_0(t_form form, va_list *arg, int *cnt);
void			ft_1(t_form form, va_list *arg, int *cnt);
void			ft_1_0(t_form form, va_list *arg, int *cnt);
void			ft_2(t_form form, va_list *arg, int *cnt);
void			ft_3(t_form form, va_list *arg, int *cnt);
void			ft_3_(t_form form, va_list *arg, int *cnt);
void			ft_3_0(t_form form, va_list *arg, int *cnt);
void			ft_3_1(t_form form, va_list *arg, int *cnt);
void			ft_3_1_0(t_form form, int *cnt);
void			ft_3_1_1(t_form form, int *cnt, long long *ct);
void			ft_3_2(t_form form, va_list *arg, int *cnt);
void			ft_3_3(t_form form, va_list *arg, int *cnt);
void			ft_5(t_form form, va_list *arg, int *cnt);
void			ft_5_(t_form form, va_list *arg, int *cnt);
void			ft_5_0(t_form form, va_list *arg, int *cnt);
void			ft_5_1(t_form form, va_list *arg, int *cnt);
void			ft_5_1_0(t_form form, int *cnt);
void			ft_5_1_1(t_form form, int *cnt, unsigned long long *ct);
void			ft_5_2(t_form form, va_list *arg, int *cnt);
void			ft_5_3(t_form form, va_list *arg, int *cnt);
void			ft_6(t_form form, va_list *arg, int *cnt);
void			ft_6_(t_form form, va_list *arg, int *cnt);
void			ft_6_0(t_form form, va_list *arg, int *cnt);
void			ft_6_1(t_form form, va_list *arg, int *cnt);
void			ft_6_1_0(t_form form, int *cnt);
void			ft_6_1_1(t_form form, int *cnt, unsigned long long *ct);
void			ft_6_2(t_form form, va_list *arg, int *cnt);
void			ft_6_3(t_form form, va_list *arg, int *cnt);
void			ft_7(t_form form, va_list *arg, int *cnt);
void			ft_7_(t_form form, va_list *arg, int *cnt);
void			ft_7_0(t_form form, va_list *arg, int *cnt);
void			ft_7_1(t_form form, va_list *arg, int *cnt);
void			ft_7_1_0(t_form form, int *cnt);
void			ft_7_1_1(t_form form, int *cnt, unsigned long long *ct);
void			ft_7_2(t_form form, va_list *arg, int *cnt);
void			ft_7_3(t_form form, va_list *arg, int *cnt);
void			ft_8(t_form form, int *cnt);
void			ft_9(t_form form, va_list *arg, int *cnt);
void			ft_9_(va_list *arg, int *cnt);
void			ft_9_0(va_list *arg, int *cnt);
void			ft_9_1(va_list *arg, int *cnt);
void			ft_9_2(va_list *arg, int *cnt);
void			ft_9_3(va_list *arg, int *cnt);
void			ft_10(t_form form, va_list *arg, int *cnt);

#endif
