#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N strlen(g)

char t[50], cs[50], g[]="10001000000100001";
int a, e, c;
void xor_crc();
void crc();

void xor_crc()
{
    for(c=1; c<N; c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}

void crc()
{
    for(e=0; e<N; e++)
        cs[e] = t[e];

    do
    {
        if(cs[0] == '1')
            xor_crc();

        for(c=0; c<N-1; c++)
            cs[c] = cs[c+1];

        cs[c] = t[e++];
    }
    while(e <= a+N-1);
}

int main()
{
    printf("\n Enter data : ");
    scanf("%s", t);

    a = strlen(t);

    for(e=a; e<a+N-1; e++)
        t[e] = '0';

    printf("\n Modified data is : %s", t);

    e = 0;
    crc();

    printf("\n CRC checksum is : %s", cs);

    for(e=a; e<a+N-1; e++)
        t[e] = cs[e-a];

    printf("\n Final codeword transmitted is : %s", t);

    printf("\n Test error detection 0(yes) 1(no)?: ");
    scanf("%d", &e);

    if(e == 0)
    {
        printf("\n Enter the position where error is to be inserted: ");
        scanf("%d", &e);

        do
        {
            t[e-1] = (t[e-1] == '0') ? '1' : '0';
        }
        while(e == 0 || e > a+N-1);

        printf("\n Erroneous data : %s \n", t);
    }

    e = 0;
    crc();

    for(e=0; (e<N-1) && (cs[e] != '1'); e++);

    if(e < N-1)
    {
        printf("\n CRC checksum is : %s", cs);
        printf("\n Error detected \n");
    }
    else
    {
        printf("\n CRC checksum is : %s", cs);
        printf("\n No error detected \n");
    }

    return 0;
}
