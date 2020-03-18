//
// Created by alik on 18.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CUBE_H
#define INC_3DSEEBUTTLE_CUBE_H

class Cube{
private:
    double transparency;  //прозрачность
    double length;  //длина стороны
    int forColor;  //для ударов и выбора кубика

    double red;
    double blue;
    double green;

    double x;
    double y;
    double z;

public:
    Cube(){
         transparency = 0;
         length = 0;
         forColor = 0;

         red = 1;
         blue = 1;
         green = 1;

         x = 0;
         y = 0;
         z = 0;
    }
    Cube(double length, double x, double y, double z, double red, double blue, double green, double transparency){
        this->length = length;
        this->transparency = transparency;
        forColor = 0;

        this->red = red;
        this->blue = blue;
        this->green = green;

        this->x = x;
        this->y = y;
        this->z = z;

        glBegin(GL_POLYGON);  //начинаем рисовать грань
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z - length/2);  //здесь и далее сначала цвет
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z - length/2);  //(красный, зеленый, синий, прозрачность)
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z - length/2);  //потом идет положение точки
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z - length/2);  //4 точки - 1 грань
        glEnd();  //закончили рисовать одну грань

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glEnd();
/*
        //пошли ребра
        glBegin(GL_LINES);  //начинаем рисовать рёбра
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j,-sizeCell + y);  //(красный, зеленый, синий, прозрачность)
        glEnd();  //одно ребро
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j,-sizeCell + y);  //(красный, зеленый, синий, прозрачность)
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
        glEnd();  //второе ребро
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
        glEnd();  //третье ребро
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
        glEnd();  //четвёртое ребро

        //следующая грань
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
        glEnd();

        //следующая
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
        glEnd();

        //ещё одна
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
        glEnd();

        //немного осталось
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
        glEnd();

        //последняя
        glBegin(GL_LINES);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
        glColor3f(red, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(r, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
        glColor3f(r, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(r, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
        glColor3f(r, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(r, g, b);
        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
        glColor3f(r, g, b);
        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
        glEnd();*/
    }


};

#endif //INC_3DSEEBUTTLE_CUBE_H
