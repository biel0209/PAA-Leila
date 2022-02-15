#include <stdio.h>
#include <stdlib.h>


void parenteses(char *string)
{
    
    int qtdAberto = 0, qtdFechado = 0;
    for(int i=0; string[i] != EOF; i++) {
        if (string[i] == '('){
            qtdAberto++;
        }else if (string[i] ==')'){
            qtdFechado++;
        }    
    }

    if (qtdAberto == qtdFechado)
        return true;
    else
        return false;   
    
}

int main()
{
    char expressao[50] = "((a + b) + (c * d))";

    parenteses(expressao);

    

    
    return 0;
}


