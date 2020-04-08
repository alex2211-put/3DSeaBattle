//
// Created by alik on 18.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CUBE_H
#define INC_3DSEEBUTTLE_CUBE_H

#include <cmath>

const int LengthBigCube = 6;
int forEnter = -1;
bool firstSide = false, secondSide = false, thirdSide = false;
int forOnePaint = 0;

class Cube
{
private:
    double transparency;  //прозрачность
    double length;  //длина стороны
    int forHit;  //для ударов и выбора кубика  Если 1 - выбрали. Если 2 - стоит рядом с кубиком, который выбрали. Если 3 - в него выстрелили
    bool isPaint;
    //для переключений между режимами игрыы (выбор, стрельба)

    double red = 0.5;
    double blue = 0.5;
    double green = 0.8;

    double x;
    double y;
    double z;

public:
    int forTransparancy;

    Cube()
    {
        transparency = 0;
        length = 0;
        forHit = 0;
        forTransparancy = 0;
        isPaint = true;

        red = 0.5;
        blue = 0.8;
        green = 0.5;

        x = 0;
        y = 0;
        z = 0;
    }

    Cube(double length, double x, double y, double z, double transparency)
    {
        this->length = length;
        this->transparency = transparency;
        forHit = 0;
        forTransparancy = 0;
        isPaint = true;

        this->x = x;
        this->y = y;
        this->z = z;
    }


    void setColor(double Red, double Green, double Blue)
    {
        this->red = Red;
        this->blue = Blue;
        this->green = Green;
    }

    void setPaint(bool isPainted)
    {
        this->isPaint = isPainted;
    }

    bool getPaint()
    {
        return isPaint;
    }

    void setTransparency(double transparancy)
    {
        this->transparency = transparancy;
        forTransparancy = 1;
    }

    void setTransparancyNothing()
    {
        if (forTransparancy == 0)
        {
            transparency = 0.11;
            setColor(0.5, 0.5, 0.8);
        }
    }

    void paintForRotate(double angle);

    void paintCube();

    void setIsHitten(int hit)
    {
        this->forHit = hit;
    }

    int getHit()
    {
        return forHit;
    }
};

#endif //INC_3DSEEBUTTLE_CUBE_H
