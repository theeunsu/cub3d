/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:36:52 by eahn              #+#    #+#             */
/*   Updated: 2024/03/14 15:13:20 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
문자열 s1의 앞과 뒤에 set에 포함된 문자가 있다면 제거해주고 새로운 문자열 배열로 반환해줌
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		rear;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	rear = ft_strlen(s1) - 1;
	while (front <= rear && ft_strchr(set, s1[front]))
		front++;
	if (front > rear)
		return (ft_strdup(s1 + rear + 1));
	while (ft_strchr(set, s1[rear]) && rear >= 0)
		rear--;
	result = malloc(rear - front + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[front], rear - front + 2);
	return (result);
}

/*앞, 뒤에서 한 글자씩 strchr을 이용해서 비교해줌
주의: ft_strchr을 불러올 때 set가 문자열(*s)이 되고
s1[front]와 s1[rear]가 (int c)가 되어 비교 대상 글자가 됨.
*/

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("", ""));
// 	printf("%s\n", ft_strtrim("xhelloyz", "xyz"));
// 	printf("%s\n", ft_strtrim("asd123das", "ads"));
// }

/*
문자열 "asd123das"에서 "123"만 남기고 모두 날리고 싶다면 'a',
	's','d' 이렇게 세 문자를 없애야 하기 때문에 세 문자를 모두 포함한 "asd"를 set으로 넘겨주었다.
그러면 ft_strtrim에서는 앞과 뒤에서 인덱스 하나씩 검사를 하면서 a, s,
	d 셋 중 하나라도 포함되어 있다면 잘라내고 다음 인덱스로 넘어간다.
그렇게 잘라내다가 set에 포함되지 않는 문자, 즉 앞에서 검사하는 부분은 1,
	뒤에서 검사하는 부분은 3을 만날때까지 앞 뒤 모두 잘라내고 남은 문자열의 길이만큼 할당을 해서 새로운 문자열로 만든 후 리턴을 해준다.
만약 모든 문자가 set에 포함되어 있어서 모든 문자가 잘라져야 한다면 빈 문자열을 할당한 후 리턴해준다.
*/