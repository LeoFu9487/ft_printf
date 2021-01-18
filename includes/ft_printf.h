#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../Libft/libft.h"

typedef struct  s_form
{
	/*
	[flags][width][.precision][length]specifier


	flags : '-' '+' ' ' '#' '0'
	when there is + and ' ', ignore ' '
	when there is - ignore 0 (only for left pad 0's)
	width: number *
	precision : .number .*
	default 0
	length : l ll h hh
			 0  1 2  3
	*/

	int flag[5];
	int width;
	int precision;
	int length;
	/*
	cspdiuxX%nf g e
	0123456789101112
	*/
	int convention;
}			   t_form;

int		ft_printf(const char *input, ...);
void	ft_get_form(char **str, va_list *arg, t_form *form);
void	ft_out(t_form form, va_list *arg, int *cnt);
void	ft_itoa_base(void* num, const char *base);
void	ft_itoa_base_ull(unsigned long long num, const char *base);
int		ft_putll(long long int num, t_form form);
int		ft_putull(unsigned long long int num, t_form form);
void	ft_putdouble(double num, t_form form, int len);
double	ft_round_up(double *num, int precision);
void	ft_put_flag_e(double num, int sc, t_form form);
void	ft_put_flag_g(double num, t_form form, int *cnt);
void	ft_0(t_form form, va_list *arg, int *cnt);
void	ft_0_0(t_form form, va_list *arg, int *cnt);
void	ft_1(t_form form, va_list *arg, int *cnt);
void	ft_1_0(t_form form, va_list *arg, int *cnt);
void	ft_2(t_form form, va_list *arg, int *cnt);
void	ft_3(t_form form, va_list *arg, int *cnt);
void	ft_3_(t_form form, va_list *arg, int *cnt);
void	ft_3_0(t_form form, va_list *arg, int *cnt);
void	ft_3_1(t_form form, va_list *arg, int *cnt);
void	ft_3_2(t_form form, va_list *arg, int *cnt);
void	ft_3_3(t_form form, va_list *arg, int *cnt);
void	ft_5(t_form form, va_list *arg, int *cnt);
void	ft_5_(t_form form, va_list *arg, int *cnt);
void	ft_5_0(t_form form, va_list *arg, int *cnt);
void	ft_5_1(t_form form, va_list *arg, int *cnt);
void	ft_5_2(t_form form, va_list *arg, int *cnt);
void	ft_5_3(t_form form, va_list *arg, int *cnt);
void	ft_6(t_form form, va_list *arg, int *cnt);
void	ft_6_(t_form form, va_list *arg, int *cnt);
void	ft_6_0(t_form form, va_list *arg, int *cnt);
void	ft_6_1(t_form form, va_list *arg, int *cnt);
void	ft_6_2(t_form form, va_list *arg, int *cnt);
void	ft_6_3(t_form form, va_list *arg, int *cnt);
void	ft_7(t_form form, va_list *arg, int *cnt);
void	ft_7_(t_form form, va_list *arg, int *cnt);
void	ft_7_0(t_form form, va_list *arg, int *cnt);
void	ft_7_1(t_form form, va_list *arg, int *cnt);
void	ft_7_2(t_form form, va_list *arg, int *cnt);
void	ft_7_3(t_form form, va_list *arg, int *cnt);
void	ft_8(t_form form, va_list *arg, int *cnt);
void	ft_9(t_form form, va_list *arg, int *cnt);
void	ft_9_(t_form form, va_list *arg, int *cnt);
void	ft_9_0(t_form form, va_list *arg, int *cnt);
void	ft_9_1(t_form form, va_list *arg, int *cnt);
void	ft_9_2(t_form form, va_list *arg, int *cnt);
void	ft_9_3(t_form form, va_list *arg, int *cnt);
void	ft_10(t_form form, va_list *arg, int *cnt);
void	ft_11(t_form form, va_list *arg, int *cnt);
void	ft_12(t_form form, va_list *arg, int *cnt);

#endif
