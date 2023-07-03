#include "skillmaster.h"

#include <getopt.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <math.h>
#include <time.h>



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

void init_player(player_t * this, int which) {

    if (which) {
        this->name = "mag";
        this->class = MAGE;
        this->lvl = 85;
        this->max_health = 10000;
        this->health = this->max_health;
        this->as = 9.0;
        this->slow = 2.0;
        this->healing = 2000;
        this->energy = 10;
        this->mana = 500;
        this->skf = 1.0;
        this->skm = 2.0;
        this->crit = 0.25;
        this->armor = 600;
        this->fire_res = 0.10;
        this->lightning_res = 0.11;
        this->ice_res = 0.12;
        this->deepwound_res = 0.13;
        this->poison_res = 0.30;
        this->abs_f = 2000;
        this->abs_m = 1000;
        this->block = 0;
        this->dodge = 40;

        this->strength = 200;
        this->agility = 200;
        this->intellect = 1000;
        this->fire_damage = 2000;


    } else {
        this->name = "woj";
        this->class = WARRIOR;
        this->lvl = 85;
        this->max_health = 15000;
        this->health = this->max_health;
        this->as = 8.0;
        this->slow = 0.5;
        this->healing = 200;
        this->energy = 200;
        this->mana = 10;
        this->skf = 1.8;
        this->skm = 1.0;
        this->crit = 0.2;
        this->armor = 1000;
        this->fire_res = 0.10;
        this->lightning_res = 0.15;
        this->ice_res = 0.13;
        this->deepwound_res = 0.5;
        this->abs_f = 100;
        this->abs_m = 50;
        this->block = 50;
        this->dodge = 30;
        this-> strength = 1000;
        this->agility = 200;
        this->intellect = 200;
        this->physical_damage = 2200;
    }


}

void upkeep(player_t * this, int *turn_count) {

    float dupa = 1.0 - (0.05 * *turn_count);
    int heal_amount = (int)round(this->healing * (dupa > 0.0 ? dupa : 0.0));
    this->health += this->health + heal_amount > this->max_health ? this->max_health - this->health : heal_amount;
    printf("Uleczono %d punktów życia graczowi %s\n", heal_amount, this->name);
    /*
    this->health -= burn_dmg;
    this->health -= lightning_dmg;
    this->health -= poison_dmg;
    this->health -= deepwound_dmg;
    */
}

void basic_physical_attack(player_t *attacker, player_t *defender) {
    float damage_amount = attacker->physical_damage;
    float damage_dealt = 0;

    int crit = (float)rand()/RAND_MAX <= attacker->crit;
    if (crit) {
        damage_amount *= attacker->skf;
    }
    damage_dealt = damage_amount;
    printf("%s wykonuje atak o sile %d\n", attacker->name, (int)round(damage_amount));
    if (crit) {
        // damage_dealt *= 1.0 - defender->ko;
    }
    // damage_dealt *= 1.0 - defender->fo;
    // damage_dealt -= z armora
    // damage_dealt -= z bloku
    int dodge = (float)rand()/RAND_MAX <= (defender->dodge * 20.0 / attacker->lvl)/100.0;
    if (dodge) {
        damage_dealt = 0;
        printf("Unik!\n");
    }


    defender->health -= damage_dealt;
    printf("Zadano %d obrażeń!\n", (int)round(damage_dealt));
    printf("Życie %s: %d (%d%%)\n", defender->name, defender->health, defender->health*100/defender->max_health);
}

void basic_magical_attack(player_t *attacker, player_t *defender) {
    float damage_amount = attacker->fire_damage;
    float damage_dealt = 0;

    int crit = (float)rand()/RAND_MAX <= attacker->crit;
    if (crit) {
        damage_amount *= attacker->skm;
    }
    damage_dealt = damage_amount;
    if (crit) {
        // damage_dealt *= 1.0 - defender->ko;
    }
    // damage_dealt *= 1.0 - defender->fo;
    // damage_dealt -= z armora
    // damage_dealt -= z bloku
    damage_dealt *= 1.0 - defender->fire_res;


    printf("%s wykonuje atak o sile %d\n", attacker->name, (int)round(damage_amount));
    defender->health -= damage_dealt;
    printf("Zadano %d obrażeń!\n", (int)round(damage_dealt));
    printf("Życie %s: %d (%d%%)\n", defender->name, defender->health, defender->health*100/defender->max_health);
   
}

void end_step(player_t *this, int *turn_count) {

    *turn_count += 1;
    //printf("Życie %s: %d (%d%%)\n", this->name, this->health, this->health*100/this->max_health);
}


int main(int argc, char** argv) {

    srand(time(NULL));

    struct option options[] = {
        {"version", no_argument, NULL, 'v'},
        {"help", no_argument, NULL, 'h'},
        {"interactive", required_argument, NULL, 'i'},
        {0, 0, 0, 0}
    };

    int c = 0, ilvl = 0;

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


    player_t player1, player2;

    init_player(&player1, 1);
    init_player(&player2, 0);

    // inicjalizujemy zmienne opisujace walke
 
    float player1_at = 1.0/(player1.as + 1.0);
    float player2_at = 1.0/(player2.as + 1.0);
    // turn ~ true -> player1, turn ~ false -> player2
    int turn = player1_at > player2_at ? 1 : 0 ;

    int p1_turn_count = 0;
    int p2_turn_count = 0;

    while (player1.health > 0 && player2.health > 0) {

        char c;
        c = getc(stdin);
        char b = c;
        c = b;
        if (turn) {
            upkeep(&player1, &p1_turn_count);

            basic_magical_attack(&player1, &player2);

            end_step(&player1, &p1_turn_count);

        } else {
            upkeep(&player2, &p2_turn_count);
            // wykonujemy atak  
            basic_physical_attack(&player2, &player1);
        
            end_step(&player2, &p2_turn_count);
        }


        // okreslamy czyja bedzie nastepna tura
        turn = 1 - turn;
    }



    return EXIT_SUCCESS;
}