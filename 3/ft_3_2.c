#include "../includes/ft_printf.h"

/*
not finished yet
*/

void ft_3_2(t_form form, va_list *arg, int *cnt)
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
		if (ct[0] == LLMIN)
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
					ft_putstr_fd(LL_STR, 1);
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
					ft_putstr_fd(LL_STR, 1);
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
					ft_putstr_fd(LL_STR, 1);
				}
			}
			else if (form.precision > 20)
			{
				(*cnt) += form.precision;
				ft_putchar_fd('-', 1);
				while (form.precision-- > 20)
					ft_putchar_fd('0', 1);
				ft_putstr_fd(LL_STR, 1);
			}
			else
			{
				(*cnt) += 20;
				ft_putchar_fd('-', 1);
				ft_putstr_fd(LL_STR, 1);
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