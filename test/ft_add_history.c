/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:41:38 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 05:22:18 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
	add_history("Comando 1");
	add_history("Comando 2");

	int historyList;
	historyList = history_list();
	int i;
	printf("grande test %d", historyList);
	//for (i = 0; historyList[i]; i++) {
	//	printf("%d: %d\n", i, historyList[i]->line);
	//}

	return 0;
}
