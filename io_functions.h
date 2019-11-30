#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


TListaDeClientes ler_arquivo_clientes(){

	TListaDeClientes lista_de_clientes;

    FILE * fp;
    char str1[100], str2[100], str3[100];

    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("clientes.txt", "r");
    if (fp == NULL)
        printf("Erro\n");

    int qnt_linhas,linha_atual = 0;
	rewind(fp);
	char *token;
	fscanf(fp,"%d\n",&qnt_linhas);

	lista_de_clientes.clientes = malloc(qnt_linhas * sizeof(TCliente));

	while ((read = getline(&line, &len, fp)) != -1) {
		TCliente cliente;
		char *aux;
		aux = strtok(line,";");
		int i = 0;
		while(aux != NULL){
			switch(i++){
				case 0:
					cliente.codigo = atoi(aux);
					break;
				case 1:
					strcpy(cliente.nome ,aux);
					break;
				case 2:
					aux[strlen(aux)-1] = '\0';
					strcpy(cliente.cpf, aux);
					break;
			}	
			aux = strtok(NULL,";");

	   	}
	lista_de_clientes.clientes[linha_atual++] = cliente;
    // printf("%d,%s,%s\n",cliente.codigo,cliente.nome,cliente.cpf );
	}
    
    fclose(fp);
    if (line)
        free(line);

    lista_de_clientes.num_cli = qnt_linhas ;
    return lista_de_clientes;
}

TListaDeFaturas ler_arquivo_faturas(){

	TListaDeFaturas lista_de_faturas;

    FILE * fp;

    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int qnt_linhas;


    fp = fopen("faturas.txt", "r");
    if (fp == NULL)
        printf("Erro\n");

	rewind(fp);
	fscanf(fp,"%d\n",&qnt_linhas);
	lista_de_faturas.faturas = malloc(qnt_linhas * sizeof(TFatura));

	while ((read = getline(&line, &len, fp)) != -1) {
		TFatura fatura;
		char *aux;
		aux = strtok(line,";");
		int linha_atual = 0,j,i = 0;
		char *aux_data;
		char aux_data_pagamento[100];
		char aux_data_vencimento[100];

		i = 0;
		while(aux != NULL){
			switch(i){
				case 0:
					fatura.numero = atoi(aux);
					break;
				case 1:
					fatura.cliente = atoi(aux);
					break;
				case 2:
					strcpy(aux_data_vencimento,aux);
					break;

				case 3:
					strcpy(aux_data_pagamento,aux);

					break;

				case 4:
					fatura.valor_nominal = atof(aux);
					break;

				case 5:
					aux[strlen(aux)-1] = '\0';
					fatura.valor_pago  = atof(aux);
					break;
			}	
			i++;

			aux = strtok(NULL,";");
	   	}
	
		aux_data = strtok(aux_data_pagamento,",");
		fatura.pagamento.dia = atoi(aux_data);
 
		aux_data = strtok(NULL,",");
		fatura.pagamento.mes = atoi(aux_data);

		aux_data = strtok(NULL,",");
		fatura.pagamento.ano = atoi(aux_data);

		aux_data = strtok(aux_data_vencimento,",");
		fatura.vencimento.dia = atoi(aux_data);

		aux_data = strtok(NULL,",");
		fatura.vencimento.mes = atoi(aux_data);

		aux_data = strtok(NULL,",");
		fatura.vencimento.ano = atoi(aux_data);
		aux_data = strtok(aux_data,",");	
						


	    // printf("numero %u,cliente %u,dia %d,mes %d,ano %d,dia %d,mes %d,ano%d,%f,%f\n",fatura.numero,fatura.cliente,fatura.vencimento.dia,
	    // 	fatura.vencimento.mes,fatura.vencimento.ano,fatura.pagamento.dia,
	    // 	fatura.pagamento.mes,fatura.pagamento.ano,fatura.valor_nominal,fatura.valor_pago);
	lista_de_faturas.faturas[linha_atual++] = fatura;

	}
    
    fclose(fp);
    if (line)
        free(line);
    lista_de_faturas.num_fat = qnt_linhas;

    return lista_de_faturas;
}


