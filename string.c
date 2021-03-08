#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

void alterna_string(char *line, char *str1, char *str2, int n, int inicio1, int inicio2){
    for(int i=0;i<(inicio2-1);i++)//preenche vetor str1 (0 a té antes do espaço do vetor linha)
        str1[i]=line[i];
    for(int i=0;i<(n-inicio2);i++)//preenche vetor str2 (logo apos espaco ate final do vetor linha)
        str2[i]=line[i+inicio2];
    for(int i=0;i<n;i++){//percorre o tamanho total do vetor linha que é a soma dos tamanhos de str1 e str2
        if(i<(inicio2-1))//verifica se ainda nao esta no fim de str1
            printf("%c",str1[i]);
        if(inicio2<n)//verifica se ainda nao esta no fim de str1
            printf("%c",str2[i]);
     }
}

int main(){
     int n=0, inicio1=0,inicio2, flag=0;
     char line[2*MAX];//tamanho máximo do vetor linha
     char *str1;//string 1
     char *str2;//string2
     while(scanf("%c", &line[n])==1 && line[n]!='\n'){ //percorre vetor linha até enter
        if(line[n]==' ' && flag==0){ //quando encontra espaco
            flag=1;//impede que entre aqui novamente e seta inicio2 outra vez
            inicio2=n+1;//inicio do vetor str2
        }
        n++;
     }
     if(n>=2 && inicio2>=2){
         str1=malloc((inicio2-1)*sizeof(char));//tamanho de str2 menos espaco é tamanho de str1
         str2=malloc((n-inicio2)*sizeof(char));//tamanho de str1 sera o tamanho do vetor linha menos o inicio2
         alterna_string(line, str1, str2, n, inicio1, inicio2);
         free (str1);//libera espacos
         free (str2);
     }
     return 0;
}
