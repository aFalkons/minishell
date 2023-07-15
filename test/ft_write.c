/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:43:03 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:43:05 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    int fileDescriptor = open("file.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fileDescriptor == -1) {
        perror("Errore durante l'apertura del file");
        return 1;
    }

    char* data = "Dati da scrivere nel file.";
    write(fileDescriptor, data, strlen(data));
    close(fileDescriptor);
    return 0;
}
