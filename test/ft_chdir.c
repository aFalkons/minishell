/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:47:52 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/15 03:10:41 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Directory corrente: %s\n", cwd);
	} else {
		perror("Errore durante l'ottenimento della directory corrente");
		return 1;
	}

	if (chdir("/Users/afalconi/Desktop/programmi/minishell/test/tmp") == -1) {
		perror("Errore durante il cambio directory");
		return 1;
	}

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Nuova directory corrente: %s\n", cwd);
	} else {
		perror("Errore durante l'ottenimento della directory corrente");
		return 1;
	}

	return 0;
}
