#include "../includes/ft_printf.h"

wchar_t	*ft_strdup_util(const char *source)
{
	wchar_t	*ans;
	int		len;
	int		i;

	len = ft_strlen(source);
	if (!(ans = (wchar_t*)malloc((len + 1) * sizeof(wchar_t))))
		return (NULL);
	i = -1;
	while (++i < len)
		ans[i] = (wchar_t)source[i];
	ans[i] = '\0';
	return (ans);
}
