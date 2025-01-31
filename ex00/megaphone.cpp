#include <cctype>
#include <iostream>
#include <unistd.h>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int j = 1; av[j]; j++) {
            for (int i = 0; av[j][i]; i++) {
                if (std::islower(av[j][i]))
                    av[j][i] = std::toupper(av[j][i]);
                std::cout << av[j][i];
            }
        }
    }
    std::cout << std::endl;
    close(STDOUT_FILENO);
    return 0;
}