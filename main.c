#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Server.h"
#include <signal.h>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("./a.out port path\n");
        return -1;
    }
    unsigned short port = atoi(argv[1]);
    chdir(argv[2]);
    int lfd = initListenFd(port);
    signal(SIGPIPE, SIG_IGN);
    epollRun(lfd);
    return 0;
}