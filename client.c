#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERV_TCP_PORT 5035
#define MAX 1024

int main()
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendfile[MAX], recvline[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Enter the file name: ");
    scanf("%s", sendfile);

    write(sockfd, sendfile, strlen(sendfile));

    printf("\nFile contents received:\n\n");

    while ((n = read(sockfd, recvline, MAX)) > 0)
    {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    close(sockfd);

    return 0;
}
