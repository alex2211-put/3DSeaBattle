//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CHOOSESIDE_H
#define INC_3DSEEBUTTLE_CHOOSESIDE_H


#include "Cube.h"
#include "Painting.h"


void choose_first_side(double &rotateX, double &rotateY)
{

    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            a[LengthBigCube - 1][j][k].setColor(0.2, 0, 0);
            a[LengthBigCube - 1][j][k].setTransparency(0.5);
        }

    rotateX = 0;
    rotateY = 90;
}

void choose_second_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : a)
        for (int k = 0; k < LengthBigCube; k++)
        {
            j[LengthBigCube - 1][k].setColor(0, 0.2, 0);
            j[LengthBigCube - 1][k].setTransparency(0.5);
        }

    rotateX = -90;
    rotateY = 180;
}

void choose_third_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : a)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 0.2);
            k[j][LengthBigCube - 1].setTransparency(0.5);
        }

    rotateX = 0;
    rotateY = 180;
}

void default_position(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
                k.setColor(0.5, 0.5, 0.8);
                k.setTransparency(0.11);
            }

    rotateX = 325;
    rotateY = 135;
}

void view_first_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            a[LengthBigCube - 1][j][k].setColor(1, 0, 0);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_second_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : a)
        for (int k = 0; k < LengthBigCube; k++)
        {
            j[LengthBigCube - 1][k].setColor(0, 1, 0);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_third_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : a)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}


#endif //INC_3DSEEBUTTLE_CHOOSESIDE_H
