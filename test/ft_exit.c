/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:47:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:47:34 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prima dell'uscita.\n");
    exit(0);
    printf("Dopo l'uscita.\n"); // Questa riga non verrà mai eseguita
    return 0;
}
