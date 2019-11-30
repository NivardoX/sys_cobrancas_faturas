#include "io_functions.h"

int main(int argc, char const *argv[])
{
	TListaDeClientes lista_de_clientes;
	TListaDeFaturas lista_de_faturas;


	lista_de_clientes = ler_arquivo_clientes();
	lista_de_faturas = ler_arquivo_faturas();

	for (int i = 0; i < lista_de_clientes.num_cli; ++i)
	{
		TCliente cliente = lista_de_clientes.clientes[i];
    	printf("%d,%s,%s\n",cliente.codigo,cliente.nome,cliente.cpf );
	}


	for (int i = 0; i < lista_de_faturas.num_fat; ++i)
	{
		TFatura fatura = lista_de_faturas.faturas[i];
		printf("numero %u,cliente %u,dia %d,mes %d,ano %d,dia %d,mes %d,ano%d,%f,%f\n",fatura.numero,fatura.cliente,fatura.vencimento.dia,
    	fatura.vencimento.mes,fatura.vencimento.ano,fatura.pagamento.dia,
    	fatura.pagamento.mes,fatura.pagamento.ano,fatura.valor_nominal,fatura.valor_pago);
	}



	
	return 0;
}