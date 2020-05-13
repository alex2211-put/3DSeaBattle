//
// Created by alik on 13.03.2020.
//

// по-хорошему заголовочный файл - это только описание функций, но так как OpenGL возмущается и не хочет работать
// то я напишу здесь сразу реализацию и не буду создавать .cpp файлы (незачем)


#ifndef INC_3DSEEBUTTLE_PAINTING_H
#define INC_3DSEEBUTTLE_PAINTING_H

#include <random>
#include <cmath>
#include <cstdio>   // Эта штука переводит числа в строки
#include <chrono>
#include "PaintingCubes.h"
#include "Text.h"
#include "DisplayCubes.h"


bool movement = true;

bool mainmenu = true;           // Главное меню
bool rules = false;             // Переходит во вкладку "Правила" в главном меню
bool authors = false;           // Переходит во вкладку "Авторы" в главном меню
unsigned int carrier = 0;       // Листает элементы меню

bool first = true;

void displayCell()
{
    if (first)
    {
        start = get_time();
        first = false;
    }
    if (forEnter == -1)
        glClearColor(0.07, 0.07, 0.25, 0.f);  //меняем цвет фона
    sprintf(&text3[7], "%i", LengthBigCube);    // Размер поля в главном меню

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(1, 1, 1, 1);  //Для написания помощи временно делаем проекцию 2D
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);  //устанавливаем уровень прозрачности - пока до конца не разобрался

    menupuncts[carrier] = true;     // С помощью него листаем меню
    if (mainmenu)
    {             // Начало игры. Отсюда и до 141 строки даже не копайтесь в коде
        mainMenuFunction();
    } else if (end1)
    {
        end1Function();
    } else if (end2)
    {
        end2Function();
    } else if (rules)
    {
        rulesFunction();
    } else if (authors)
    {
        authorsFunction();
    } else if (help)
    {
        helpFunction();
    } else
    {        // После отключения справки возвращаемся в 3D
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.5, 1.5, -1, 1, 1, -1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
        glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у

        twoBigCubes();
        oneBigCube();
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