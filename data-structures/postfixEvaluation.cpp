#include<stdio.h>
#include<math.h>
#include "stack.cpp"

int main()
{
  char str[100];
  int i;
  int_Stack s;
  s.top = -1;
  printf("Enter a postfix expression to evaluate: ");
  scanf ("%[^\n]s", str);
  for(i=0;str[i]!='\0';i++)
  {
    if(str[i] == ' ')
      continue;
    if(str[i]>='0'&&str[i]<='9')
    {
      int j = i;
      int num = 0;
      while(str[i]>='0'&&str[i]<='9')
      {
        num = num * 10 + str[i++] - 48;
      }
      int_push(&s, num);
    }
    else
    {
      int o1=int_pop(&s), o2=int_pop(&s), result=0;
      switch(str[i])
      {
        case '^': result = pow(o2,o1);
          break;
        case '+': result = o2 + o1;
          break;
        case '-': result = o2 - o1;
          break;
        case '*': result = o2 * o1;
          break;
        case '/': result = o2 / o1;
          break;
      }
      int_push(&s, result);
    }
  }
  int answer = int_pop(&s);
  printf("\n%d\n",answer);
  return 0;
}
