/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:51:29 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/15 04:24:58 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
	char* const argv[] = {"env", NULL};
    char* const envp[] = {"MY_OPTION=1", NULL};

	if (execve("/usr/bin/env", argv, envp) == -1) {
		perror("Errore durante l'esecuzione di execve");
		return 1;
	}

	return 0;
}
