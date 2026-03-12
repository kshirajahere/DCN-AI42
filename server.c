#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERV_TCP_PORT 5035
#define MAX 1024

int main()
{
    int sockfd, newsockfd, clength, n;
    struct sockaddr_in serv_addr, cli_addr;
    char filename[MAX], buffer[MAX];
    FILE *f1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Server started...\n");
    printf("Waiting for client...\n");

    listen(sockfd, 5);

    clength = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clength);

    read(newsockfd, filename, MAX);

    printf("Client requested file: %s\n", filename);

    f1 = fopen(filename, "r");

    if (f1 == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    while (fgets(buffer, MAX, f1) != NULL)
    {
        write(newsockfd, buffer, strlen(buffer));
    }

    fclose(f1);
    close(newsockfd);

    printf("File transferred successfully\n");

    return 0;
}
