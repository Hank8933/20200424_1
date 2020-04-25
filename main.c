#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40
#define OMAX 80

char* stringCopy( char *o, char const *a )
{
    for(; *a != '\0'; ++o, ++a)
        *o = *a;

    return o;
}

void insertspace( char *o, char const *a, int n )
{
    memcpy(o, a, n);
    char *out = stringCopy(o + n, " ");
    out = stringCopy(out, a + n);
    *out = '\0';
}

char *pig (char *a, char *o, int n)  //return o
{
    //printf("a = %s\n",a);
    *(a+n) = *a++;
    int i=0;
    for (; i<n; i++){
        *(o+i) = *(a+i);
    }
    *(o+i) = 'a'; *(o+i+1) = 'y'; *(o+i+2) = 0;
    return o;
}

int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    char a[MAX+2] = {0};
    char t[MAX+2] = {0};
    char o[OMAX] = {0};
    char oo[OMAX] = {0};
    char temp;
    int len=0;  //line len
    int i=0;  //word len
    int f, f2=1;
    do{
        f=0;  //row end
        if (i == 0){
            for (;;){
                temp = getchar();
                if (temp != ' ' && temp != '\n'){
                    *(t+i) = temp;
                    i++;
                }else {
                    *(t+i) = 0;
                    break;
                }
            }
            if (i == 0) {
                f2=0; f=1;
            }
            pig(t, a, i);  //a = Pig Latin
            //printf("%d pig %s\n",i,a);
            i += 2;
        }
        if (len+i >= OMAX) f=1;
        else if (!f) {
            memcpy(o+len, a, i);
            len += i; i=0;
            *(o+len++) = ' ';

            //for (int l=0; l<=len;l++) printf("\n%d\n",*(o+l));
        }

        //printf("i=%d len = %d\n",i,len);

        if (f) {
            *(o+len-1) = 0;
            //printf("%d %s\n",len,o);
            int flag = 0, n = OMAX-len;
            for (int k=0, round = 1; k<=len&& flag < n; k++){
                //printf("k = %d flag = %d\n",k,flag);
                if (k == len) {
                    round++;
                    k=0;
                }
                if (*(((flag%2)?oo:o)+k) == ' '){
                    insertspace( (flag%2)?o:oo, (flag%2)?oo:o, k);
                    k += round; flag++; len++;
                }
            }
            printf("%s\n",(flag%2)?oo:o);
            len=0;
        }
    }while (f2);
    return 0;
}
