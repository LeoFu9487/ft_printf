#include "ft_printf.h"

/*
flags : '-' '+' ' ' '#' '0'
	when there is + and ' ', ignore ' '
	when there is - ignore 0 (only for left pad 0's)
	width: number *
	precision : .number .*
	default 0
	length : l ll h hh
			 0  1 2  3
	convention :
	cspdiuxX%nf g e
	0123456789101112
*/
static void ft_0(t_form form, va_list *arg, int *cnt)
{
	/*
	c
	length 0 not finished yet
	*/
	if (form.width > 1 && form.flag[0] == 0)
	{
		(*cnt) += form.width;
		if (form.flag[4])
			while ((form.width)-- > 1)
				ft_putchar_fd('0', 1);
		else
			while ((form.width)-- > 1)
				ft_putchar_fd(' ', 1);
		ft_putchar_fd(va_arg(*arg, int), 1);
	}
	else
	{
		ft_putchar_fd(va_arg(*arg, int), 1);
		if (form.width > 1)
		{
			(*cnt) += form.width;
			while ((form.width)-- > 1)
			ft_putchar_fd(' ', 1);
		}
		else
			(*cnt)++;
	}
}
static void ft_1(t_form form, va_list *arg, int *cnt)
{
	char	*out;
	int	 len;

	/*
	s
	length 0 not finished yet
	*/
	out = va_arg(*arg, char*);
	if (out == NULL)
	{
		if (form.precision == -1)
			out = ft_strdup("(null)");
		else
			out = ft_substr("(null)", 0, form.precision);
	}
	else if (form.precision != -1)
		out = ft_substr(out, 0, form.precision);
	else
		out = ft_strdup(out);
	len = ft_strlen(out);
	if (form.width > len)
	{
		(*cnt) += form.width;
		if (form.flag[0] == 0)
		{
			if (form.flag[4])
				while (form.width-- > len)
					ft_putchar_fd('0', 1);
			else
				while (form.width-- > len)
					ft_putchar_fd(' ', 1);
		}
		ft_putstr_fd(out, 1);
		if (form.flag[0])
			while (form.width-- > len)
				ft_putchar_fd(' ', 1);
		return ;
	}
	(*cnt) += len;
	ft_putstr_fd(out, 1);
	free(out);
}
static void ft_2(t_form form, va_list *arg, int *cnt)
{
	// p
	if (form.width > 8)
	{
		(*cnt) += form.width;
		if (form.flag[0])
		{
			ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
			while (form.width-- > 8)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (form.width-- > 8)
				ft_putchar_fd(' ', 1);
			ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
		}
	}
	else
	{
		(*cnt) += 8;
		ft_itoa_base(va_arg(*arg, void*), "0123456789ABCDEF");
	}
}

static void ft_3_0(t_form form, va_list *arg, int *cnt)
{
	//ld
}

static void ft_3_1(t_form form, va_list *arg, int *cnt)
{
	/*
	problem : +, - , ' '(sign) should be the first
	deal with LLONG_MIN separately
	deal with 0 separately
	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	if left pad 0 then sign before 0
	if left pad ' ' then ' ' before sign
	*/
	//lld
	long long int   ct[4];

	ct[1] = ct[0] = va_arg(*arg, long long int);
	if (ct[0] == 0LL && form.precision == 0)
	{
		if (form.flag[0])
		{
			if (form.flag[1])
			{
				ft_putchar_fd('+', 1);
				(*cnt)++;
				(form.width)--;
			}
			else if (form.flag[2])
			{
				ft_putchar_fd(' ', 1);
				(*cnt)++;
				(form.width)--;
			}
			if (form.width > 0)
				(*cnt) += form.width;
			while ((form.width)-- > 0)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			if (form.flag[1] || form.flag[2])
			{
				(*cnt)++;
				(form.width)--;
			}
			if (form.width > 0)
				(*cnt) += form.width;
			while ((form.width)-- > 0)
				ft_putchar_fd(' ', 1);
			if (form.flag[1])
				ft_putchar_fd('+', 1);
			else if (form.flag[2])
				ft_putchar_fd(' ', 1);
		}
		return ;
	}
	ct[2] = 1LL;
	while (ct[1] > 9LL || ct[1] < -9LL)
	{
		ct[2]++;
		ct[1] /= 10LL;
	}


	if (form.precision != -1)
		form.flag[4] = 0;
	if (ct[0] < 0LL)
	{
		form.precision++;
		if (ct[0] == -9223372036854775808LL)
		{
			if (form.width > 20 && form.width > form.precision)
			{
				(*cnt) += form.width;
				if (form.flag[0])
				{
					ft_putchar_fd('-', 1);
					ct[3] = (long long int)form.precision;
					while (ct[3]-- > 20)
						ft_putchar_fd('0', 1);
					ft_putstr_fd("9223372036854775808", 1);
					while (form.width > 20 && form.width > form.precision)
					{
						ft_putchar_fd(' ', 1);
						form.width--;
					}
				}
				else if (form.flag[4])
				{
					//sign, left pad 0
					ft_putchar_fd('-', 1);
					while (form.width > 20 && form.width > form.precision)
					{
						ft_putchar_fd('0', 1);
						form.width--;
					}
					ft_putstr_fd("9223372036854775808", 1);
				}
				else
				{
					//left pad ' ', sign
					while (form.width > 20 && form.width > form.precision)
					{
						ft_putchar_fd(' ', 1);
						form.width--;
					}
					ft_putchar_fd('-', 1);
					while ((form.precision)-- > 20)
						ft_putchar_fd('0', 1);
					ft_putstr_fd("9223372036854775808", 1);
				}
			}
			else if (form.precision > 20)
			{
				(*cnt) += form.precision;
				ft_putchar_fd('-', 1);
				while (form.precision-- > 20)
					ft_putchar_fd('0', 1);
				ft_putstr_fd("9223372036854775808", 1);
			}
			else
			{
				(*cnt) += 20;
				ft_putstr_fd("-9223372036854775808", 1);
			}
			return ;
		}
		else
			ct[0] *= -1LL;
		(form.precision)--;
		(form.width)--;
		if (form.width > (int)ct[2] && form.width > form.precision)
		{
			(*cnt) += form.width + 1;
			if (form.flag[0])
			{
				ft_putchar_fd('-', 1);
				ft_putll(ct[0], form);
				while (form.width > (int)ct[2] && form.width > form.precision)
				{
					form.width--;
					ft_putchar_fd(' ', 1);
				}
			}
			else if (form.flag[4])
			{
				ft_putchar_fd('-', 1);
				while (form.width > (int)ct[2] && form.width > form.precision)
				{
					ft_putchar_fd('0', 1);
					form.width--;
				}
				ft_putll(ct[0], form);
			}
			else
			{
				while (form.width > (int)ct[2] && form.width > form.precision)
				{
					ft_putchar_fd(' ', 1);
					form.width--;
				}
				ft_putchar_fd('-', 1);
				ft_putll(ct[0], form);
			}
		}
		else
		{
			ft_putchar_fd('-', 1);
			(*cnt) += ft_putll(ct[0], form) + 1;
		}
		return ;
	}
	if (form.width > (int)ct[2] && form.width > form.precision)
	{
		(*cnt) += form.width;
		if (form.flag[0])
		{
			if (form.flag[1])
			{
				ft_putchar_fd('+', 1);
				form.width--;
			}
			else if (form.flag[2])
			{
				ft_putchar_fd(' ', 1);
				form.width--;
			}
			ft_putll(ct[0], form);
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				form.width--;
				ft_putchar_fd(' ', 1);
			}
		}
		else if (form.flag[4])
		{
			if (form.flag[1])
			{
				ft_putchar_fd('+', 1);
				form.width--;
			}
			else if (form.flag[2])
			{
				ft_putchar_fd(' ', 1);
				form.width--;
			}
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				ft_putchar_fd('0', 1);
				form.width--;
			}
			ft_putll(ct[0], form);
		}
		else
		{
			if (form.flag[1] || form.flag[2])
				form.width--;
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				ft_putchar_fd(' ', 1);
				form.width--;
			}
			if (form.flag[1])
				ft_putchar_fd('+', 1);
			else if (form.flag[2])
				ft_putchar_fd(' ', 1);
			ft_putll(ct[0], form);
		}
	}
	else
	{
		//no width
		if (form.flag[1])
		{
			ft_putchar_fd('+', 1);
			(*cnt)++;
		}

		else if (form.flag[2])
		{
			(*cnt)++;
			ft_putchar_fd(' ', 1);
		}
		(*cnt) += ft_putll(ct[0], form);
	}
}

static void ft_3_2(t_form form, va_list *arg, int *cnt)
{
	//hd
}

static void ft_3_3(t_form form, va_list *arg, int *cnt)
{
	//hhd
}

static void ft_3_(t_form form, va_list *arg, int *cnt)
{
	//d
}

static void ft_3(t_form form, va_list *arg, int *cnt)
{
	//%d
	/*
	flags : - + ' ' 0 (0 1 2 4), ignore 0 while -,0 ignore ' ' while + ' '
	width : yes
	precision : yes
	length : yes
	*/
	/*
	length -> precision -> flags + width
	*/
	if (form.length == 0)
		ft_3_0(form, arg, cnt);
	else if (form.length == 1)
		ft_3_1(form, arg, cnt);
	else if (form.length == 2)
		ft_3_2(form, arg, cnt);
	else if (form.length == 3)
		ft_3_3(form, arg, cnt);
	else
		ft_3_(form, arg, cnt);
}

static void ft_5_0(t_form form, va_list *arg, int *cnt)
{

}

static void ft_5_1(t_form form, va_list *arg, int *cnt)
{
	unsigned long long int   ct[4];

	ct[1] = ct[0] = va_arg(*arg, unsigned long long int);
	if (ct[0] == 0ULL && form.precision == 0)
	{
		(*cnt) += form.width;
		while ((form.width)-- > 0)
			ft_putchar_fd(' ', 1);
		return ;
	}
	ct[2] = 1ULL;
	while (ct[1] > 9ULL)
	{
		ct[2]++;
		ct[1] /= 10ULL;
	}
	if (form.precision != -1)
		form.flag[4] = 0;
	if (form.width > (int)ct[2] && form.width > form.precision)
	{
		(*cnt) += form.width;
		if (form.flag[0])
		{
			ft_putull(ct[0], form);
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				form.width--;
				ft_putchar_fd(' ', 1);
			}
		}
		else if (form.flag[4])
		{
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				ft_putchar_fd('0', 1);
				form.width--;
			}
			ft_putull(ct[0], form);
		}
		else
		{
			while (form.width > (int)ct[2] && form.width > form.precision)
			{
				ft_putchar_fd(' ', 1);
				form.width--;
			}
			ft_putull(ct[0], form);
		}
	}
	else
	{
		(*cnt) += ft_putull(ct[0], form);
	}
}

static void ft_5_2(t_form form, va_list *arg, int *cnt)
{

}

static void ft_5_3(t_form form, va_list *arg, int *cnt)
{

}

static void ft_5_(t_form form, va_list *arg, int *cnt)
{

}

static void ft_5(t_form form, va_list *arg, int *cnt)
{
	//u
	if (form.length == 0)
		ft_5_0(form, arg, cnt);
	else if (form.length == 1)
		ft_5_1(form, arg, cnt);
	else if (form.length == 2)
		ft_5_2(form, arg, cnt);
	else if (form.length == 3)
		ft_5_3(form, arg, cnt);
	else
		ft_5_(form, arg, cnt);
}

static void ft_6_0(t_form form, va_list *arg, int *cnt)
{

}

static void ft_6_1(t_form form, va_list *arg, int *cnt)
{
	unsigned long long  ct[4];
	/*
	flag : -(0) #(3) 0(4)
	output order : space -> 0x -> 0(left-pad)
	(done)if there is precision, ignore flag[4]
	precision doesn't contain 0x
	=>
	counting len : precision then width
	*/
	ct[1] = ct[0] = va_arg(*arg, unsigned long long);
	if (form.precision != -1)
		form.flag[4] = 0;
	else
		form.precision = 1;
	if (ct[0] == 0ULL)
	{
		(*cnt) += (form.width > form.precision ? form.width : form.precision);
		if (form.flag[0])
		{
			form.width -= form.precision;
			while (form.precision-- > 0)
				ft_putchar_fd('0', 1);
			while (form.width-- > 0)
				ft_putchar_fd(' ', 1);
		}
		else if (form.flag[4])
		{
			while (form.width-- > form.precision)
				ft_putchar_fd('0', 1);
		}
		else
		{
			while (form.width-- > form.precision)
				ft_putchar_fd(' ', 1);
			while (form.precision-- > 0)
				ft_putchar_fd('0', 1);
		}
		return ;
	}
	ct[2] = 1ULL;
	while (ct[1] > 15ULL)
	{
		ct[2]++;
		ct[1] /= 16ULL;
	}
	//ct[2]->0 additional part of cnt
	ct[3] = 0ULL; // 0 to output
	if (form.precision > (int)ct[2])
	{
		ct[3] = (unsigned long long)form.precision - ct[2];
		ct[2] = form.precision;
	}
	if (form.flag[3])
		ct[2] += 2ULL;
	(*cnt) += (form.width > (int)ct[2] ? form.width : (int)ct[2]);
	if (form.flag[0])
	{
		if (form.flag[3])
			ft_putstr_fd("0x", 1);
		while (ct[3]-- > 0ULL)
			ft_putchar_fd('0', 1);
		ft_itoa_base_ull(ct[0], "0123456789abcdef");
		while (form.width-- > (int)ct[2])
			ft_putchar_fd(' ', 1);
	}
	else if (form.flag[4])
	{
		if (form.flag[3])
			ft_putstr_fd("0x", 1);
		while (form.width-- > (int)ct[2])
			ft_putchar_fd('0', 1);
		ft_itoa_base_ull(ct[0], "0123456789abcdef");
	}
	else
	{
		while (form.width-- > (int)ct[2])
			ft_putchar_fd(' ', 1);
		if (form.flag[3])
			ft_putstr_fd("0x", 1);
		while (ct[3]-- > 0ULL)
			ft_putchar_fd('0', 1);
		ft_itoa_base_ull(ct[0], "0123456789abcdef");
	}
}

static void ft_6_2(t_form form, va_list *arg, int *cnt)
{

}

static void ft_6_3(t_form form, va_list *arg, int *cnt)
{

}

static void ft_6_(t_form form, va_list *arg, int *cnt)
{

}

static void ft_6(t_form form, va_list *arg, int *cnt)
{
	//x
	if (form.length == 0)
		ft_6_0(form, arg, cnt);
	else if (form.length == 1)
		ft_6_1(form, arg, cnt);
	else if (form.length == 2)
		ft_6_2(form, arg, cnt);
	else if (form.length == 3)
		ft_6_3(form, arg, cnt);
	else
		ft_6_(form, arg, cnt);
}
static void ft_7(t_form form, va_list *arg, int *cnt)
{
	//X
	//same as ft_6
}

static void	ft_8(t_form form, va_list *arg, int *cnt)
{
	//%% 
	//try precision zero
	form.width = (form.width < 1 ? 1 : form.width);
	(*cnt) += form.width;
	if (!form.flag[0])
	{
		while (form.width-- > 1)
		{
			if (form.flag[4])
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
	}
	ft_putchar_fd('%', 1);
	if (form.flag[0])
	{
		while (form.width-- > 1)
			ft_putchar_fd(' ', 1);
	}
}

static void ft_9_0(t_form form, va_list *arg, int *cnt)
{

}

static void ft_9_1(t_form form, va_list *arg, int *cnt)
{

}

static void ft_9_2(t_form form, va_list *arg, int *cnt)
{

}

static void ft_9_3(t_form form, va_list *arg, int *cnt)
{

}

static void ft_9_(t_form form, va_list *arg, int *cnt)
{
	int *va;

	va = va_arg(*arg, int*);
	*va = *cnt;
}

static void ft_9(t_form form, va_list *arg, int *cnt)
{
	//n
	if (form.length == 0)
		ft_9_0(form, arg, cnt);
	else if (form.length == 1)
		ft_9_1(form, arg, cnt);
	else if (form.length == 2)
		ft_9_2(form, arg, cnt);
	else if (form.length == 3)
		ft_9_3(form, arg, cnt);
	else
		ft_9_(form, arg, cnt);
}
static void ft_10(t_form form, va_list *arg, int *cnt)
{
	double  ct[3];
	int	 use[5];
	//f
	/*
	flags : all
	'-' '+' ' ' '#' '0'
	precision
	*/
	ct[0] = va_arg(*arg, double);
	if (form.flag[0])
		form.flag[4] = 0;
	if (ct[0] > 1.7976931348623158e+308 || ct[0] < -1.7976931348623158e+308)
	{
		// if it shows inf, +inf, -inf etc. and ignore flag[4]
		use[0] = 3;
		if (ct[0] < 0.0 || form.flag[1] || form.flag[2])
			use[0]++;
		form.width = (use[0] > form.width ? use[0] : form.width);
		(*cnt) += form.width;
		if (!form.flag[0])
		{
			//activate this if the flag[4] works
			/*if (form.flag[4])
				while (form.width-- > use[0])
					ft_putchar_fd('0', 1);
			else*/
				while (form.width-- > use[0])
					ft_putchar_fd(' ', 1);
		}
		if (ct[0] < 0.0)
			ft_putchar_fd('-', 1);
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("inf", 1);
		while ((form.width)-- > use[0])
			ft_putchar_fd(' ', 1);
		return ;
	}
	if (form.precision == -1)
		form.precision = 6;
	ct[1] = ft_round_up(ct, form.precision);
	//round up ct[1] and  here
	use[0] = 1;//count the digits before the decimal point
	if (ct[1] < 0.0)
		ct[1] *= -1.0;
	while (ct[1] >= 10.0)
	{
		ct[1] /= 10.0;
		use[0]++;
	}
	use[1] = use[0]; // the output length without width
	if (form.precision != 0)
		use[1] += form.precision + 1;
	else if (form.flag[3])
		use[1]++;
	if (ct[0] < 0.0 || form.flag[1] || form.flag[2])
		use[1]++;
	form.width -= use[1];
	(*cnt) += use[1];
	if (form.width > 0)
		(*cnt) += form.width;
	if (form.flag[0])
	{
		/*
			sign(+,-,' ') number . precision + ' '
		*/
		if (ct[0] < 0.0)
		{
			ft_putchar_fd('-', 1);
			ct[0] *= -1.0;
		}
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putdouble(ct[0], form, use[0]); // care about precision and flag[3]
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (form.flag[4])
	{
		/*
		sign + '0' + number . precision
		*/
		if (ct[0] < 0.0)
		{
			ft_putchar_fd('-', 1);
			ct[0] *= -1.0;
		}
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		while (form.width-- > 0)
			ft_putchar_fd('0', 1);
		ft_putdouble(ct[0], form, use[0]);
	}
	else
	{
		while (form.width-- > 0)
			ft_putchar_fd(' ', 1);
		if (ct[0] < 0.0)
		{
			ft_putchar_fd('-', 1);
			ct[0] *= -1.0;
		}
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putdouble(ct[0], form, use[0]);
	}
}
static void ft_11(t_form form, va_list *arg, int *cnt)
{
	//g
	double	n[5];
	int		ct[5];

	n[0] = va_arg(*arg, double);
	if (form.precision == -1)
		form.precision = 6;
	if (n[0] > 1.7976931348623158e+308 || n[0] < -1.7976931348623158e+308)
	{
		// if it shows inf, +inf, -inf etc. and ignore flag[4]
		ct[0] = 3;
		if (n[0] < 0.0 || form.flag[1] || form.flag[2])
			ct[0]++;
		form.width = (ct[0] > form.width ? ct[0] : form.width);
		(*cnt) += form.width;
		if (!form.flag[0])
		{
			// activate this if flag[4] works
			/*if (form.flag[4])
				while (form.width-- > ct[0])
					ft_putchar_fd('0', 1);
			else*/
				while (form.width-- > ct[0])
					ft_putchar_fd(' ', 1);
		}
		if (n[0] < 0.0)
			ft_putchar_fd('-', 1);
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("inf", 1);
		while ((form.width)-- > ct[0])
			ft_putchar_fd(' ', 1);
		return ;
	}
	ft_put_flag_g(n[0], form, cnt);
}
static void ft_12(t_form form, va_list *arg, int *cnt)
{
	//e
	/*
	1.7E +/- 308 (15 digits)
	flag : all
	precision : yes
	*/
	/*
	[number]e[sign][two digits or three digits]
	*/
	double	n[5];
	int		ct[5];

	ct[4] = 1;
	n[0] = va_arg(*arg, double);
	if (form.precision == -1)
		form.precision = 6;
	if (n[0] > 1.7976931348623158e+308 || n[0] < -1.7976931348623158e+308)
	{
		// if it shows inf, +inf, -inf etc. and ignore flag[4]
		ct[0] = 3;
		if (n[0] < 0.0 || form.flag[1] || form.flag[2])
			ct[0]++;
		form.width = (ct[0] > form.width ? ct[0] : form.width);
		(*cnt) += form.width;
		if (!form.flag[0])
		{
			// activate this if flag[4] works
			/*if (form.flag[4])
				while (form.width-- > ct[0])
					ft_putchar_fd('0', 1);
			else*/
				while (form.width-- > ct[0])
					ft_putchar_fd(' ', 1);
		}
		if (n[0] < 0.0)
			ft_putchar_fd('-', 1);
		else if (form.flag[1])
			ft_putchar_fd('+', 1);
		else if (form.flag[2])
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("inf", 1);
		while ((form.width)-- > ct[0])
			ft_putchar_fd(' ', 1);
		return ;
	}
	ct[0] = 0;
	if (n[0] < 0.0)
	{
		n[0] *= -1.0;
		ct[4] = -1;
	}
	while (n[0] >= 10.0)
	{
		n[0] /= 10.0;
		ct[0]++;
	}
	while (n[0] < 1.0)
	{
		n[0] *= 10.0;
		ct[0]--;
	}
	ft_round_up(n, form.precision);
	if (n[0] >= 10.0)
	{
		n[0] /= 10.0;
		ct[0]++;
	}
	//ct[1] for counting the length of output
	ct[1] = 5; // the number before decimal point and the scientific notation : e+99
	if (form.precision || form.flag[3])
		ct[1] += 1 + form.precision;
	if (ct[0] > 99 || ct[0] < -99)
		ct[1] += 1;
	if (ct[4] == -1 || form.flag[1] || form.flag[2])
		ct[1]++;
	form.width = (ct[1] > form.width ? ct[1] : form.width);
	(*cnt) += form.width;
	//' '-> sign->'0'
	if ((!form.flag[0]) && (!form.flag[4]))
		while (form.width-- > ct[1])
			ft_putchar_fd(' ', 1);
	if (ct[4] == -1)
		ft_putchar_fd('-', 1);
	else if (form.flag[1])
		ft_putchar_fd('+', 1);
	else if (form.flag[2])
		ft_putchar_fd(' ', 1);
	if (!(form.flag[0]) && form.flag[4])
		while (form.width-- > ct[1])
			ft_putchar_fd('0', 1);
	/*
	put the number, consider the flag[3] and precision
	*/
	ft_put_flag_e(n[0], ct[0], form);
	if (form.flag[0])
		while (form.width-- > ct[1])
			ft_putchar_fd(' ', 1);
}

void	ft_out(t_form form, va_list *arg, int *cnt)
{
	if (form.convention == 0)
		ft_0(form, arg, cnt);
	if (form.convention == 1)
		ft_1(form, arg, cnt);
	if (form.convention == 2)
		ft_2(form, arg, cnt);
	if (form.convention == 3 || form.convention == 4)
		ft_3(form, arg, cnt);
	if (form.convention == 5)
		ft_5(form, arg, cnt);
	if (form.convention == 6)
		ft_6(form, arg, cnt);
	if (form.convention == 7)
		ft_7(form, arg, cnt);
	if (form.convention == 8)
		ft_8(form, arg, cnt);
	if (form.convention == 9)
		ft_9(form, arg, cnt);
	if (form.convention == 10)
		ft_10(form, arg, cnt);
	if (form.convention == 11)
		ft_11(form, arg, cnt);
	if (form.convention == 12)
		ft_12(form, arg, cnt);
}
