//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CHOOSESIDE_H
#define INC_3DSEEBUTTLE_CHOOSESIDE_H

void choose_first_side (float& r_i_min, float& r_j_min, float& r_y_min, float& r_i_max, float& r_j_max, float& r_y_max, double& r_r, double& r_g, double& r_b, double& r_rotate_x, double& r_rotate_y) {
    r_i_min = 0.24;
    r_j_min = -1;
    r_y_min = -1;
    r_i_max = 0.26;
    r_j_max = 1;
    r_y_max = 1;
    r_r = 1;
    r_g = 0;
    r_b = 0;
    r_rotate_x = -180;
    r_rotate_y = -90;
}

void choose_second_side (float& r_i_min, float& r_j_min, float& r_y_min, float& r_i_max, float& r_j_max, float& r_y_max, double& r_r, double& r_g, double& r_b, double& r_rotate_x, double& r_rotate_y) {
    r_i_min = -1;
    r_j_min = 0.24;
    r_y_min = -1;
    r_i_max = 1;
    r_j_max = 0.26;
    r_y_max = 1;
    r_r = 0;
    r_g = 1;
    r_b = 0;
    r_rotate_x = -90;
    r_rotate_y = 270;
}

void choose_third_side (float& r_i_min, float& r_j_min, float& r_y_min, float& r_i_max, float& r_j_max, float& r_y_max, double& r_r, double& r_g, double& r_b, double& r_rotate_x, double& r_rotate_y) {
    r_i_min = -1;
    r_j_min = -1;
    r_y_min = 0.24;
    r_i_max = 1;
    r_j_max = 1;
    r_y_max = 0.26;
    r_r = 0;
    r_g = 0;
    r_b = 1;
    r_rotate_x = -180;
    r_rotate_y = 0;
}

void default_position (float& r_i_min, float& r_j_min, float& r_y_min, float& r_i_max, float& r_j_max, float& r_y_max, double& r_r, double& r_g, double& r_b,double& r_rotate_x, double& r_rotate_y) {
    r_i_min = -1;
    r_j_min = -1;
    r_y_min = -1;
    r_i_max = 1;
    r_j_max = 1;
    r_y_max = 1;
    r_r = 0.5;
    r_g = 0.5;
    r_b = 0.5;
    r_rotate_x = 325;
    r_rotate_y = 135;
}

void view_first_side (float& r_i_min, float& r_j_min, float& r_y_min, float& r_i_max, float& r_j_max, float& r_y_max, double& r_r, double& r_g, double& r_b, double& r_rotate_x, double& r_rotate_y) {
    r_i_min = 0.24;
    r_j_min = -1;
    r_y_min = -1;
    r_i_max = 0.26;
    r_j_max = 1;
    r_y_max = 1;
    r_r = 1;
    r_g = 0;
    r_b = 0;
    r_rotate_x = 325;
    r_rotate_y = 135;
}

void view_second_side (float& r_i_min, float& r_j_min, float& r_y_min, float& r_i_max, float& r_j_max, float& r_y_max, double& r_r, double& r_g, double& r_b, double& r_rotate_x, double& r_rotate_y) {
    r_i_min = -1;
    r_j_min = 0.24;
    r_y_min = -1;
    r_i_max = 1;
    r_j_max = 0.26;
    r_y_max = 1;
    r_r = 0;
    r_g = 1;
    r_b = 0;
    r_rotate_x=325;
    r_rotate_y=135;
}

void view_third_side (float& r_i_min, float& r_j_min, float& r_y_min, float& r_i_max, float& r_j_max, float& r_y_max, double& r_r, double& r_g, double& r_b, double& r_rotate_x, double& r_rotate_y) {
    r_i_min = -1;
    r_j_min = -1;
    r_y_min = 0.24;
    r_i_max = 1;
    r_j_max = 1;
    r_y_max = 0.26;
    r_r = 0;
    r_g = 0;
    r_b = 1;
    r_rotate_x=325;
    r_rotate_y=135;
}


#endif //INC_3DSEEBUTTLE_CHOOSESIDE_H
