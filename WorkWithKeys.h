//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_WORKWITHKEYS_H
#define INC_3DSEEBUTTLE_WORKWITHKEYS_H

#include "Painting.h"

//функция взаимодействия с клавиатурой
void Keyboard (unsigned char key, int x, int y) {
    if (key == '7') {
        choose_first_side(r_i_min, r_j_min, r_y_min, r_i_max, r_j_max, r_y_max, r_r, r_g, r_b, r_rotate_x, r_rotate_y);
    }

    if (key == '8') {
        choose_second_side(r_i_min, r_j_min, r_y_min, r_i_max, r_j_max, r_y_max, r_r, r_g, r_b, r_rotate_x, r_rotate_y);
    }

    if (key == '9') {
        choose_third_side(r_i_min, r_j_min, r_y_min, r_i_max, r_j_max, r_y_max, r_r, r_g, r_b, r_rotate_x, r_rotate_y);
    }
    glutPostRedisplay(); //а это просто обязательная функция

}

void specialKeys( int key, int x, int y) {

    if (key == GLUT_KEY_RIGHT) //если нажата клавиша "вправо", то поворачиваем
        rotate_y += 5;

    else if (key == GLUT_KEY_LEFT)  //аналогично для левой клавиши
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)  //это уже повороты  вверх и вниз
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    else if (key == GLUT_KEY_PAGE_UP) {
        show_first_cube = true;
        show_second_cube = false;

    }
    else if (key == GLUT_KEY_PAGE_DOWN) {
        show_second_cube = true;
        show_first_cube = false;

    }
    else if (key == GLUT_KEY_F7) {
        view_first_side(r_i_min, r_j_min, r_y_min, r_i_max, r_j_max, r_y_max, r_r, r_g, r_b, r_rotate_x,
                        r_rotate_y);
    }
    else if (key == GLUT_KEY_F8) {
        view_second_side(r_i_min, r_j_min, r_y_min, r_i_max, r_j_max, r_y_max, r_r, r_g, r_b, r_rotate_x,
                         r_rotate_y);
    }
    else if (key == GLUT_KEY_F9) {
        view_third_side(r_i_min, r_j_min, r_y_min, r_i_max, r_j_max, r_y_max, r_r, r_g, r_b, r_rotate_x,
                        r_rotate_y);
    }

    else if (key == GLUT_KEY_HOME) {
        default_position(r_i_min, r_j_min, r_y_min, r_i_max, r_j_max, r_y_max, r_r, r_g, r_b, r_rotate_x, r_rotate_y);
    }
    glutPostRedisplay(); //а это просто обязательная функция
}


#endif //INC_3DSEEBUTTLE_WORKWITHKEYS_H
