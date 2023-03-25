#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"
#include <cmath>

void cgrDesenharPontosDepth(
    int mes, int dados2005[8], int dados2006[8],
    int dados2007[8], int dados2008[8], int dados2009[8],
    int dados2010[8], int dados2011[8], int dados2012[8],
    int dados2013[8], int dados2014[8], int dados2015[8])
{

    glPolygonMode(GL_FRONT_AND_BACK, GL_POINTS);
    glPointSize(8);

    std::cout << "\n------" << std::endl;
        
        if(mes == 1){
            std::cout << "\nMes: Maio" << std::endl;
        }else if(mes == 2){
            std::cout << "\nMes: Junho" << std::endl;
        }else if(mes ==3){
            std::cout << "\nMes: Julho" << std::endl;
        }else if(mes ==4){
            std::cout << "\nMes: Agosto" << std::endl;
        }else if(mes ==5){
            std::cout << "\nMes: Setembro" << std::endl;
        }else if(mes ==6){
            std::cout << "\nMes: Outubro" << std::endl;
        }else if(mes ==7){
            std::cout << "\nMes: Novembro" << std::endl;
        }else if(mes ==8){
            std::cout << "\nMes: Dezembro" << std::endl;
        }
        std::cout
        << "\n2005:" << dados2005[mes-1]
        << "\n2006:" << dados2006[mes-1]
        << "\n2007:" << dados2007[mes-1]
        << "\n2008:" << dados2008[mes-1]
        << "\n2009:" << dados2009[mes-1]
        << "\n2010:" << dados2010[mes-1]
        << "\n2011:" << dados2011[mes-1]
        << "\n2012:" << dados2012[mes-1]
        << "\n2013:" << dados2013[mes-1]
        << "\n2014:" << dados2014[mes-1]
        << "\n2015:" << dados2015[mes-1]
        << std::endl;

    // Cada ano é -0.3 no eixo X, cada caso de vendaval é 0.25 no eixo Y * a quantia de casos
        GLfloat vertices[] = {
            -2+(0.3*11), 0.25*dados2015[mes-1],0,
            -2+(0.3*10), 0.25*dados2014[mes-1],0,
            -2+(0.3*9), 0.25*dados2013[mes-1],0,
            -2+(0.3*8), 0.25*dados2012[mes-1],0,
            -2+(0.3*7), 0.25*dados2011[mes-1],0,
            -2+(0.3*6), 0.25*dados2010[mes-1],0,
            -2+(0.3*5), 0.25*dados2009[mes-1],0,
            -2+(0.3*4), 0.25*dados2008[mes-1],0,
            -2+(0.3*3), 0.25*dados2007[mes-1],0,
            -2+(0.3*2), 0.25*dados2006[mes-1],0,
            -2+(0.3*1), 0.25*dados2005[mes-1],0,
            };

    GLfloat cores[] =
        {
            1, 0, 0, // dado de 2015 - vermelho
            0, 1, 0, // dado de 2014 -verde
            0, 0, 1, // dado de 2013 -azul
            0, 1, 1, // dado de 2012 -ciano
            1, 1, 0, // dado de 2011 -amarelo
            1, 0.5, 0,//dado de 2010 -laranja
            0.5, 0, 0,//dado de 2009 -marrom
            0, 0.5, 0,//dado de 2008 -verde escuro
            0, 0, 0.5,//dado de 2007 - azul mais escuro
            0, 1, 0.5,//dado de 2006 - ciano mais esverdeado
            1, 0, 0.5 //dado de 2005 - rosa
            };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, cores);

    glDrawArrays(GL_POINTS, 0, 11);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void cgrDesenharLinha(
    int mes, int dados2005[8], int dados2006[8],
    int dados2007[8], int dados2008[8], int dados2009[8],
    int dados2010[8], int dados2011[8], int dados2012[8],
    int dados2013[8], int dados2014[8], int dados2015[8])
{

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE_STRIP);

    std::cout << "\n------" << std::endl;
        
        if(mes == 1){
            std::cout << "\nMes: Maio" << std::endl;
        }else if(mes == 2){
            std::cout << "\nMes: Junho" << std::endl;
        }else if(mes ==3){
            std::cout << "\nMes: Julho" << std::endl;
        }else if(mes ==4){
            std::cout << "\nMes: Agosto" << std::endl;
        }else if(mes ==5){
            std::cout << "\nMes: Setembro" << std::endl;
        }else if(mes ==6){
            std::cout << "\nMes: Outubro" << std::endl;
        }else if(mes ==7){
            std::cout << "\nMes: Novembro" << std::endl;
        }else if(mes ==8){
            std::cout << "\nMes: Dezembro" << std::endl;
        }
        std::cout
        << "\n2005:" << dados2005[mes-1]
        << "\n2006:" << dados2006[mes-1]
        << "\n2007:" << dados2007[mes-1]
        << "\n2008:" << dados2008[mes-1]
        << "\n2009:" << dados2009[mes-1]
        << "\n2010:" << dados2010[mes-1]
        << "\n2011:" << dados2011[mes-1]
        << "\n2012:" << dados2012[mes-1]
        << "\n2013:" << dados2013[mes-1]
        << "\n2014:" << dados2014[mes-1]
        << "\n2015:" << dados2015[mes-1]
        << std::endl;

    // Cada ano é -0.3 no eixo X, cada caso de vendaval é 0.25 no eixo Y * a quantia de casos
        GLfloat vertices[] = {
            -2+(0.3*11), 0.25*dados2015[mes-1],0,
            -2+(0.3*10), 0.25*dados2014[mes-1],0,
            -2+(0.3*9), 0.25*dados2013[mes-1],0,
            -2+(0.3*8), 0.25*dados2012[mes-1],0,
            -2+(0.3*7), 0.25*dados2011[mes-1],0,
            -2+(0.3*6), 0.25*dados2010[mes-1],0,
            -2+(0.3*5), 0.25*dados2009[mes-1],0,
            -2+(0.3*4), 0.25*dados2008[mes-1],0,
            -2+(0.3*3), 0.25*dados2007[mes-1],0,
            -2+(0.3*2), 0.25*dados2006[mes-1],0,
            -2+(0.3*1), 0.25*dados2005[mes-1],0,
            };

    GLfloat cores[] =
        {
            1, 0, 0, // dado de 2015 - vermelho
            0, 1, 0, // dado de 2014 -verde
            0, 0, 1, // dado de 2013 -azul
            0, 1, 1, // dado de 2012 -ciano
            1, 1, 0, // dado de 2011 -amarelo
            1, 0.5, 0,//dado de 2010 -laranja
            0.5, 0, 0,//dado de 2009 -marrom
            0, 0.5, 0,//dado de 2008 -verde escuro
            0, 0, 0.5,//dado de 2007 - azul mais escuro
            0, 1, 0.5,//dado de 2006 - ciano mais esverdeado
            1, 0, 0.5 //dado de 2005 - rosa
            };
            
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, cores);

    glDrawArrays(GL_LINE_STRIP, 0, 11);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void cgrDesenharCubo()
{

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // GL_LINE, GL_POINT, GL_FILL

    // vertices do cubo (modelo, objeto) estao no intervalo [-1, 1]
    GLfloat verticesCubo[] =
        {
            -2, -2, -2, -2, -2, 2, -2, 2, 2, -2, 2, -2,
            2, -2, -2, 2, -2, 2, 2, 2, 2, 2, 2, -2,
            -2, -2, -2, -2, -2, 2, 2, -2, 2, 2, -2, -2,
            -2, 2, -2, -2, 2, 2, 2, 2, 2, 2, 2, -2,
            -2, -2, -2, -2, 2, -2, 2, 2, -2, 2, -2, -2,
            -2, -2, 2, -2, 2, 2, 2, 2, 2, 2, -2, 2};

    GLfloat coresCubo[] =
        {
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1};

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, verticesCubo);
    glColorPointer(3, GL_FLOAT, 0, coresCubo);

    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void cgrDesenharPiramide()
{

    GLfloat verticesPiramide[] = {
        -0.5, 0.0, 0.5, 0.0, 1.0, 0.0, 0.5, 0.0, 0.5,
        -0.5, 0.0, -0.5, 0.0, 1.0, 0.0, -0.5, 0.0, 0.5,

        -0.5, 0.0, -0.5, 0.0, 1.0, 0.0, 0.5, 0.0, -0.5,
        0.5, 0.0, -0.5, 0.0, 1.0, 0.0, 0.5, 0.0, 0.5,

        -0.5, 0.0, 0.5, -0.5, 0.0, -0.5, 0.5, 0.0, 0.5, // base - 2 triangulos
        -0.5, 0.0, -0.5, 0.5, 0.0, -0.5, 0.5, 0.0, 0.5};

    GLfloat coresPiramide[] = {
        0, 0, 0.4, 0, 0, 0.4, 0, 0, 0.4,             // azul escuro
        1, 0.5, 0, 1, 0.5, 0, 1, 0.5, 0,             // laranja
        1, 1, 0, 1, 1, 0, 1, 1, 0,                   // amarelo
        0, 1, 0.5, 0, 1, 0.5, 0, 1, 0.5,             // verde
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, // preto
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0  // preto
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // modo de tracado - linhas (inspecao visual)
    glLineWidth(3.0);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, verticesPiramide); // size, tipo, deslocamento inicial, ponteiro
    glColorPointer(3, GL_FLOAT, 0, coresPiramide);     // size, tipo, deslocamento inicial, ponteiro

    glDrawArrays(GL_TRIANGLES, 0, 6 * 3); // desenha os pontos da piramide

    // limpa estados
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}