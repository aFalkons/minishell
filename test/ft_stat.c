/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:48:17 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:48:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat fileStat;

    if (stat("file.txt", &fileStat) == -1) {
        perror("Errore durante l'ottenimento delle informazioni sul file");
        return 1;
    }

    printf("Dimensione del file: %lld bytes\n", (long long)fileStat.st_size);
    printf("Ultimo accesso: %s", ctime(&fileStat.st_atime));

    return 0;
}
