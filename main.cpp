
#include <GL/glut.h>  //библиотека GLUT
#include "Painting.h"  //подключаем файлы заголовочные
#include "WorkWithKeys.h"  //работа с клавиатурой
#include "Cube.h"
//много всего и всё служебное

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //параметры окна(двойная буферизация и всё такое)
    glutInitWindowSize(1200, 800);  //это размеры окна
    glutCreateWindow("Awesome Cube");  //это название создающегося окна
    glEnable(GL_DEPTH_TEST);  //тест глубины или что-то такое
    glutDisplayFunc(displayCell);  //вызвываем функцию, которая рисует кубы
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(specialKeys);  //вызываем функцию для поворотов кубиков

    glutMainLoop();  //а это бесконечный цикл
    return 0;

}