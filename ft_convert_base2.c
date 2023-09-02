


char *ft_convert_base2(int nb,char *base);

char *skip_spaces(char *str)
{
	int i;

	while(*str)
	{
		if(*str==' ' || (*str>=9 && *str<=13))
			str++;
		else
		       	break;
	}
	return str;
}

int check_base(char *base)
{
	int i;
	int j;

	i=0;
	while(base[i])
	{
		i=j+1;
		while(base[j])
		{
			if(base[i]==base[j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int ft_strlen(char *str)
{
	int i;

	i=0;
	while(str[i])
		i++;
	return i;
}

int in_base(char c,char *base)
{
	int i;
	int j;

	i = 0;
	while(base[i])
	{
		if(c == base[i])
			return i;
		i++;
	}
	return -1;
}


int ft_atoi_base(char *str,char *base)
{
	int i;
	int base_len;
	int result;
	int sign;

	if(check_base(base))
		return 0;
	base_len = ft_strlen(base);
	result = 0;
	str = skip_spaces(str);
	sign = 1;
	i=0;
	while(*str=='-' || *str =='+')
	{
		if(*str=='-')
			sign*=-1;
		str++;
	}
	while(in_base(*str,base) != -1)
	{
		result = result * base_len + in_base(*str,base);
		str++;
	}
	return (result * sign);
}

char *ft_convert_base(char *nb,char *base_from, char *base_to)
{
	char *p;
	int x;

	x = ft_atoi_base(nb,base_from);
	p = ft_convert_base2(x,base_to);
	return p;
}
#include<stdio.h>

int main()
{
	char *base_from="01";
	char *base_to = "0123456789abcdef";
	char *str="       				--++--1011pjjj";
	char *x = ft_convert_base(str,base_from,base_to);
	printf("%s\n",x);
}









