#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <GLFW/glfw3.h>
#include "cgrDesenharBasico.hpp"

/** variaveis de controle - global **/
float zoom_level = 0.0, zoom_min = 10, zoom_max = 100, rot_x = 0.0;
int mes = 1, strip = 0, 
    dados2005[8],
    dados2006[8],
    dados2007[8],
    dados2008[8],
    dados2009[8],
    dados2010[8],
    dados2011[8],
    dados2012[8],
    dados2013[8],
    dados2014[8],
    dados2015[8];;

/** assinatura das funcoes **/
/** configuracoes iniciais **/
void aplicarConfigInicial(GLFWwindow *window);

/** tecla pressionada **/
void processarTeclado(GLFWwindow *window, int key, int scancode, int action, int mode);
/** movimento do mouse **/
void processarMovimentoMouse(GLFWwindow *window, double xpos, double ypos);

/** janela redimensionada**/
void ajustarJanela(GLFWwindow *window, int w, int h);

void desenharGrafico(int mes)
{
    glClear(GL_COLOR_BUFFER_BIT); // cor de fundo
    glClear(GL_DEPTH_BUFFER_BIT); // z-buffer

    glMatrixMode(GL_MODELVIEW);                       // indicar qual matriz sera modificada
    glLoadIdentity();                                 // "reset" na matriz
    glTranslatef(0.0, 0.0, -(zoom_min + zoom_level)); // nivel de zoom da cena
    // fim da definicao das transformacoes da cena como um todo (camera ou view)

    glPushMatrix(); // adicionar matriz na pilha

    // transformacoes dos modelos
    glRotatef(rot_x, 0.0, 1.0, 0.0); // rotacionando ao longo de y
    glScalef(2.0, 2.0, 0.5);         // ex. escala
    cgrDesenharCubo();
    if(strip == 0){
        cgrDesenharPontosDepth(mes, dados2005, dados2006, dados2007,
        dados2008, dados2009, dados2010, dados2011, dados2012,
        dados2013, dados2014, dados2015);
    }else{
        cgrDesenharLinha(mes, dados2005, dados2006, dados2007,
        dados2008, dados2009, dados2010, dados2011, dados2012,
        dados2013, dados2014, dados2015);
    }
    
}

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 766, "Trabalho 1 - Projeção de Dados: Maio", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    // aplicando configuracoes --> outros nomes: init ou setup
    aplicarConfigInicial(window);

    std::ifstream file;
    //int dados2005[8];

    file.open("hurricanes_no_header.csv", std::ifstream::in);
    if (!file.is_open())
    {
        std::cerr << "Não foi possível ler o .csv" << std::endl;
        return 1;
    }


    std::string aux;
    int i = 0, val = 0;
    
    while (!file.eof())
    {
        char mes[64] = "";
        file.getline(mes, 63, ';');
        if (mes[0] == '\x0')
            break;

        char media[64] = "";
        file.getline(media, 63, ';');

        char ano2005[16] = "";
        file.getline(ano2005, 15, ';');
        aux = (ano2005);
        val = stoi(aux);
        dados2005[i] = val;

        char ano2006[16] = "";
        file.getline(ano2006, 15, ';');
        aux = (ano2006);
        val = stoi(aux);
        dados2006[i] = val;

        char ano2007[16] = "";
        file.getline(ano2007, 15, ';');
        aux = (ano2007);
        val = stoi(aux);
        dados2007[i] = val;

        char ano2008[16] = "";
        file.getline(ano2008, 15, ';');
        aux = (ano2008);
        val = stoi(aux);
        dados2008[i] = val;

        char ano2009[16] = "";
        file.getline(ano2009, 15, ';');
        aux = (ano2009);
        val = stoi(aux);
        dados2009[i] = val;

        char ano2010[16] = "";
        file.getline(ano2010, 15, ';');
        aux = (ano2010);
        val = stoi(aux);
        dados2010[i] = val;

        char ano2011[16] = "";
        file.getline(ano2011, 15, ';');
        aux = (ano2011);
        val = stoi(aux);
        dados2011[i] = val;

        char ano2012[16] = "";
        file.getline(ano2012, 15, ';');
        aux = (ano2012);
        val = stoi(aux);
        dados2012[i] = val;

        char ano2013[16] = "";
        file.getline(ano2013, 15, ';');
        aux = (ano2013);
        val = stoi(aux);
        dados2013[i] = val;

        char ano2014[16] = "";
        file.getline(ano2014, 15, ';');
        aux = (ano2014);
        val = stoi(aux);
        dados2014[i] = val;

        char ano2015[16] = "";
        file.getline(ano2015, 15, ';');
        aux = (ano2015);
        val = stoi(aux);
        dados2015[i] = val;

        /*
        std::cout
        << "\n------"
        << "\nMes: " << mes
        << "\nMedia: " << media
        << "\n2005:" << ano2005
        << "\n2006:" << ano2006
        << "\n2007:" << ano2007
        << "\n2008:" << ano2008
        << "\n2009:" << ano2009
        << "\n2010:" << ano2010
        << "\n2011:" << ano2011
        << "\n2012:" << ano2012
        << "\n2013:" << ano2013
        << "\n2014:" << ano2014
        << "\n2015:" << ano2015
        << std::endl;
        */
        i++;
    }

    file.close();

    //Testando pra ver se consegui converter os dados:
    /*
    std::cout << "Ano de 2005: " << std::endl;
    for(int i = 0; i<8; i++){
        std::cout << "Mês: " << i << " | -> Ano de 2005:" << dados2005[i] << std::endl;
    }
    std::cout << "\n\nAno de 2015: " << std::endl;
    for(int i = 0; i<8; i++){
        std::cout << "Mês: " << i << "| -> Ano de 2015:" << dados2015[i] << std::endl;
    }
    */

    /* Loop until the user closes the window */
    // render loop
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        desenharGrafico(mes); // composicao - cena 1

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

/**
 * Configuracoes do world system **/
void aplicarConfigInicial(GLFWwindow *window)
{
    glEnable(GL_DEPTH_TEST); // habilita z-buffer (depth test)

    int largura, altura;
    glfwGetWindowSize(window, &largura, &altura); // obtem largura e altura

    // especificacao da cor de fundo
    // red, green, blue, alpha
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // registro de quais funcoes serao executadas apos eventos
    glfwSetWindowSizeCallback(window, ajustarJanela);
    glfwSetCursorPosCallback(window, processarMovimentoMouse);
    glfwSetKeyCallback(window, processarTeclado);
    ajustarJanela(window, largura, altura);
}

/** configuracao para ser executada a cada redimensionamento
 * e tambem na primeira vez que o codigo for ser executado **/
void ajustarJanela(GLFWwindow *window, int w, int h)
{
    std::cout << "Dimensoes atuais da janela: " << w << ", " << h << std::endl;

    // lower x, lower y, largura, altura (em pixels)
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); // indicar qual matriz sera modificada
    glLoadIdentity();            // "reset" na matriz de projecao

    // definicao do viewing box que sera utilizado (universo)
    // left, right, bottom, top, near, far (near e far com sinal trocado)
    // glOrtho(-1.0, 1.0,    -1.0, 1.0,  -1.0, 1.0);
    // glOrtho( 0.0, 200.0,   0.0, 100.0, -1.0, 1.0);

    // left, right, bottom, top, near, far (near e far com sinais trocados)
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
}

/** tecla pressionada **/
void processarTeclado(GLFWwindow *window, int key, int scancode, int action, int mode)
{

    std::cout << "Uma tecla foi pressionada: key " << key << std::endl;
    float zoom_step = 1.0;
    float rot_step = 8.0;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        std::cout << "ESC pressionado " << std::endl;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    // configuracao de zoom
    else if (key == GLFW_KEY_KP_ADD && action == GLFW_PRESS)
    {
        zoom_level = zoom_level - zoom_step;
        std::cout << "zoom in pressionado - nivel de zoom: " << zoom_level << std::endl;
    }
    else if (key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS)
    {
        zoom_level = zoom_level + zoom_step;
        std::cout << "zoom out pressionado - nivel de zoom: " << zoom_level << std::endl;
    }

    // configuração da rotação do eixo X
    else if (key == GLFW_KEY_J && action == GLFW_PRESS)
    {
        rot_x = rot_x - rot_step;
        std::cout << "Rotacionando no eixo X, indo para a esquerda: " << rot_x << std::endl;
    }
    else if (key == GLFW_KEY_L && action == GLFW_PRESS)
    {
        rot_x = rot_x + rot_step;
        std::cout << "Rotacionando no eixo X, indo para a direita: " << rot_x << std::endl;
    }

    //habilitar line strip
    else if(key == GLFW_KEY_1 && action == GLFW_PRESS){
        if(strip == 0){
            strip = 1;
            std::cout << "Projeção com Line Strip Habilitada." << std::endl;
        } else {
            strip = 0;
            std::cout << "Projeção sem Line Strip." << std::endl;
        }
    }
    // mudar os meses
    else if (key == GLFW_KEY_M && action == GLFW_PRESS)
    {
        if (mes < 8)
        {
            mes++;
            if(mes == 2){
                glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Junho");
            }else if(mes == 3){
                glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Julho");
            }else if(mes == 4){
                glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Agosto");
            }else if(mes == 5){
                glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Setembro");
            }else if(mes == 6){
                glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Outubro");
            }else if(mes == 7){
                glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Novembro");
            }else if(mes == 8){
                glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Dezembro");
            }      
        }
        else if (mes == 8)
        {
            mes = 1;
            glfwSetWindowTitle(window,"Trabalho 1 - Projeção de Dados: Maio");   
        }
        std::cout << "Mes: " << mes << "º do CSV" << std::endl;
    }
}

/** movimento do mouse **/
void processarMovimentoMouse(GLFWwindow *window, double xpos, double ypos)
{
    // std::cout << "Mouse movimentado: " << xpos << ", " << ypos << std::endl;
}