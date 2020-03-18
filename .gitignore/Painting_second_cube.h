//
// Created by xaero on 14.03.2020.
//

#ifndef INC_3DSEEBUTTLE_PAINTING_SECOND_CUBE_H
#define INC_3DSEEBUTTLE_PAINTING_SECOND_CUBE_H

#include <iostream>
double rotate_y_2=180;  //начальный поворот куба по у
double rotate_x_2=0; //начальный поворот куба по х
double sizeCell_2 = -0.05; //размеры кубиков
double steCell_2 = 0.1; //шаг при определении
double quantityCell_2 = 0.5-0.25; //количестве кубиков, тоесть их всего  (quantityCell_2/steCell_2)   #### вычел 0.4, чтобы сместить кубики и чтобы крутились вокруг центра
double transparency_2 = 0.3; //прозрачность кубиков
double r_2=1, g_2=1, b_2=0;
//функция рисует 3Д кубики на экране
int z = 0;
void displayCell_2() {
    if (z == 1) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"
    glLoadIdentity();
    glRotatef(rotate_x_2, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y_2, 0.0, 1.0, 0.0);  //а это для у

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);  //устанавдиваем уровень прозрачности - пока до конца не разобрался

        for (float i_2 = -0.25; i_2 <
                                quantityCell_2; i_2 += steCell_2)  //опять же начинаю с -0.25  ### это чтобы сместить кубики и чтобы крутились вокруг центра
        {
            for (float j_2 = -0.25; j_2 < quantityCell_2; j_2 += steCell_2)  //аналогия
            {
                for (float y_2 = -0.25; y_2 < quantityCell_2; y_2 += steCell_2)   //аналогия
                {
                    //std::cout<<y;
                    if (i_2 < 100) {
                        r_2 = 0;
                        g_2 = 1;
                        b_2 = 0;

                        glBegin(GL_POLYGON);  //начинаем рисовать грань
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //здесь и далее сначала цвет
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //(красный, зеленый, синий, прозрачность)
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //потом идет положение точки
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);  //4 точки - 1 грань
                        glEnd();  //закончили рисовать одну грань

                        glBegin(GL_POLYGON);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(r_2, g_2, b_2, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();

                        //пошли ребра
                        glBegin(GL_LINES);  //начинаем рисовать рёбра
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //здесь и далее сначала цвет
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //(красный, зеленый, синий, прозрачность)
                        glEnd();  //одно ребро
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //(красный, зеленый, синий, прозрачность)
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //потом идет положение точки
                        glEnd();  //второе ребро
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //потом идет положение точки
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);  //4 точки - 1 грань
                        glEnd();  //третье ребро
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);  //4 точки - 1 грань
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //здесь и далее сначала цвет
                        glEnd();  //четвёртое ребро

                        //следующая грань
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        //следующая
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        //ещё одна
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();

                        //немного осталось
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        //последняя
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r_2, g, b);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(r_2, g, b);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();

                    } else {
                        glBegin(GL_POLYGON);  //начинаем рисовать грань
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //здесь и далее сначала цвет
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //(красный, зеленый, синий, прозрачность)
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //потом идет положение точки
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);  //4 точки - 1 грань
                        glEnd();  //закончили рисовать одну грань

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor4f(0.5, 0.5, 0.5, transparency_2);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();

                        //пошли ребра
                        glBegin(GL_LINES);  //начинаем рисовать рёбра
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //здесь и далее сначала цвет
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //(красный, зеленый, синий, прозрачность)
                        glEnd();  //одно ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //(красный, зеленый, синий, прозрачность)
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //потом идет положение точки
                        glEnd();  //второе ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //потом идет положение точки
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);  //4 точки - 1 грань
                        glEnd();  //третье ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);  //4 точки - 1 грань
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2,
                                   -sizeCell_2 + y_2);  //здесь и далее сначала цвет
                        glEnd();  //четвёртое ребро

                        //следующая грань
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        //следующая
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        //ещё одна
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();

                        //немного осталось
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();

                        //последняя
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell_2 + i_2, -sizeCell_2 + j_2, -sizeCell_2 + y_2);
                        glEnd();
                    }

                }
            }
        }


        glFlush();
        glutSwapBuffers();
    }
}



void changeSize_2(int w, int h)
{
    if (h == 0)
        h=1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = w/(float)h;
    if (w<=h)
        glOrtho (-1,1,-1/ratio, 1/ratio, 1,-1);
    else
        glOrtho (-1*ratio,1*ratio, -1,1,1,-1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//функция взаимодействия с клавиатурой
void specialKeys_2( int key, int x, int y) {

    if (key == GLUT_KEY_RIGHT) //если нажата клавиша "вправо", то поворачиваем
        rotate_y_2 += 5;

    else if (key == GLUT_KEY_LEFT)  //аналогично для левой клавиши
        rotate_y_2 -= 5;

    else if (key == GLUT_KEY_UP)  //это уже повороты  вверх и вниз
        rotate_x_2 += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x_2 -= 5;

    else if (key == GLUT_KEY_F12) {
        rotate_y_2 = -180;
        rotate_x_2 = 0;
    }

    else if (key == GLUT_KEY_F11) {
        rotate_y_2 = -180;
        rotate_x_2 = 270;
    }

    else if (key == GLUT_KEY_F10) {
        rotate_y_2 = -270;
        rotate_x_2 = 0;
    }

    glutPostRedisplay(); //а это просто обязательная функция

}

#endif //INC_3DSEEBUTTLE_PAINTING_SECOND_CUBE_H
