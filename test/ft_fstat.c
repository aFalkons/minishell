/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:49:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/15 05:04:37 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fileDescriptor = open("file.txt", O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Errore durante l'apertura del file");
        return 1;
    }

    struct stat fileStat;
    if (fstat(fileDescriptor, &fileStat) == -1) {
        perror("Errore durante la chiamata a fstat");
        close(fileDescriptor);
        return 1;
    }

    printf("Informazioni sul file:\n");
    printf("Dimensione: %lld byte\n", fileStat.st_size);
    printf("Ultimo accesso: %ld\n", fileStat.st_atime);
    printf("Ultima modifica: %ld\n", fileStat.st_mtime);
    printf("Ultimo cambiamento di stato: %ld\n", fileStat.st_ctime);

    close(fileDescriptor);

    return 0;
}
