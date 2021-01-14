#include "../includes/ft_printf.h"

/*not finished yet*/
void	ft_7_1(t_form form, va_list *arg, int *cnt)
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
		ft_itoa_base_ull(ct[0], "0123456789ABCDEF");
		while (form.width-- > (int)ct[2])
			ft_putchar_fd(' ', 1);
	}
	else if (form.flag[4])
	{
		if (form.flag[3])
			ft_putstr_fd("0x", 1);
		while (form.width-- > (int)ct[2])
			ft_putchar_fd('0', 1);
		ft_itoa_base_ull(ct[0], "0123456789ABCDEF");
	}
	else
	{
		while (form.width-- > (int)ct[2])
			ft_putchar_fd(' ', 1);
		if (form.flag[3])
			ft_putstr_fd("0x", 1);
		while (ct[3]-- > 0ULL)
			ft_putchar_fd('0', 1);
		ft_itoa_base_ull(ct[0], "0123456789ABCDEF");
	}
}
