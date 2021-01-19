#include "../includes/ft_printf.h"
/*
	not finished yet
	*/

void ft_1_0(t_form form, va_list *arg, int *cnt)
{
	form.length = -1;
	ft_1(form, arg, cnt);
	/*
	wchar_t	*out;
	int		len;

	
	
	
	out = va_arg(*arg, wchar_t*);
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
	*/
}
