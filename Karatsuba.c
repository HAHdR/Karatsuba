#include <stdio.h>

/* atividade Karatsuba */
/* Arquivo: Karatsuba.c
   Autores: Guilherme de Brito Diogo
            Henrique Abreu Hollanda da Rocha
            João Alfredo   
			Matheus Guido Noronha Moreira Passos
            Thiago Salanti Mambrini
   Data: 02/10/2025
   Descrição: implementa o algoritmo de Karatsuba
*/

int cont = 0; //Contador de chamadas(variável global)

//interfaces
unsigned long long Karatsuba(unsigned long long, unsigned long long);

//aplicação
int main()
{
	unsigned long long A, B, C;
	
	A = 12345;
    B = 6789;
    C = Karatsuba(A,B);
    
    printf("A = %lld   B = %lld   C = %lld\n\nContador de chamadas = %d\n\n", A, B, C, cont);
    
    cont = 0;
	
	A = 1234;
	B = 12345678;
	C = Karatsuba(A,B);	
	
    printf("\nA = %lld   B = %lld   C = %lld\n\nContador de chamadas = %d\n", A, B, C, cont);
}


unsigned long long Karatsuba(unsigned long long u, unsigned long long v)
{
	unsigned long long uv, p, q, r, s, pot, n, m, tx, ty, pr, qs, y, tempU, tempV;
	int i, contDigU, contDigV;
	
	cont++;
	contDigU = 1;
	contDigV = 1;
	tempU = u;
	tempV = v;
	
	while (tempU >= 10)
	{
		contDigU++;
    	tempU /= 10;
	}
	
	while (tempV >= 10)
	{
		contDigV++;
    	tempV /= 10;
	}
	
	if(contDigU < 4 && contDigV < 4)  //Verifica a quantidade de dígitos
		uv = u * v;
	else
	{
		if(contDigU > contDigV)
	    	n = contDigU;
	    else
	    	n = contDigV;
	    	
		m = (n+1) / 2;
	
    	//Calcular as potências de 10
		pot = 1;
    	for(i = 0; i < m; i++)
    	pot *= 10;
	
		//Multiplicação por Karatsuba
		p = u / pot;
		q = u % pot;
		r = v / pot;
		s = v % pot;
	    
		pr = Karatsuba(p,r);
		qs = Karatsuba(q,s);
		y = Karatsuba(p+q,r+s);
		uv = pr * (pot * pot) + (y - pr - qs) * pot + qs;
	}
	
	return uv; 
}