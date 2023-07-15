/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:41:38 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/15 02:58:30 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
    add_history("Comando 1");
    add_history("Comando 2");
	char* input = readline("Inserisci una stringa: ");
	printf("Hai inserito: %s\n", input);
    add_history("Comando 3");
	free(input);
    return 0;
}
