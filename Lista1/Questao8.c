#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool parenteses(char *string)
{
    bool resp;
    int qtdAberto = 0, qtdFechado = 0;
    for(int i=0; string[i] != EOF; i++) {
        if (string[i] == '('){
            qtdAberto++;
        }else if (string[i] ==')'){
            qtdFechado++;
        }    
    }

    if (qtdAberto == qtdFechado)
        resp = true;
    else
        resp = false;   
    return resp;
    
}

int main()
{
    //Casos de teste
    char expressao[50] = "((a + b) + (c * d))";
    //char expressao[50] = "(( a + b) + 1";
    //char expressao[50] = ") (a + b)) + (c * d)";

    printf(parenteses(expressao) ? "True" : "False");

    return 0;
}


