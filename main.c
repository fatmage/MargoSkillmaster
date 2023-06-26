#include "skillmaster.h"

#include <getopt.h>


void print_usage() {
    printf("usage\n");
}

void print_help() {
    printf("help\n");
}

void print_version() {
    printf("version\n");
}

int interactive_level = 0;



int main(int argc, char** argv) {

    struct option options[] = {
        {"version", no_argument, NULL, 'v'},
        {"help", no_argument, NULL, 'h'},
        {"interactive", required_argument, NULL, 'i'},
        {0, 0, 0, 0}
    };

    int c = 0;
    int ilvl = 0;

    while ((c = getopt_long(argc, argv, "vhi:", options, NULL)) != -1) {
        if (c == '?') {
            print_usage();
            return EXIT_FAILURE;
        }

        switch(c) {
            case 'v':
                print_version();
                return EXIT_SUCCESS;
            case 'h':
                print_help();
                print_usage();
                return EXIT_SUCCESS;
            case 'i':
                ilvl = atoi(optarg);
                if (0 <= ilvl  && ilvl <= 2) {
                    interactive_level = ilvl;
                    break;
                } 
            // Fall-through
            default:
                print_usage();
                return EXIT_FAILURE;
        }
    }

    printf("%d\n", interactive_level);



    // uzyjemy getopta



    /*
        tworzymy playerow
        inicjalizujemy im staty
        z plikow wczytujemy itemki/staty?
        jesli itemki to potrzeba bazy danych ze statami
        jezeli staty to bedzie latwiej testowac staty ciezej testowac zestawy

        z plikow wczytujemy umki i mistrzostwo

        zaczynamy walke
        interactive: 1 - p1 recznie, 2 - p1 i p2 recznie, 0 - default, lecimy mistrzostwem, potem zrobimy mcts
    
        readline - wczytujemy komendy
        wykonujemy jesli legal


    

    
    
    */




    return EXIT_SUCCESS;
}