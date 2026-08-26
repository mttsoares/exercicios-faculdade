/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2026                          **/
/**   Prof. Luciano Digiampietri                                    **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**  turma 04                                                       **/
/*********************************************************************/


#include <stdio.h>

#define true 1
#define false 0

#define PEDRA 0
#define PAPEL 1
#define TESOURA 2

typedef int bool;


/*
Funcao usada em testes da correcao automatica
   NAO APAGAR OU MODIFICAR 
*/
void print123(){
}


/* Funcao que retorna o fatorial de n, caso n seja maior ou igual que zero ou
   -1 caso contario. */
double fatorial(int n){
	double res = 0;
    double valor = 1;//Variavel que recebe o primeiro numero do fatorial (1)
    if (n < 0) return -1;//Se n menor que zero, retorna -1
	/*Loop para garantir a multiplicacao de todos os termos antes de n.
	Para cada nova passagem, um valor eh acrescido ao indice i, ate que
	ele chegue no numero (n) digitado na funcao. */
    for (int i = 1; i <= n; i++){
		valor = valor * i; //Atualiza o valor da variavel para cada nova passagem do loop.
	}
	res = valor; //Insere o novo valor no local da resposta. 
	//(res fora do loop para quando n = 0, pois nesse caso, o loop nem eh iniciado).
	return res;
}

/* Funcao que retorna -1 caso os parametros base e exp sejam iguais a zero ou 
  caso o expoente seja menor que zero. Caso contrario, retorna o valor de 
  base elevada ao expoente (exp).
*/
long potencia(int base, int exp){
	/*res = 1 para que seja possivel a multiplicacao dentro do loop, alem de 
	 garantir que quando exp = 0, o resultado base^exp = 1, ja que para exp = 0
	 o loop nao eh realizado.*/
	long res = 1; 
	//Se exp eh negativo ou se a base e o expoente, juntos, sao zero, retorna -1.
	if(exp < 0 || (base == 0 && exp == 0)) return -1;
	/*Loop para multiplicar o valor inicial da variavel res
	pela base, atribuindo este novo valor a variavel res. 
	Apos a primeira passagem do loop, temos res = base, 
	resultando em base multiplicada exp vezes.*/
	for(int i = 1; i <= exp; i++){
		res = res * base;
	}
	return res;
}

/* Funcao que calcular o numero aproximado de Euler por meio da 
   soma de k termos. */
double aproximarEuler(int k) {
	double e = 0.0;
	if(k < 1) return -1; //Se k menor que 1, retorna -1
	/*Loop para a soma de k termos. Como o limite superior 
	do somatorio eh k-1, a funcao termina quando i nao eh 
	menor que k (poderia ser quando i <= k-1).*/
	for (int i = 0; i < k; i++){
		e = e + (1.0 / fatorial(i)); 
		//A cada rodada, a variavel 'e' recebe a soma dela mesma com o 1/i! correspondente.
	}
	return e;
}

/* Funcao que verifica a vitoria em uma rodade de Pedra, Papel e Tesoura.
   Em caso de empate retorna 0, se o jogador 1 ganhar retorna 1 e se o 
   jogador 2 ganhar retorna 2. */
int verificarVitoriaRodada(int j1, int j2) {
	int res = 2;//res = 2 garante a vitoria do j2 caso nao sejam satisfeitas as condicoes abaixo.
	if(j1 == j2) return 0; //Caso a jogada de j1 seja igual a de j2, o resultado eh empate.

/* Analise das possibilidades de vitoria do j1. */
	switch (j1){
	case 0: //j1 jogou Pedra:
		if(j2 == TESOURA) res = 1;// Se j2 jogar Tesoura, vitoria do j1.
		break;
	case 1: //j1 jogou Papel:
		if(j2 == PEDRA) res = 1;// Se j2 jogar Pedra, vitoria do j1.
		break;
	case 2: // j1 joga Tesoura:
		if(j2 == PAPEL) res = 1; // Se o j2 jogar Papel, vitoria do j1.
		break;
	}
	return res;
}

/* Funcao que verifica o ganhador de uma sequencia de 'melhor de tres'
   rodadas de Pedra, Papel e Tesoura. Em caso de empate retorna 0, se o
   jogador 1 ganhar retorna 1, se o jogador 2 ganhar retorna 2. */
int melhorDeTres(int j1_r1, int j2_r1, int j1_r2, int j2_r2, int j1_r3, int j2_r3) {
	int res = -1;
	//Sistema de atribuicao de pontos por vitoria de cada jogador.
	int rodada_1 = verificarVitoriaRodada(j1_r1, j2_r1);
	int rodada_2 = verificarVitoriaRodada(j1_r2, j2_r2);
	int rodada_3 = verificarVitoriaRodada(j1_r3, j2_r3);
	//Comecam com a pontuacao zerada.
	int pontoJ1 = 0;
	int pontoJ2 = 0;
	/*Verificacao de cada rodada com o acrescimo dos 
	respectivos pontos para cada jogador.*/
	if(rodada_1 == 1) pontoJ1+=1; 
		else if(rodada_1 == 2) pontoJ2 +=1;
	if(rodada_2 == 1) pontoJ1+=1;
		else if(rodada_2 == 2) pontoJ2 +=1;
	if(rodada_3 == 1) pontoJ1+=1;
		else if(rodada_3 == 2) pontoJ2 += 1;
	/*Verificacao de quem ganhou o melhor de tres,
	baseada na quantidade de pontos de cada um.*/
	if(pontoJ1 > pontoJ2) res = 1;
		else if(pontoJ2 > pontoJ1) res = 2;
		else if(pontoJ1 == pontoJ2) res = 0;
	return res;
}

/* Funcao que verifica se o numero passado como parametro eh narcisista. */
bool ehNarcisista(int n) {
	int res = -1;
	int i = 0; //Indice para o armazenamento da quantidade de digitos.
	int soma = 0;
	int numero = n; 
	/*Loop para armazenar os digitos de n. Por n ser um valor int, a divisao ignora valores decimais. 
	O indice i observa quantas vezes a conta foi feita, que corresponde a quantidade de digitos de n.*/ 
	//Ex: 157/10 => 15
	do{
		numero = numero/10; 
		i++;
	}while (numero > 0);
	numero = n;
	int digito[i];//Array para guardar cada um dos digitos individualmente no loop seguinte
	/*Loop responsavel por atribuir cada digito de n a uma posicao do array.*/
	for (int j = 0; j < i; j++){
		digito[j] = numero % 10; //Pegamos o resto da divisao para inserir no array, na posicao j.
		numero = numero/10; //Dividimos o numero por 10, por ser int os decimais serao ignorados.
	}
	for (int j = 0; j < i; j++){
		soma += potencia(digito[j], i); //Soma de cada digito elevado ao indice i.
	}
	if(soma == n) res = true; //Se o numero eh narcisista, retorna 1.
	else res = false; //Se não, retorna 0.
	return res;
}

/*
	Funcao main criada apenas para seus testes.
	Voce pode adicionar novos testes se quiser.
	ESTA FUNCAO SERA IGNORADA NA CORRECAO
*/
void main() {
	int x;
	printf("########### Fatorial ###########\n");
	for (x=0;x<=20;x++){
		printf("O fatorial de %2i eh %20.0f\n", x, fatorial(x));
	}

	printf("\n########### Potencia ###########\n");
	for (x=0;x<=20;x++){
		printf("3 elevado a %2i eh %15li\n", x, potencia(3,x));
	}

	printf("\n########### Euler ###########\n");
	for (x=0;x<=10;x++){
		printf("A aproximacao do numero de Euler com %2i termo(s) eh: %.20f\n", x, aproximarEuler(x));
	}
	
	printf("\n########### Pedra, Papel e Tesoura ###########\n");
	printf("Pedra vence Papel?\t%s\n", verificarVitoriaRodada(PEDRA, PAPEL) == 1 ? "Sim!" : "Nao.");
	printf("Pedra vence Pedra?\t%s\n", verificarVitoriaRodada(PEDRA, PEDRA) == 1 ? "Sim!" : "Nao.");
	printf("Pedra vence Tesoura?\t%s\n", verificarVitoriaRodada(PEDRA, TESOURA) == 1 ? "Sim!" : "Nao.");
	printf("Tesoura vence Papel?\t%s\n", verificarVitoriaRodada(TESOURA, PAPEL) == 1 ? "Sim!" : "Nao.");

	printf("\n");
	printf("Quem ganhou a melhor de tres foi: %i\n", melhorDeTres(PEDRA, PEDRA, TESOURA, TESOURA, PAPEL, TESOURA));	
	printf("Quem ganhou a melhor de tres foi: %i\n", melhorDeTres(PAPEL, TESOURA, TESOURA, TESOURA, PEDRA, TESOURA));
	printf("Quem ganhou a melhor de tres foi: %i\n", melhorDeTres(PEDRA, TESOURA, PAPEL, PEDRA, TESOURA, PAPEL));


	printf("\n########### Numeros Narcisistas ###########\n");
	for (x=1;x<1000;x++){
		if (ehNarcisista(x)) printf("O numero %4i eh narcisista!\n", x);
	}

}