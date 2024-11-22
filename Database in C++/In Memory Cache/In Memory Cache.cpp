#include "cache.h"
#include <iostream>

bool scontinuation{};

int main(int argc, char *argv[])
{
    const char* sport{};
    int16 port{};
    int s{};

    if (argc < 2) {
        sport = PORT;
    }
    else {
        sport = argv[1];
    }

    port = (int16)atoi(sport);

    s = initserver(port);

    scontinuation = true;

    while (scontinuation) {
        mainloop(s);
    }

    std::cout << "Shutting down..." << std::endl;
    close(s);

    return 0;
}


