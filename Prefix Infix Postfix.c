#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define kapasitas 20
char str[kapasitas],stack[kapasitas];
int top=-1;

void push(char c)
{
   stack[++top]=c;
}

char pop()
{
   return stack[top--];
}

void post_in()
{
   int n,i,j=0;
   char a,b,op,x[20];
   printf("Masukkan POSTFIX yang ingin diubah: \n");fflush(stdin);
   gets(str);
   strrev(str);
   n=strlen(str);
   for(i=0;i<kapasitas;i++)
      stack[i]='\0';
   printf("Hasil Infix adalah: \t");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
      {
         push(str[i]);
      }
      else
      {
         x[j]=str[i]; j++;
         x[j]=pop(); j++;
      }
   }
   x[j]=str[top--];
    strrev(x);
   printf("%s\n",x);
}

void pre_in()
{
   int n,i;
   char a,b,op;
   printf("Masukkan PREFIX yang mau diubah: \n");fflush(stdin);
   gets(str);
   n=strlen(str);
   for(i=0;i<kapasitas;i++)
      stack[i]='\0';
   printf("Hasil Infix adalah:\t");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      {
         op=pop();
         a=str[i];
         printf("%c%c",a,op);
      }
   }
   printf("%c\n",str[top--]);
}
void main()
{
    int pilihan;
    while(1){
    printf("1 PREFIX ke INFIX, 2 POSTFIX ke INFIX,3 keluar\nMasukkan pilihan:\n");
    scanf("%d",&pilihan);

    switch(pilihan){
     case 1: pre_in();
     break;

     case 2:post_in();
     break;

     case 3:exit(0);
     break;

     default: printf("Masukkan Ulang pilihan\n");
   }
   printf("Masukkan 1 untuk lanjut, 0 untuk keluar\n");
   scanf("%d",&pilihan);
   if(pilihan==0)
    break;
   }
}
