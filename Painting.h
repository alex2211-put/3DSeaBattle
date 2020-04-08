//
// Created by alik on 13.03.2020.
//

// по-хорошему заголовочный файл - это только описание функций, но так как OpenGL возмущается и не хочет работать
// то я напишу здесь сразу реализацию и не буду создавать .cpp файлы (незачем)


#ifndef INC_3DSEEBUTTLE_PAINTING_H
#define INC_3DSEEBUTTLE_PAINTING_H

#include <iostream>
#include "Cube.h"
#include "PaintingCubes.h"

double rotate_y = 135;  //начальный поворот куба по у
double rotate_x = -35; //начальный поворот куба по х
double &r_rotate_x = rotate_x;
double &r_rotate_y = rotate_y;

bool movement = true;

Cube a[LengthBigCube][LengthBigCube][LengthBigCube];
Cube b[LengthBigCube][LengthBigCube][LengthBigCube];
bool cubeA = true;

void Rotate(int value)
{
    if (forEnter != -1)
        return;
    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у
    if (forEnter == -1)
        rotate_y++;
    glutPostRedisplay();
    glutTimerFunc(2, Rotate, 1);
}

void displayCell()
{
    if (cubeA)
        glClearColor(0.07, 0.07, 0.25, 0.f);  //меняем цвет фона
    else
        glClearColor(0.1, 0.45, 0.1, 0.f);  //цвет фона
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);  //устанавливаем уровень прозрачности - пока до конца не разобрался

    if (forEnter == -1)
        rotate_y++;

    if (forOnePaint == 0 && forEnter == 0)
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                    if (a[i][j][k].getPaint())
                    {
                        a[i][j][k] = Cube(1.1 / (LengthBigCube),
                                          i * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                          0.55 / LengthBigCube,
                                          j * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                          0.55 / LengthBigCube,
                                          k * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                          0.55 / LengthBigCube, 0.11);

                        a[i][j][k].setColor(0.5, 0.5, 0.8);
                        forOnePaint = 1;
                    }
    }

    if (forOnePaint == 0 && forEnter == -1)
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    if (cubeA)
                    {
                        a[i][j][k] = Cube(1.1 / (LengthBigCube * 2),
                                          i * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) +
                                          0.55 * LengthBigCube / (LengthBigCube * 2),
                                          j * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) +
                                          0.55 * LengthBigCube / (LengthBigCube * 2),
                                          k * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) +
                                          0.55 * LengthBigCube / (LengthBigCube * 2), 0.11);

                        b[i][j][k] = Cube(1.1 / (LengthBigCube * 2),
                                          i * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) - 0.25,
                                          j * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) + 0.28,
                                          k * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) + 0.785,
                                          0.11);
                        a[i][j][k].setColor(1, 0, 0);
                    } else if (!cubeA)
                    {
                        b[i][j][k] = Cube(1.1 / (LengthBigCube * 2),
                                          i * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) +
                                          0.55 * LengthBigCube / (LengthBigCube * 2),
                                          j * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) +
                                          0.55 * LengthBigCube / (LengthBigCube * 2),
                                          k * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) +
                                          0.55 * LengthBigCube / (LengthBigCube * 2), 0.11);

                        a[i][j][k] = Cube(1.1 / (LengthBigCube * 2),
                                          i * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) + 0.25,
                                          j * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) - 0.28,
                                          k * 1.1 / (LengthBigCube * 2) - 0.55 + 0.55 / (LengthBigCube * 2) - 0.785,
                                          0.11);
                        b[i][j][k].setColor(1, 0, 0);
                    }
                    forOnePaint = 1;
                }
    }


    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
                if (k.getPaint())
                {
                    if (forEnter == -1 && !cubeA)
                    {
                        k.paintForRotate(rotate_y);
                    } else k.paintCube();
                    if (forEnter != -1)
                        k.setTransparancyNothing();
                }

    if (forEnter == -1)
        for (auto &i : b)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (cubeA)
                        k.paintForRotate(rotate_y);
                    else k.paintCube();
                }

    glFlush();
    glutSwapBuffers();
}

void changeSize(int w, int h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float) w / (float) h;
    if (w <= h)
        glOrtho(-1, 1, -1 / ratio, 1 / ratio, 1, -1);
    else
        glOrtho(-1 * ratio, 1 * ratio, -1, 1, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#endif //INC_3DSEEBUTTLE_PAINTING_H