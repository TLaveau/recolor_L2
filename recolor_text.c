#include "game.h"
#include "game_io.h"
#include "stdlib.h"

int main(){
    game g = game_new_empty();
    game_set_max_moves(g, 12);
    for(uint i=0;i<SIZE;i++) {
        for(uint j=0;j<SIZE;j++) {
            int color = rand() % (3 + 1 - 0);
            game_set_cell_init(g, i, j, color);
        }
    }
    if(game_nb_moves_cur(g) > 12 ){
        printf("looser");
        game_delete(g);
    } else if (game_is_over(g)){
        printf("winner");
    } else {
        char key = getchar();
        if (key > 0 && key < 4) {
            game_play_one_move(key);
        }
    }
    return EXIT_SUCCESS;
}

// bool win_test(game g) {
//     if(game_nb_moves_cur(g) > 12 ){
//         printf("looser");
//         game_delete(g);
//     } else {
//         int test_color = game_cell_current_color(g, 0, 0);
//         for(uint i=0;i<SIZE;i++) {
//             for(uint j=0;j<SIZE;j++) {
//                 int current_color = game_cell_current_color(g, i, j);
//                 if(current_color != test_color){

//                 }
//             }
//         }
//     }
// }