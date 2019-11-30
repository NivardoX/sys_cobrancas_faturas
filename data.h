struct data
{
	char dia;
	char mes;
	short ano;
};
typedef struct data TData;

struct cliente
{
	unsigned codigo;
	char nome[41];
	char cpf[12];

};
typedef struct cliente TCliente;

struct fatura
{

	unsigned numero;
	unsigned cliente;
	TData vencimento;
	TData pagamento;
	float valor_nominal;
	float valor_pago;	
};
typedef struct fatura TFatura;

struct lista_de_clientes
{
	int capacidade;
	int num_cli;
	TCliente *clientes;
};
typedef struct lista_de_clientes TListaDeClientes;

struct lista_de_faturas
{
	int capacidade;
	int num_fat;
	TFatura *faturas;
};
typedef struct lista_de_faturas TListaDeFaturas;
