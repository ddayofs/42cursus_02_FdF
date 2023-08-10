#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./00libft/libft.h"

// typedef struct s_info
// {
// 	int	a;
// 	int	b;
// 	int	c;
// }t_info;

// t_info *make_info_arr()
// {
// 	t_info	*ret;

// 	ret= (t_info *)malloc(sizeof(t_info) * 3);
// 	return (ret);
// }

// void	input_777(t_info *info)
// {
// 	info[0].a = 777;
// }
// int main()
// {
// 	t_info	*info;

// 	info = make_info_arr();
// 	printf("%d\n", info[0].a);
// 	input_777(info);
// 	printf("%d\n", info[0].a);
// }


// // static int	find_idx(char c, char *base)
// // {
// // 	int	i;

// // 	i = -1;
// // 	while (base[++i])
// // 		if (c == base[i])
// // 			return (i);
// // 	return (-1);
// // }

// // static int	bonus_condi_chk(const char *str, int sign, long integer, int b_len)
// // {
// // 	if (sign == 1 && ((integer > LONG_MAX / b_len)
// // 			|| ((integer == LONG_MAX / b_len && *str - '0'
// // 					> LONG_MAX % b_len))))
// // 		return (-1);
// // 	else if (sign == -1 && ((integer > -1 * (LONG_MIN / b_len)
// // 				|| (integer == -1 * (LONG_MIN / b_len)
// // 					&& *str - '0' > -1 * (LONG_MIN % b_len)))))
// // 		return (0);
// // 	else
// // 		return (1);
// // }

// // static int	push_left(const char *str, char *base, int b_len, long *integer)
// // {
// // 	int	idx;

// // 	idx = find_idx(*str, base);
// // 	if (idx == -1)
// // 		return (1);
// // 	*integer = b_len * (*integer) + idx;
// // 	return (0);
// // }

// // static int	make_int(const char *str, int sign, long integer)
// // {
// // 	char	*base;
// // 	int		b_len;
// // 	int		bonus_flag;

// // 	base = "0123456789";
// // 	b_len = 10;
// // 	if (*str == '0' && *(str + 1) == 'x')
// // 	{
// // 		base = "0123456789abcdef";
// // 		b_len = 16;
// // 		str += 2;
// // 	}
// // 	while (1)
// // 	{
// // 		bonus_flag = bonus_condi_chk(str, sign, integer, b_len);
// // 		if (bonus_flag != 1)
// // 			return (bonus_flag);
// // 		else
// // 			if (push_left(str, base, b_len, &integer))
// // 				break ;
// // 		str++;
// // 	}
// // 	return (sign * (int)integer);
// // }

// // int	ft_atoi(const char *str)
// // {
// // 	long	integer;
// // 	int		sign;

// // 	integer = 0;
// // 	sign = 1;
// // 	while (*str == ' ' || (9 <= *str && *str <= 13))
// // 		str++;
// // 	if (*str == 43 || *str == 45)
// // 		sign = 44 - *(str++);
// // 	return (make_int(str, sign, integer));
// // }
// // int main()
// // {
// // 	printf("%d\n", ft_atoi("0x7fffffff"));
// // }

// // int main()
// // {
// // 	free(NULL);
// // }

// int main()
// {
// 	double a = atan(1.0 / sqrt(2.0));
// 	printf("%f\n", a);
// }

// C program for DDA line generation

// int main()
// {

// 	double a = 2.5;
// 	double b = 3.49;
// 	// int c = round(a - b);
// 	int d = round(fabs(a - b));
// 	// printf("%d\n", c);
// 	printf("%d\n", d);
// }

// int main()
// {
// 	printf("%d\n", 0x0F);
// 	printf("%d\n", 0x0f);
// }

// int main()
// {
// 	char str[100] = "       orange is good for your health       \n";

// 	printf("%s",str);
// 	printf("\n");
// 	printf("%s",ft_strtrim(str, " \n"));
// }

// int main()
// {
// 	int x = 4;
// 	int	y = 3;
// 	double z = x / y;
// 	printf("%f\n", z);
// }

// #include <stdio.h>
// #include <math.h>

// // DDA 알고리즘 함수
// void drawLineDDA(float x1, float y1, float x2, float y2) {
//     float dx = x2 - x1;
//     float dy = y2 - y1;
//     int steps, k;
//     float xIncrement, yIncrement, x = x1, y = y1;

//     // 기울기 절댓값이 1보다 큰 경우
//     if (fabs(dx) > fabs(dy)) {
//         steps = fabs(dx);
//     }
//     // 기울기 절댓값이 1보다 작거나 같은 경우
//     else {
//         steps = fabs(dy);
//     }

//     xIncrement = dx / steps;
//     yIncrement = dy / steps;

//     printf("DDA 그린 선분 좌표:\n");

//     for (k = 0; k < steps; k++) {
//         printf("(%f, %f)\n", x, y);
//         x += xIncrement;
//         y += yIncrement;
//     }
//     // 마지막 점 출력
//     printf("(%f, %f)\n", x2, y2);
// }

// int main() {
//     float x1, y1, x2, y2;
    
//     printf("첫번째 점의 x, y 좌표를 입력하세요: ");
//     scanf("%f %f", &x1, &y1);
    
//     printf("두번째 점의 x, y 좌표를 입력하세요: ");
//     scanf("%f %f", &x2, &y2);

//     drawLineDDA(x1, y1, x2, y2);

//     return 0;
// }

// #include <stdio.h>
// #include <math.h>

// // DDA 알고리즘 함수
// void drawLineDDA(int x1, int y1, int x2, int y2) {
//     int dx = x2 - x1;
//     int dy = y2 - y1;
//     int steps, k;
//     float xIncrement, yIncrement, x = x1, y = y1;

//     // 기울기 절댓값이 1보다 큰 경우
//     if (fabs(dx) > fabs(dy)) {
//         steps = fabs(dx);
//     }
//     // 기울기 절댓값이 1보다 작거나 같은 경우
//     else {
//         steps = fabs(dy);
//     }

//     xIncrement = (float)dx / steps;
//     yIncrement = (float)dy / steps;

//     printf("DDA 그린 선분 좌표:\n");

//     for (k = 0; k < steps; k++) {
//         printf("(%d, %d)\n", (int)x, (int)y);
//         x += xIncrement;
//         y += yIncrement;
//     }
//     // 마지막 점 출력
//     printf("(%d, %d)\n", x2, y2);
// }

// int main() {
//     int x1, y1, x2, y2;
    
//     printf("첫번째 점의 x, y 좌표를 입력하세요: ");
//     scanf("%d %d", &x1, &y1);
    
//     printf("두번째 점의 x, y 좌표를 입력하세요: ");
//     scanf("%d %d", &x2, &y2);

//     drawLineDDA(x1, y1, x2, y2);

//     return 0;
// }
