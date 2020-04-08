//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_WORKWITHKEYS_H
#define INC_3DSEEBUTTLE_WORKWITHKEYS_H

#include "ChooseSide.h"

//введем координаты кубиков, которые подкрашиваются первыми при выборе фронтального вида
int i_first_side = LengthBigCube - 1, j_first_side = 0, k_first_side = 0;
int i_second_side = LengthBigCube - 1, j_second_side = LengthBigCube - 1, k_second_side = LengthBigCube - 1;
int i_third_side = LengthBigCube - 1, j_third_side = 0, k_third_side = LengthBigCube - 1;
int yf = j_first_side, z1 = k_first_side;
int x2 = i_second_side, z2 = k_second_side;
int x3 = i_third_side, y3 = j_third_side;
int p1 = 0, p2 = 0, p3 = 0;

//функция взаимодействия с клавиатурой
void Keyboard(unsigned char key, int x, int y)
{
    if (key == 13 && forEnter == -1)
    {
        forEnter = 0;
        forOnePaint = 0;
    }

    if (key == 13 && forEnter == 1)
    {
        if (firstSide)
        {
            choose_first_side(r_rotate_x, r_rotate_y);
            a[i_first_side][j_first_side][k_first_side].setColor(1, 0, 0);
        } else if (secondSide)
        {
            choose_second_side(r_rotate_x, r_rotate_y);
            a[i_second_side][j_second_side][k_second_side].setColor(0, 1, 0);
        } else if (thirdSide)
        {
            choose_third_side(r_rotate_x, r_rotate_y);
            a[i_third_side][j_third_side][k_third_side].setColor(0, 0, 1);
        }
        forEnter = 2;
        movement = false;
    }

    if (key == 13 && forEnter == 3)
    {
        movement = true;
        for (auto &i : a)
            for (auto &j : i)
                for (auto &k : j)
                {
                    k.setColor(0.5, 0.5, 0.8);
                    k.setTransparency(0.1);
                }

        if (firstSide)
        {
            for (auto &i : a)
                i[yf][z1].setColor(1, 1, 0);
            a[0][yf][z1].setTransparency(1);
            r_rotate_x = 325;
            r_rotate_y = 135;
        } else if (secondSide)
        {
            for (int j = 0; j < LengthBigCube; j++)
                a[x2][j][z2].setColor(1, 1, 0);
            a[x2][0][z2].setTransparency(1);
            r_rotate_x = 325;
            r_rotate_y = 135;
        } else if (thirdSide)
        {
            for (int k = 0; k < LengthBigCube; k++)
                a[x3][y3][k].setColor(1, 1, 0);
            a[x3][y3][0].setTransparency(1);
            r_rotate_x = 325;
            r_rotate_y = 135;
        }
        forEnter = 4;
    }

    if (key == 13 && forEnter == 5)
    {//FIRE!!! (типа пыжь пыжь и все покраснело)
        if (firstSide && a[p1][yf][z1].getHit() != 2)
        {
            for (auto &i : a)
            {
                i[yf][z1].setColor(0.5, 0.5, 0.8);
                i[yf][z1].setTransparency(0.1);
            }
            a[p1][yf][z1].setColor(1, 0, 0);
            a[p1][yf][z1].setTransparency(0.5);
            a[p1][yf][z1].setIsHitten(1);
            for (int i = p1 - 1; i <= p1 + 1; i++)
                for (int j = yf - 1; j <= yf + 1; j++)
                    for (int k = z1 - 1; k <= z1 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube && k < LengthBigCube)
                        {
                            a[i][j][k].setPaint(false);
                            a[i][j][k].setIsHitten(2);
                        }
            a[p1][yf][z1].setPaint(true);
        } else if (secondSide && a[x2][p2][z2].getHit() != 2)
        {
            for (int j = 0; j < LengthBigCube; j++)
            {
                a[x2][j][z2].setColor(0.5, 0.5, 0.8);
                a[x2][j][z2].setTransparency(0.1);
            }
            a[x2][p2][z2].setColor(1, 0, 0);
            a[x2][p2][z2].setTransparency(0.5);
            a[x2][p2][z2].setIsHitten(1);
            for (int i = x2 - 1; i <= x2 + 1; i++)
                for (int j = p2 - 1; j <= p2 + 1; j++)
                    for (int k = z2 - 1; k <= z2 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube && k < LengthBigCube)
                        {
                            a[i][j][k].setPaint(false);
                            a[i][j][k].setIsHitten(2);
                        }
            a[x2][p2][z2].setPaint(true);
        } else if (thirdSide && a[x3][y3][p3].getHit() != 2)
        {
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[x3][y3][k].setColor(0.5, 0.5, 0.8);
                a[x3][y3][k].setTransparency(0.1);
            }
            a[x3][y3][p3].setColor(1, 0, 0);
            a[x3][y3][p3].setTransparency(0.5);
            a[x3][y3][p3].setIsHitten(1);
            for (int i = x3 - 1; i <= x3 + 1; i++)
                for (int j = y3 - 1; j <= y3 + 1; j++)
                    for (int k = p3 - 1; k <= p3 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube && k < LengthBigCube)
                        {
                            a[i][j][k].setPaint(false);
                            a[i][j][k].setIsHitten(2);
                        }
            a[x3][y3][p3].setPaint(true);
        }
    }

    if (key == 27)
    {
        movement = true;
        forEnter--;
        if (forEnter < 0)
            forEnter = 0;
        default_position(r_rotate_x, r_rotate_y);
        firstSide = false;
        secondSide = false;
        thirdSide = false;
    }

    glutPostRedisplay(); //а это просто обязательная функция
}

void ChooseColumn(int arrow)
{
    if (firstSide)
    {
        a[LengthBigCube - 1][LengthBigCube - 1][LengthBigCube - 1].setTransparency(0.5);
        a[LengthBigCube - 1][LengthBigCube - 1][LengthBigCube - 1].setColor(0.2, 0.0, 0.0);


        if (arrow == 4)
        {//работает стрелочка вправо
            a[LengthBigCube - 1][yf][z1].setTransparency(0.5);
            a[LengthBigCube - 1][yf][z1].setColor(0.2, 0.0, 0.0);
            z1++;
            if (z1 > LengthBigCube - 1)
                z1 = 0;
            a[LengthBigCube - 1][yf][z1].setColor(1, 0.0, 0.0);
        } else if (arrow == 2)
        {//стрелочка вверх
            a[LengthBigCube - 1][yf][z1].setTransparency(0.5);
            a[LengthBigCube - 1][yf][z1].setColor(0.2, 0.0, 0.0);
            yf++;
            if (yf > LengthBigCube - 1)
                yf = 0;
            a[LengthBigCube - 1][yf][z1].setColor(1, 0.0, 0.0);
        } else if (arrow == 1)
        {//стрелочка влево
            a[LengthBigCube - 1][yf][z1].setTransparency(0.5);
            a[LengthBigCube - 1][yf][z1].setColor(0.2, 0.0, 0.0);
            z1--;
            if (z1 < 0)
                z1 = LengthBigCube - 1;
            a[LengthBigCube - 1][yf][z1].setColor(1, 0.0, 0.0);
        } else if (arrow == 3)
        {
            a[LengthBigCube - 1][yf][z1].setTransparency(0.5);
            a[LengthBigCube - 1][yf][z1].setColor(0.2, 0.0, 0.0);
            yf--;
            if (yf < 0)
                yf = LengthBigCube - 1;
            a[LengthBigCube - 1][yf][z1].setColor(1, 0.0, 0.0);

        }
    } else if (secondSide)
    {
        a[0][LengthBigCube - 1][LengthBigCube - 1].setTransparency(0.5);
        a[0][LengthBigCube - 1][LengthBigCube - 1].setColor(0.0, 0.2, 0.0);


        if (arrow == 2)
        {//работает стрелочка вправо
            a[x2][LengthBigCube - 1][z2].setTransparency(0.5);
            a[x2][LengthBigCube - 1][z2].setColor(0.0, 0.2, 0.0);
            z2--;
            if (z2 < 0)
                z2 = LengthBigCube - 1;
            a[x2][LengthBigCube - 1][z2].setColor(0, 1, 0.0);
        } else if (arrow == 1)
        {//стрелочка вверх
            a[x2][LengthBigCube - 1][z2].setTransparency(0.5);
            a[x2][LengthBigCube - 1][z2].setColor(0.0, 0.2, 0.0);
            x2++;
            if (x2 > LengthBigCube - 1)
                x2 = 0;
            a[x2][LengthBigCube - 1][z2].setColor(0, 1, 0.0);
        } else if (arrow == 3)
        {//стрелочка влево
            a[x2][LengthBigCube - 1][z2].setTransparency(0.5);
            a[x2][LengthBigCube - 1][z2].setColor(0.0, 0.2, 0.0);
            z2++;
            if (z2 > LengthBigCube - 1)
                z2 = 0;
            a[x2][LengthBigCube - 1][z2].setColor(0, 1, 0.0);
        } else if (arrow == 4)
        {//стрелочка вниз
            a[x2][LengthBigCube - 1][z2].setTransparency(0.5);
            a[x2][LengthBigCube - 1][z2].setColor(0.0, 0.2, 0.0);
            x2--;
            if (x2 < 0)
                x2 = LengthBigCube - 1;
            a[x2][LengthBigCube - 1][z2].setColor(0, 1, 0.0);

        }

    } else if (thirdSide)
    {
        a[0][LengthBigCube - 1][LengthBigCube - 1].setTransparency(0.5);
        a[0][LengthBigCube - 1][LengthBigCube - 1].setColor(0.0, 0.0, 0.2);


        if (arrow == 1)
        {//работает стрелочка вправо
            a[x3][y3][LengthBigCube - 1].setTransparency(0.5);
            a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 0.2);
            x3++;
            if (x3 > LengthBigCube - 1)
                x3 = 0;
            a[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
        } else if (arrow == 3)
        {//стрелочка вверх
            a[x3][y3][LengthBigCube - 1].setTransparency(0.5);
            a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 0.2);
            y3--;
            if (y3 < 0)
                y3 = LengthBigCube - 1;
            a[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
        } else if (arrow == 4)
        {//стрелочка влево
            a[x3][y3][LengthBigCube - 1].setTransparency(0.5);
            a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 0.2);
            x3--;
            if (x3 < 0)
                x3 = LengthBigCube - 1;
            a[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
        } else if (arrow == 2)
        {//стрелочка вниз
            a[x3][y3][LengthBigCube - 1].setTransparency(0.5);
            a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 0.2);
            y3++;
            if (y3 > LengthBigCube - 1)
                y3 = 0;
            a[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
        }
    }
    forEnter = 3;
}

void ChooseCube(int page)
{
    if (firstSide)
    {
        a[p1][yf][z1].setTransparency(1);

        if (page == 1)
        {
            a[p1][yf][z1].setTransparency(0.2);
            p1++;
            if (p1 > LengthBigCube - 1)
                p1 = 0;
            a[p1][yf][z1].setTransparency(1);
        } else if (page == 2)
        {
            a[p1][yf][z1].setTransparency(0.2);
            p1--;
            if (p1 < 0)
                p1 = LengthBigCube - 1;
            a[p1][yf][z1].setTransparency(1);
        }
    } else if (secondSide)
    {
        a[x2][p2][z2].setTransparency(1);

        if (page == 1)
        {
            a[x2][p2][z2].setTransparency(0.2);
            p2++;
            if (p2 > LengthBigCube - 1)
                p2 = 0;
            a[x2][p2][z2].setTransparency(1);
        } else if (page == 2)
        {
            a[x2][p2][z2].setTransparency(0.2);
            p2--;
            if (p2 < 0)
                p2 = LengthBigCube - 1;
            a[x2][p2][z2].setTransparency(1);
        }
    } else if (thirdSide)
    {
        a[x3][y3][p3].setTransparency(1);

        if (page == 1)
        {
            a[x3][y3][p3].setTransparency(0.2);
            p3++;
            if (p3 > LengthBigCube - 1)
                p3 = 0;
            a[x3][y3][p3].setTransparency(1);
        } else if (page == 2)
        {
            a[x3][y3][p3].setTransparency(0.2);
            p3--;
            if (p3 < 0)
                p3 = LengthBigCube - 1;
            a[x3][y3][p3].setTransparency(1);
        }

    }
}

// 1 == left, 2 == up, 3 == down, 4 == right
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
    {
        if (forEnter == -1)
        {
            if (cubeA)
            {
                cubeA = false;
                for (auto &i : a)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 1, 1);
                for (auto &i : b)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            } else
            {
                cubeA = true;
                for (auto &i : b)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 1, 1);
                for (auto &i : a)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            }
            forOnePaint = 0;
        } else if (movement && forEnter != -1)
        {
            //if (rotate_y <= 175)
            rotate_y += 5;
        } else
            ChooseColumn(4);
    }//если нажата клавиша "вправо", то поворачиваем

    else if (key == GLUT_KEY_LEFT)
    {
        if (forEnter == -1)
        {
            if (cubeA)
            {
                cubeA = false;
                for (auto &i : a)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 1, 1);
                for (auto &i : b)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            } else
            {
                cubeA = true;
                for (auto &i : b)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 1, 1);
                for (auto &i : a)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            }
            forOnePaint = 0;
        } else if (movement && forEnter != -1)
        {
            //if (rotate_y >= 95)
            rotate_y -= 5;
        } else
            ChooseColumn(1);
    }//аналогично для левой клавиши

    else if (key == GLUT_KEY_UP)
    {
        if (forEnter == -1)
        {

        } else if (movement && forEnter != -1)
        {
            //if (rotate_x <= -5)
            rotate_x += 5;
        } else
            ChooseColumn(2);
    } //это уже повороты  вверх и вниз

    else if (key == GLUT_KEY_DOWN)
    {
        if (forEnter == -1)
        {

        } else if (movement && forEnter != -1)
        {
            //if (rotate_x >= -85)
            rotate_x -= 5;
        } else
            ChooseColumn(3);
    } else if (key == GLUT_KEY_HOME && forEnter <= 1)
    {
        default_position(r_rotate_x, r_rotate_y);
    } else if (key == GLUT_KEY_PAGE_UP && (forEnter == 4 || forEnter == 5))
    {
        ChooseCube(1);
        forEnter = 5;
    } else if (key == GLUT_KEY_PAGE_DOWN && (forEnter == 4 || forEnter == 5))
    {
        ChooseCube(2);
        forEnter = 5;
    }


    if (key == GLUT_KEY_F7 && (forEnter == 0 || forEnter == 1))
    {
        view_first_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        movement = false;
        firstSide = true;
        thirdSide = false;
        secondSide = false;
    } else if (key == GLUT_KEY_F8 && (forEnter == 0 || forEnter == 1))
    {
        view_second_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        secondSide = true;
        firstSide = false;
        thirdSide = false;
    } else if (key == GLUT_KEY_F9 && (forEnter == 0 || forEnter == 1))
    {
        view_third_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        thirdSide = true;
        firstSide = false;
        secondSide = false;
    }

    /*if (key == GLUT_KEY_RIGHT && forEnter == 2) //если нажата клавиша "вправо", то поворачиваем
    {}

    else if (key == GLUT_KEY_LEFT && forEnter == 2)  //аналогично для левой клавиши
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP && forEnter == 2)  //это уже повороты  вверх и вниз
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN && forEnter == 2)
        rotate_x -= 5;

   */
    glutPostRedisplay(); //а это просто обязательная функция
}


#endif //INC_3DSEEBUTTLE_WORKWITHKEYS_H