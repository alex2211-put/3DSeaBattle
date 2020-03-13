//
// Created by alik on 13.03.2020.
//

// по-хорошему заголовочный файл - это только описание функций, но так как OpenGL возмущается и не хочет работать
// то я напишу здесь сразу реализацию и не буду создавать .cpp файлы (незачем)


#ifndef INC_3DSEEBUTTLE_PAINTING_H
#define INC_3DSEEBUTTLE_PAINTING_H

double rotate_y=0;  //начальный поворот куба по у
double rotate_x=0; //начальный поворот куба по х
double sizeCell = -0.05; //размеры кубиков
double  stepCell = 0.1; //шаг при определении
double quantityCell = 0.5-0.4; //количестве кубиков, тоесть их всего  (quantityCell/stepCell)   #### вычел 0.4, чтобы сместить кубики и чтобы крутились вокруг центра
double transparency = 0.3; //прозрачность кубиков

//функция рисует 3Д кубики на экране
void displayCell(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"
    glLoadIdentity();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );  //функция, поворачивающая кубики по х
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );  //а это для у

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //устанавдиваем уровень прозрачности - пока до конца не разобрался

    for (float i = -0.4; i < quantityCell; i+=stepCell)  //опять же начинаю с -0.4  ### это чтобы сместить кубики и чтобы крутились вокруг центра
    {
        for (float j = -0.4; j < quantityCell; j+=stepCell)  //аналогия
        {
            for (float y = -0.4; y < quantityCell; y+=stepCell)   //аналогия
            {
                glBegin(GL_POLYGON);  //начинаем рисовать грань
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);  //потом идет положение точки
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                glEnd();  //закончили рисовать одну грань

                glBegin(GL_POLYGON);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  -sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  -sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i, sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i, sizeCell + j, sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f(  sizeCell + i,  -sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i,  -sizeCell + j, sizeCell + y);
                glColor4f( 0.5, 0.5, 0.5, transparency );     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();

                //пошли ребра
                glBegin(GL_LINES);  //начинаем рисовать рёбра
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                glEnd();  //одно ребро
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);  //потом идет положение точки
                glEnd();  //второе ребро
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);  //потом идет положение точки
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                glEnd();  //третье ребро
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                glEnd();  //четвёртое ребро

                //следующая грань
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();

                //следующая
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( sizeCell + i,  sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();

                //ещё одна
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  -sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  -sizeCell + i,  sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  -sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  -sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();

                //немного осталось
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, sizeCell + j, sizeCell + y);
                glEnd();

                //последняя
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  -sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i,  -sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  -sizeCell + j, sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i,  -sizeCell + j, sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor3f( 0.5, 0.5, 0.5);     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();

            }
        }
    }

    glFlush();
    glutSwapBuffers();
}


//функция взаимодействия с клавиатурой
void specialKeys( int key, int x, int y) {

    if (key == GLUT_KEY_RIGHT) //если нажата клавиша "вправо", то поворачиваем
        rotate_y += 5;

    else if (key == GLUT_KEY_LEFT)  //аналогично для левой клавиши
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)  //это уже повороты  вверх и вниз
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    glutPostRedisplay(); //а это просто обязательная функция

}


#endif //INC_3DSEEBUTTLE_PAINTING_H