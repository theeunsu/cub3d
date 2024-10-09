/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:40:39 by eahn              #+#    #+#             */
/*   Updated: 2024/03/14 14:43:57 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
문자열 s를 구분 문자인 c에 맞춰서 잘라낸 후 문자열들의 배열을 만들어 리턴해주는 함수 즉, 이중 포인터에 저장하는 함수
Allocates (with malloc(3)) and returns an array of strings obtained
by splitting 's' using the character 'c' as a delimeter.
The array must end with a NULL pointer.
*/

#include "libft.h"

static void	free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	split_str(char const *str, char c, char **result, int i)
{
	int	w_len;

	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			w_len = 0;
			while (*str != c && *str)
			{
				str++;
				w_len++;
			}
			result[i] = (char *)malloc(w_len + 1);
			if (!result[i])
			{
				free_strs(result);
				return (-1);
			}
			ft_strlcpy((char *)result[i++], (char *)str - w_len, w_len + 1);
		}
	}
	result[i] = NULL;
	return (1);
}

/* ft_strlcpy를 이용하여 단어를 result 배열에 복사 후 다음 인덱스로 이동
위의 while 구문을 통해 str++, len++을 증가시켜 문자의 끝에 도달하였으니
str - len을 해줘서 문자의 시작점으로 돌아와 그 지점부터 단어를 복사하여 result에 저장해준다 */

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if ((split_str(s, c, result, 0)) == -1)
		return (NULL);
	return (result);
}

// //정적 선언: 이 함수는 유틸리티 함수로 파일 범위에서만 접근 가능, 모듈성 증가, 외부 접근 방지
// static void	free_strs(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		free(str[i++]); //각 문자열에 할당된 메모리 해제 후 다음 문자열로 이동
// 	free(str);          // 문자열 배열의 메모리 해제
// }

// static int	count_words(char const *str, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			count++;
// 			while (str[i] && str[i] != c) /*단어의 끝까지(구분 문자 나오기 전) 이동*/
// 				i++;
// 		}
// 		else
// 			i++; /* 현재 문자가 구분 문자인 경우, 다음 문자로 이동 */
// 	}
// 	return (count); // 구분된 단어의 개수 반환
// }

// static int	split_str(char const *str, char c, char **result, int i)
// {
// 	int	len;

// 	while (*str)
// 	{
// 		if (*str == c)
// 			str++;
// 		else
// 		{
// 			len = 0;
// 			while (*str != c && *str)
// 			{
// 				str++;
// 				len++; //단어의 길이 증가
// 			}
// 			result[i] = (char *)malloc(len + 1); //단어의 길이만큼 각 배열에 메모리 할당
// 			if (!result[i])
// 			{
// 				free_strs(result); //이미 할당된 메모리 해제
// 				return (-1);       //에러코드 반환
// 			}
// 			ft_strlcpy((char *)result[i++], (char *)str - len, len + 1);
// 		}
// 	}
// 	result[i] = NULL; //문자열의 끝을 표시하기 위해 NULL 추가
// 	return (1);       //성공코드 반환
// }

// /* ft_strlcpy를 이용하여 단어를 result 배열에 복사 후 다음 인덱스로 이동
// 위의 while 구문을 통해 str++, len++을 증가시켜 문자의 끝에 도달하였으니
// str - len을 해줘서 문자의 시작점으로 돌아와 그 지점부터 단어를 복사하여 result에 저장해준다 */

// char	**ft_split(char const *s, char c)
// {
// 	char	**result;

// 	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	//단어의 개수에 따라 메모리 할당
// 	if (!result) //할당 실패시
// 		return (NULL);
// 	if ((split_str(s, c, result, 0)) == -1)
// 		return (NULL);
// 	return (result); //분할된 문자열 배열 반환
// }
/* split_str 부분은 문자열을 단어로 분할하는 작업 수행,
split_str 함수가 실패했을 때 - 1을 반환(일반적으로 함수가 오류 상태에 있는 경우를 나타냄) */

// int	main(void)
// {
// 	char **str = ft_split("aaa123a456aaaa78ba", 'a');
// 	if (!str)
// 	{
// 		printf("Error occurred while splitting the string. \n");
// 		return (1); // main에서 0이 아닌 값은 실패를 뜻함. 프로그램이 실패하여 종료됨을 뜻함.
// 	}
// 	int i = 0;
// 	while (str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}

// 	free_strs(str);

// 	return (0);
// }
