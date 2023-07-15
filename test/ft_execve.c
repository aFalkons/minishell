/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:51:29 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:51:31 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    char* const argv[] = {"ls", "-l", NULL};
    char* const envp[] = {NULL};

    if (execve("/bin/ls", argv, envp) == -1) {
        perror("Errore durante l'esecuzione di execve");
        return 1;
    }

    return 0;
}
