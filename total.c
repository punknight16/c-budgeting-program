#include <stdio.h>
#define AMT 2
#define ACCT 3
#define ENT 4 
struct ledger_obj {
	int id;
        char desc[1000];
        float amount;
};
void parseit(), structit(), displayit(), strcopy(), squeeze();
float atofloat();
int getid(), addledgerobj();
int main(){ 
	char input[100][5][1000];
	struct ledger_obj c[100], e[100];
	parseit(input);
	structit(input, c, e);
	displayit("accounts", c);
	displayit("entities", e);
}
void parseit(input)
char input[100][5][1000];
{
	int x, i, j, k;
	i = j = k = 0;
        while((x=getchar())!=EOF){
                if(x != '\t' || x != '\n'){
                	input[i][j][k] = x;
                        k++;
                } 
		 if(x == '\t' ){
                        input[i][j][k] = '\0';
                        k = 0;
                        j++;
                } 
		 if(x == '\n'){
                        input[i][j][k] = '\0';
                        j = k = 0;
                        i++;
                }
        }
	return;
}
void structit(input, c, e)
char input[100][5][1000];
struct ledger_obj c[], e[];
{
	int i,x,y,last[5]; 
	i = last[0] = last[1] = last[2] = last[3] = last[4] = 0;
	while((input[i][0][0])){
		x = addledgerobj(c, last, 2, input[i][ACCT], input[i][AMT]);
		y = addledgerobj(e, last, 4, input[i][ENT], input[i][AMT]);
		/*printf("e[y].id: %d \t e[y].desc: %s \t e[y].amount %6.2f\n", e[y].id, e[y].desc, e[y].amount);*/
		i++;
	}
	return;
}
int addledgerobj(ledger, last_arr, index, name_arr, amt_arr)
struct ledger_obj ledger[100];
int last_arr[5], index;
char name_arr[], amt_arr[];
{
	int i = 0;
	squeeze(name_arr);
	if((i =getid(ledger, name_arr)) != -1) {
		ledger[i].amount = ledger[i].amount + atofloat(amt_arr);
	} else {
		i = last_arr[index];
		ledger[i].id = i;
		strcopy(name_arr, ledger[i].desc);
		ledger[i].amount = atofloat(amt_arr);
		last_arr[index] = i + 1;
	}
	return i;
}
float atofloat(str)
char str[];
{
	int i, n, flag;
        float f;
        i = n = flag = 0;
        f = 1.00;
        while((str[i]>='0' && str[i]<='9') ||
                  str[i] =='.' || str[i] == '+' || str[i] == '-'){
                        if(str[i] == '.')
                                flag = 1;
                        else if (str[i] =='+')
                                ;
                        else if (str[i] =='-')
                                f = f * -1;
                        else {
                                n = 10 * n + (str[i] - '0');
                                if(flag)
                                        f = f * .1;
                        }
		i++;
	}
	return(n*f);
}
void strcopy(a,b)
char a[], b[];
{
	int i;
        for(i=0;(b[i] = a[i]) != '\0';i++)
                        ;
        a[i] = '\0';
}
int getid(a, b)
struct ledger_obj a[100];
char b[1000];
{
	int i, j, x, flag;
	for(i=0;(x = a[i].desc[0]); i++){
		for(j=0,flag=1; a[i].desc[j]!='\0';j++)
			if(a[i].desc[j] != b[j])
				flag = 0;
		if(a[i].desc[j] == '\0' && b[j]=='\0' && flag == 1)
			return i;
	}
	return -1;
}
void squeeze(s)
char s[];
{
        int i,j;
        for (i = j = 0; s[i] != '\0'; i++)
                if (s[i] != '\n' && s[i] !='\t')
                        s[j++] = s[i];
        s[j] = '\0';
}
void displayit(title, ledger)
char title[];
struct ledger_obj ledger[];
{
	int i;
	printf("\n--------\n%s:\n--------\n", title);
	for(i=0;(ledger[i].desc[0]); i++)
		printf("%s \t %6.2f\n", ledger[i].desc, ledger[i].amount);
}
