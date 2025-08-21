#include "Texture.h"
#include <corecrt_math_defines.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_imageR.h"
#include "Camisa.hpp"
#include <GL/glew.h>
#include <Windows.h>
#include <iostream>
#include <unordered_map>
#include <thread>
#include <atomic>
#include "MinHook.h"
#include <string>
#include <vector>

///Chams Que No Crash
bool Chams3D;
bool GlowAnimado;
bool Glow;
bool HdRmap;
bool ChamsWokung;
bool ChamsWokungOld;
bool MapaOcuro;
bool Black;
bool Oreon;
bool Solido;
bool WukongSolara;
bool Pick;
bool ChamsLegendario;
bool MapaBendi;
bool Rgb;
bool Wireframe;
bool Araña3D;
bool Santino3D;
bool Lava;
bool galaxy;
bool goldengalaxy;
bool Glitch;
bool starfield;
bool Creeper;
bool Spiderman;
bool matrix;
bool whiteglich;

// Chams Por Poner
bool lataglich;
bool txglich;
bool rainbowswirl;
bool Disco;

//Solucion Glich
GLuint ErrorChamsZ = 0;

//Wukong
GLuint Color = 0;

//Camisa
GLuint ImgCamisa = 0;
zCamisa miCamisa;


GLfloat blendColor1[4] = { 57 / 255.f, 215 / 255.f, 22 / 255.f, 1.0f };
GLfloat blendColor2[4] = { 57 / 255.f, 215 / 255.f, 22 / 255.f, 1.0f };




static float width = 1.5f;
static float widthx = 0.923f;
static float AnimacionSpped = 0.1f;
static float height = 0.523f;
static float lineBox = 1.5f;
static float lineWidth = 2.f;
static float frequency = 1.f;
int countThreshold = 1200;

int baseThreshold = 8100;
int maxSliderValue = 12000;
int dynamicRange = countThreshold;


// ChamsPn
float width_cabezaSS = 1.0f;
float height_cabezaSS = 1.0f;
float rectangleX_cabezaSS = 0.0f;
float rectangleY_cabezaSS = 0.0f;
float rectangleZ_cabezaSS = 1.3f;
float rotationX_cabezaSS = 90.0f;
float rotationY_cabezaSS = 90.0f;


//Navidad
float lineScale = 0.005f;
float lineHeight = 0.15f;
#define GL_PI 3.14159


// Corazon
float rotationX_corazonss = 90.0f;
float rotationY_corazonss = 90.0f;
float rectangleX_corazon = 0.0f;
float rectangleY_corazon = 0.0f;


// Antiguo
static float frequencyM = 0.600;
static float lineWidthM = 1.0;
static float lineWidthT = 1.0;
static float lineWidthSS = 1.0f;
static float scale = 0.1f;



using namespace std;

void (WINAPI* oglDrawElements)(GLenum mode, GLsizei count, GLenum type, const void* indices);

GLuint gTexCyan;
GLuint gTexRed;
GLuint gTexYellow;
GLuint gTexPurple;

std::unordered_map<std::string, ChamsInfo> gChamsDescs
{
    {"_CharaLightIntensity", {&gTexCyan, &gTexYellow}} ,{"_ShadowThreshold", {&gTexCyan, &gTexYellow}},{"_RimContrast2", {&gTexCyan, &gTexYellow}}
};

std::atomic_bool gbRunning = true;

bool CurrentShaderHasUniform(const std::string& uniform)
{
    GLint currProgram;
    glGetIntegerv(GL_CURRENT_PROGRAM, &currProgram);

    GLint id = -1;

    id = glGetUniformLocation(currProgram, uniform.c_str());

    return id != -1;
}

double getCurrentTime() {
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count() / 1000.0;
}

double getCurrentTimeX() {
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count() / 4000.0;
}


/////////////////////CILINDRO//////////////////////////////////////

float radius_33DS = 0.5f;

float circleX_33DS = 0.0f;
float circleY_33DS = 0.0f;
float circleZ_33DS = 0.0f;

float rotationX_33DS = 0.0f;
float rotationY_33DS = 0.0f;
void DrawCircle_3DS() {
    const int numSegments = 50;
    const float PI = 3.14159265358979323846f;

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float x = radius_33DS * cos(theta);
        float y = radius_33DS * sin(theta);


        float rotatedX = x * cos(rotationY_33DS) - y * sin(rotationY_33DS);
        float rotatedY = x * sin(rotationY_33DS) + y * cos(rotationY_33DS);

        x += circleX_33DS;
        y += circleY_33DS;

        glVertex3f(x, y, circleZ_33DS);
    }
    glEnd();
    glLineWidth(1.0f);
}


float radius_33DS2 = 0.5f;

float circleX_33DS2 = 0.0f;
float circleY_33DS2 = 0.0f;
float circleZ_33DS2 = 0.3f;

float rotationX_33DS2 = 0.0f;
float rotationY_33DS2 = 0.0f;
void DrawCircle_33DS2() {
    const int numSegments = 50;
    const float PI = 3.14159265358979323846f;

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float x = radius_33DS2 * cos(theta);
        float y = radius_33DS2 * sin(theta);


        float rotatedX = x * cos(rotationY_33DS2) - y * sin(rotationY_33DS2);
        float rotatedY = x * sin(rotationY_33DS2) + y * cos(rotationY_33DS2);

        x += circleX_33DS2;
        y += circleY_33DS2;

        glVertex3f(x, y, circleZ_33DS2);
    }
    glEnd();
    glLineWidth(1.0f);
}




float radius_33DS3 = 0.5f;

float circleX_33DS3 = 0.0f;
float circleY_33DS3 = 0.0f;
float circleZ_33DS3 = 0.6f;

float rotationX_33DS3 = 0.0f;
float rotationY_33DS3 = 0.0f;
void DrawCircle_33DS3() {
    const int numSegments = 50;
    const float PI = 3.14159265358979323846f;

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float x = radius_33DS3 * cos(theta);
        float y = radius_33DS3 * sin(theta);


        float rotatedX = x * cos(rotationY_33DS3) - y * sin(rotationY_33DS3);
        float rotatedY = x * sin(rotationY_33DS3) + y * cos(rotationY_33DS3);

        x += circleX_33DS3;
        y += circleY_33DS3;

        glVertex3f(x, y, circleZ_33DS3);
    }
    glEnd();
    glLineWidth(1.0f);
}



float radius_33DS4 = 0.5f;

float circleX_33DS4 = 0.0f;
float circleY_33DS4 = 0.0f;
float circleZ_33DS4 = 0.9f;

float rotationX_33DS4 = 0.0f;
float rotationY_33DS4 = 0.0f;
void DrawCircle_33DS4() {
    const int numSegments = 50;
    const float PI = 3.14159265358979323846f;

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float x = radius_33DS4 * cos(theta);
        float y = radius_33DS4 * sin(theta);


        float rotatedX = x * cos(rotationY_33DS4) - y * sin(rotationY_33DS4);
        float rotatedY = x * sin(rotationY_33DS4) + y * cos(rotationY_33DS4);

        x += circleX_33DS4;
        y += circleY_33DS4;

        glVertex3f(x, y, circleZ_33DS4);
    }
    glEnd();
    glLineWidth(1.0f);
}



float radius_33DS5 = 0.5f;

float circleX_33DS5 = 0.0f;
float circleY_33DS5 = 0.0f;
float circleZ_33DS5 = 1.2f;

float rotationX_33DS5 = 0.0f;
float rotationY_33DS5 = 0.0f;
void DrawCircle_33DS5() {
    const int numSegments = 50;
    const float PI = 3.14159265358979323846f;

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float x = radius_33DS5 * cos(theta);
        float y = radius_33DS5 * sin(theta);


        float rotatedX = x * cos(rotationY_33DS5) - y * sin(rotationY_33DS5);
        float rotatedY = x * sin(rotationY_33DS5) + y * cos(rotationY_33DS5);


        x += circleX_33DS5;
        y += circleY_33DS5;


        glVertex3f(x, y, circleZ_33DS5);
    }
    glEnd();
    glLineWidth(1.0f);
}


static float frequency1 = 1.400;
static float frequency2 = 2.500;
static float frequency3 = 3.600;
static float frequency4 = 4.700;
static float frequency5 = 5.900;

void rgb1()
{
    double time = getCurrentTime();
    float red = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency1 * time));
    float green = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency1 * time + 2.0 * 3.14159265358979323846 / 3.0));
    float blue = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency1 * time + 4.0 * 3.14159265358979323846 / 3.0));
    glEnable(GL_BLEND);
    glBlendColor(red, green, blue, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
}
void rgb2()
{
    double time = getCurrentTime();
    float red = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency2 * time));
    float green = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency2 * time + 2.0 * 3.14159265358979323846 / 3.0));
    float blue = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency2 * time + 4.0 * 3.14159265358979323846 / 3.0));
    glEnable(GL_BLEND);
    glBlendColor(red, green, blue, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
}
void rgb3()
{
    double time = getCurrentTime();
    float red = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency3 * time));
    float green = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency3 * time + 2.0 * 3.14159265358979323846 / 3.0));
    float blue = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency3 * time + 4.0 * 3.14159265358979323846 / 3.0));
    glEnable(GL_BLEND);
    glBlendColor(red, green, blue, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
}
void rgb4()
{
    double time = getCurrentTime();
    float red = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency4 * time));
    float green = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency4 * time + 2.0 * 3.14159265358979323846 / 3.0));
    float blue = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency4 * time + 4.0 * 3.14159265358979323846 / 3.0));
    glEnable(GL_BLEND);
    glBlendColor(red, green, blue, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
}
void rgb5()
{
    double time = getCurrentTime();
    float red = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency5 * time));
    float green = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency5 * time + 2.0 * 3.14159265358979323846 / 3.0));
    float blue = 0.5f * (1.0f + std::sin(2.0 * 3.14159265358979323846 * frequency5 * time + 4.0 * 3.14159265358979323846 / 3.0));
    glEnable(GL_BLEND);
    glBlendColor(red, green, blue, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
}

/////////////////////MOCOX//////////////////////////////////////
void MOCOX()
{
    float radio = 0.2f;
    for (float i = 0.f; i <= 2.0f * 3.1416; i += 0.1f)
    {
        float x = radio * cos(i);
        float y = radio * sin(i);
        glLineWidth(1.f);
        glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 1.4f);
        glVertex3f(x, y, 1.8f);
        glEnd();

    }
}

void RotatePoint(float& x, float& y, float angleDegrees) {
    float angleRadians = angleDegrees * (3.14159265359f / 180.0f);
    float tempX = x * cos(angleRadians) - y * sin(angleRadians);
    float tempY = x * sin(angleRadians) + y * cos(angleRadians);
    x = tempX;
    y = tempY;
}

void drawArrow2() {
    // Dimensiones del rectángulo
    float width_line = 1.6f;  // Ancho de la línea
    float height_line = 1.8f; // Altura de la línea (no aplicable en este caso)

    // Punto de referencia del rectángulo
    float rectangleX_line = 0.0f;  // Coordenada X del punto central de la línea
    float rectangleY_line = 0.0f;  // Coordenada Y del punto central de la línea
    float rectangleZ_line = 2.5f;  // Coordenada Z del punto central de la línea (aumentado)

    // Ángulos de rotación
    float rotationX_line = 180.0f;  // Ángulo de rotación en el eje X (en grados)
    float rotationY_line = 90.0f;   // Ángulo de rotación en el eje Y (en grados)
    float rotationZ_line = 270.0f;  // Ángulo de rotación en el eje Z (en grados)

    // Cálculo de la mitad del ancho
    float halfWidth_line = width_line / 3.0f;

    // Coordenadas de los extremos de la línea
    float x1_line = -halfWidth_line - 0.5f;  // Ajusta este valor para hacer la línea más larga hacia la izquierda
    float y1_line = 0.0f;
    float z1_line = 0.0f;

    float x2_line = halfWidth_line + 80.5f;  // Ajusta este valor para hacer la línea más larga hacia la derecha
    float y2_line = 0.0f;
    float z2_line = 0.0f;

    // Aplicar rotación a los puntos
    RotatePoint(y1_line, z1_line, rotationX_line);
    RotatePoint(y2_line, z2_line, rotationX_line);
    RotatePoint(x1_line, z1_line, rotationY_line);
    RotatePoint(x2_line, z2_line, rotationY_line);

    // Trasladar los puntos al punto de referencia del rectángulo
    x1_line += rectangleX_line;
    y1_line += rectangleY_line;
    z1_line += rectangleZ_line;

    x2_line += rectangleX_line;
    y2_line += rectangleY_line;
    z2_line += rectangleZ_line;

    // Establecer el grosor de la línea
    glLineWidth(3.0f);

    // Dibujar las líneas
    glBegin(GL_LINES);
    // Línea principal de la flecha
    glVertex3f(x1_line, y1_line, z1_line);
    glVertex3f(x2_line, y2_line, z2_line);
    // Línea izquierda de la V
    glVertex3f(0.0f, 0.0f, 1.5f); // Punto inicial
    glVertex3f(-0.1f, 0.0f, 1.8f); // Punto final

    // Línea derecha de la V
    glVertex3f(0.0f, 0.0f, 1.5f); // Punto inicial
    glVertex3f(0.1f, 0.0f, 1.8f); // Punto final
    glEnd();

    // Restaurar el grosor de línea al valor predeterminado
    glLineWidth(3.0f);
}

//2D
float rectangleX2D = 0.0f;
float rectangleY2D = 0.0f;
float rectangleZ2D = 0.7f;
float rotationX2D = 90.0f;
float rotationY2D = 90.0f;


//2D
void DrawRectangle2D() {
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;

    float x1 = -halfWidth;
    float y1 = -halfHeight;
    float z1 = 0.0f;

    float x2 = halfWidth;
    float y2 = -halfHeight;
    float z2 = 0.0f;

    float x3 = halfWidth;
    float y3 = halfHeight;
    float z3 = 0.0f;

    float x4 = -halfWidth;
    float y4 = halfHeight;
    float z4 = 0.0f;

    RotatePoint(y1, z1, rotationX2D);
    RotatePoint(y2, z2, rotationX2D);
    RotatePoint(y3, z3, rotationX2D);
    RotatePoint(y4, z4, rotationX2D);

    RotatePoint(x1, z1, rotationY2D);
    RotatePoint(x2, z2, rotationY2D);
    RotatePoint(x3, z3, rotationY2D);
    RotatePoint(x4, z4, rotationY2D);

    x1 += rectangleX2D;
    y1 += rectangleY2D;
    z1 += rectangleZ2D;

    x2 += rectangleX2D;
    y2 += rectangleY2D;
    z2 += rectangleZ2D;

    x3 += rectangleX2D;
    y3 += rectangleY2D;
    z3 += rectangleZ2D;

    x4 += rectangleX2D;
    y4 += rectangleY2D;
    z4 += rectangleZ2D;

    glLineWidth(lineBox);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();
}

//3D -----LINE 1
float rectangleX = 0.0f;
float rectangleY = 0.3378f;
float rectangleZ = 0.73f;
float rotationX = 90.0f;
float rotationY = 90.0f;
//--------LINE 2
float rotationX2 = 0.0f;
float rotationY2 = 90.0f;
float rectangleX2 = 0.3378f;
float rectangleY2 = 0.0f;
float rectangleZ2 = 0.73f;
//---------LINE 3 - L1
float rotationX3 = 90.0f;
float rotationY3 = 90.0f;
float rectangleX3 = 0.0f;
float rectangleY3 = -0.3378f;
float rectangleZ3 = 0.73f;
//---------LINE 4 - L2
float rotationX4 = 0.0f;
float rotationY4 = 90.0f;
float rectangleX4 = -0.3378f;
float rectangleY4 = 0.0f;
float rectangleZ4 = 0.73f;


void DrawRectangle() {
    float halfWidth = widthx / 1.38f;
    float halfHeight = height / 1.5f;

    float x1 = -halfWidth;
    float y1 = -halfHeight;
    float z1 = 0.0f;

    float x2 = halfWidth;
    float y2 = -halfHeight;
    float z2 = 0.0f;

    float x3 = halfWidth;
    float y3 = halfHeight;
    float z3 = 0.0f;

    float x4 = -halfWidth;
    float y4 = halfHeight;
    float z4 = 0.0f;

    RotatePoint(y1, z1, rotationX);
    RotatePoint(y2, z2, rotationX);
    RotatePoint(y3, z3, rotationX);
    RotatePoint(y4, z4, rotationX);

    RotatePoint(x1, z1, rotationY);
    RotatePoint(x2, z2, rotationY);
    RotatePoint(x3, z3, rotationY);
    RotatePoint(x4, z4, rotationY);

    x1 += rectangleX;
    y1 += rectangleY;
    z1 += rectangleZ;

    x2 += rectangleX;
    y2 += rectangleY;
    z2 += rectangleZ;

    x3 += rectangleX;
    y3 += rectangleY;
    z3 += rectangleZ;

    x4 += rectangleX;
    y4 += rectangleY;
    z4 += rectangleZ;

    glLineWidth(lineBox);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();
}
void DrawRectangle2() {
    float halfWidth = widthx / 1.38f;
    float halfHeight = height / 1.5f;

    float x1 = -halfWidth;
    float y1 = -halfHeight;
    float z1 = 0.0f;

    float x2 = halfWidth;
    float y2 = -halfHeight;
    float z2 = 0.0f;

    float x3 = halfWidth;
    float y3 = halfHeight;
    float z3 = 0.0f;

    float x4 = -halfWidth;
    float y4 = halfHeight;
    float z4 = 0.0f;

    RotatePoint(y1, z1, rotationX2);
    RotatePoint(y2, z2, rotationX2);
    RotatePoint(y3, z3, rotationX2);
    RotatePoint(y4, z4, rotationX2);

    RotatePoint(x1, z1, rotationY2);
    RotatePoint(x2, z2, rotationY2);
    RotatePoint(x3, z3, rotationY2);
    RotatePoint(x4, z4, rotationY2);

    x1 += rectangleX2;
    y1 += rectangleY2;
    z1 += rectangleZ2;

    x2 += rectangleX2;
    y2 += rectangleY2;
    z2 += rectangleZ2;

    x3 += rectangleX2;
    y3 += rectangleY2;
    z3 += rectangleZ2;

    x4 += rectangleX2;
    y4 += rectangleY2;
    z4 += rectangleZ2;

    glLineWidth(lineBox);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();
    glLineWidth(1.0f);
}
void DrawRectangle3() {
    float halfWidth = widthx / 1.38f;
    float halfHeight = height / 1.5f;

    float x1 = -halfWidth;
    float y1 = -halfHeight;
    float z1 = 0.0f;

    float x2 = halfWidth;
    float y2 = -halfHeight;
    float z2 = 0.0f;

    float x3 = halfWidth;
    float y3 = halfHeight;
    float z3 = 0.0f;

    float x4 = -halfWidth;
    float y4 = halfHeight;
    float z4 = 0.0f;

    RotatePoint(y1, z1, rotationX3);
    RotatePoint(y2, z2, rotationX3);
    RotatePoint(y3, z3, rotationX3);
    RotatePoint(y4, z4, rotationX3);

    RotatePoint(x1, z1, rotationY3);
    RotatePoint(x2, z2, rotationY3);
    RotatePoint(x3, z3, rotationY3);
    RotatePoint(x4, z4, rotationY3);

    x1 += rectangleX3;
    y1 += rectangleY3;
    z1 += rectangleZ3;

    x2 += rectangleX3;
    y2 += rectangleY3;
    z2 += rectangleZ3;

    x3 += rectangleX3;
    y3 += rectangleY3;
    z3 += rectangleZ3;

    x4 += rectangleX3;
    y4 += rectangleY3;
    z4 += rectangleZ3;

    glLineWidth(lineBox);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();

}
void DrawRectangle4() {
    float halfWidth = widthx / 1.38f;
    float halfHeight = height / 1.5f;

    float x1 = -halfWidth;
    float y1 = -halfHeight;
    float z1 = 0.0f;

    float x2 = halfWidth;
    float y2 = -halfHeight;
    float z2 = 0.0f;

    float x3 = halfWidth;
    float y3 = halfHeight;
    float z3 = 0.0f;

    float x4 = -halfWidth;
    float y4 = halfHeight;
    float z4 = 0.0f;

    RotatePoint(y1, z1, rotationX4);
    RotatePoint(y2, z2, rotationX4);
    RotatePoint(y3, z3, rotationX4);
    RotatePoint(y4, z4, rotationX4);

    RotatePoint(x1, z1, rotationY4);
    RotatePoint(x2, z2, rotationY4);
    RotatePoint(x3, z3, rotationY4);
    RotatePoint(x4, z4, rotationY4);

    x1 += rectangleX4;
    y1 += rectangleY4;
    z1 += rectangleZ4;

    x2 += rectangleX4;
    y2 += rectangleY4;
    z2 += rectangleZ4;

    x3 += rectangleX4;
    y3 += rectangleY4;
    z3 += rectangleZ4;

    x4 += rectangleX4;
    y4 += rectangleY4;
    z4 += rectangleZ4;

    glLineWidth(lineBox);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();
}


// Navidad
void DrawStarNavidad()
{
    const float PI = 3.14159265358979323846f;

    int numPuntas = 5;


    float escala = 0.5f;

    float radioExterno = (width_cabezaSS / 2.0) * escala;
    float radioInterno = radioExterno / 2.5;

    float angulo = 2 * PI / numPuntas;

    float x[10], y[10], z[10];


    for (int i = 0; i < numPuntas * 2; i++) {
        float currentAngulo = i * angulo / 2;
        float radio = (i % 2 == 0) ? radioExterno : radioInterno;

        x[i] = radio * cos(currentAngulo);
        y[i] = radio * sin(currentAngulo);
        z[i] = 0.0f;
    }


    for (int i = 0; i < numPuntas * 2; i++)
    {
        RotatePoint(y[i], z[i], rotationX_cabezaSS);
        RotatePoint(x[i], z[i], rotationY_cabezaSS);


        x[i] += rectangleX_cabezaSS;
        y[i] += rectangleY_cabezaSS;
        z[i] += rectangleZ_cabezaSS;
    }

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numPuntas * 2; i++) {
        glVertex3f(x[i], y[i], z[i]);
    }
    glEnd();
    glLineWidth(1.0f);
}
void Espiral()
{
    glBegin(GL_POINTS);
    float z = -lineHeight / 2.0f;
    float escala = 70.0f;
    for (float angle = 0.0f; angle <= (2.0f * GL_PI) * 3.0f; angle += 0.1f)
    {
        float x = escala * lineScale * sin(angle);
        float y = escala * lineScale * cos(angle);
        glLineWidth(5.0f);
        glVertex3f(x, y, z);
        glLineWidth(5.5f);
        z += lineHeight / (2.0f * 3.0f * GL_PI);
    }
    glEnd();
}

// corazon
void DrawCorazon()
{
    float scale = width_cabezaSS / 80.0;
    int numPoints = 50;
    std::vector<std::vector<float>> points(numPoints, std::vector<float>(3));

    for (int i = 0; i < numPoints; ++i)
    {
        float theta = (float)i / numPoints * 2 * M_PI;
        float x = scale * 16 * pow(sin(theta), 3);
        float y = scale * (13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta));

        points[i][0] = x;
        points[i][1] = y;
        points[i][2] = 0.0f;
    }

    for (int i = 0; i < numPoints; ++i)
    {
        float tempX = points[i][0];
        float tempY = points[i][1];

        points[i][0] = tempX * cos(-M_PI / 2) - tempY * sin(-M_PI / 2);
        points[i][1] = tempX * sin(-M_PI / 2) + tempY * cos(-M_PI / 2);

        RotatePoint(points[i][1], points[i][2], rotationX_corazonss);
        RotatePoint(points[i][0], points[i][2], rotationY_corazonss);

        points[i][0] += rectangleX_corazon;
        points[i][1] += rectangleY_corazon;
        points[i][2] += rectangleZ_cabezaSS;
    }

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numPoints; ++i)
    {
        glVertex3f(points[i][0], points[i][1], points[i][2]);
    }
    glEnd();
    glLineWidth(2.0f);
}

// Chams Pene
void Drawcirculo2()
{
    float halfWidth = width_cabezaSS / 7.0;
    float radius = halfWidth;
    int numSegments = 100;
    float angleStep = 2.0f * M_PI / numSegments;
    float offsetX = 0.2f;
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < numSegments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        float z = 0.0f;
        RotatePoint(y, z, rotationX_cabezaSS);
        RotatePoint(x, z, rotationY_cabezaSS);

        x += rectangleX_cabezaSS + offsetX;
        y += rectangleY_cabezaSS;
        z += rectangleZ_cabezaSS;

        glVertex3f(x, y, z);
    }

    glEnd();
    glLineWidth(4.0f);
}
void Drawcirculo3()
{
    float halfWidth = width_cabezaSS / 7.0;
    float radius = halfWidth;
    int numSegments = 100;
    float angleStep = 2.0f * M_PI / numSegments;
    float offsetX = -0.2f;
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < numSegments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        float z = 0.0f;
        RotatePoint(y, z, rotationX_cabezaSS);
        RotatePoint(x, z, rotationY_cabezaSS);
        x += rectangleX_cabezaSS + offsetX; z += rectangleZ_cabezaSS;
        glVertex3f(x, y, z);
    }
    glEnd();
    glLineWidth(4.0f);
}
void Drawretangulo()
{
    float halfWidth = width_cabezaSS / 2.6f;
    float halfHeight = height_cabezaSS / 11.0f;
    float x1 = -halfWidth;
    float y1 = -halfHeight;
    float z1 = 0.0f;
    float x2 = halfWidth;
    float y2 = -halfHeight;
    float z2 = 0.0f;
    float x3 = halfWidth;
    float y3 = halfHeight;
    float z3 = 0.0f;
    float x4 = -halfWidth;
    float y4 = halfHeight;
    float z4 = 0.0f;
    RotatePoint(y1, z1, rotationX_cabezaSS);
    RotatePoint(y2, z2, rotationX_cabezaSS);
    RotatePoint(y3, z3, rotationX_cabezaSS);
    RotatePoint(y4, z4, rotationX_cabezaSS);
    RotatePoint(x1, z1, rotationY_cabezaSS);
    RotatePoint(x2, z2, rotationY_cabezaSS);
    RotatePoint(x3, z3, rotationY_cabezaSS);
    RotatePoint(x4, z4, rotationY_cabezaSS);
    float zOffset = 0.4f;
    x1 += rectangleX_cabezaSS;
    y1 += rectangleY_cabezaSS;
    z1 += rectangleZ_cabezaSS + zOffset;
    x2 += rectangleX_cabezaSS;
    y2 += rectangleY_cabezaSS;
    z2 += rectangleZ_cabezaSS + zOffset;
    x3 += rectangleX_cabezaSS;
    y3 += rectangleY_cabezaSS;
    z3 += rectangleZ_cabezaSS + zOffset;
    x4 += rectangleX_cabezaSS;
    y4 += rectangleY_cabezaSS;
    z4 += rectangleZ_cabezaSS + zOffset;
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();
    glLineWidth(1.0f);
}


GLuint CreateTextureZ(int width, int height, int channels, GLenum wrapMode, const unsigned char* imageRaw)
{
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

    GLenum format = GL_RGB;

    if (channels == 4)
    {
        format = GL_RGBA;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageRaw);

    return textureID;
}

void DrawNebulaEffect(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    static float time = 0.0f;
    time += AnimacionSpped;
    int PixelW = 256;
    int PixelH = 256;
    int PixelChanel = 4;
    std::vector<unsigned char> NebulaIMG(PixelW * PixelH * PixelChanel);
    for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
    {
        int x = (i / PixelChanel) % PixelW;
        int y = (i / PixelChanel) / PixelW;
        float r = sin(x * 0.1f + time) * 127 + 128;
        float g = cos(y * 0.1f + time) * 127 + 128;
        float b = sin((x + y) * 0.1f + time) * 127 + 128;
        NebulaIMG[i] = static_cast<unsigned char>(std::clamp(r, 0.0f, 255.0f));
        NebulaIMG[i + 1] = static_cast<unsigned char>(std::clamp(g, 0.0f, 255.0f));
        NebulaIMG[i + 2] = static_cast<unsigned char>(std::clamp(b, 0.0f, 255.0f));
        NebulaIMG[i + 3] = 255;
    }
    GLuint NebulaTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, NebulaIMG.data());
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, NebulaTexture);
    glDepthRangef(1, 0.5);
    oglDrawElements(mode, count, type, indices);
    glDepthRangef(0.5, 1);
    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &NebulaTexture);
}

void DrawDynamicGalaxyEffect(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    int PixelW = 256;
    int PixelH = 256;
    int PixelChanel = 4;
    std::vector<unsigned char> ErrorChamsIMG(PixelW * PixelH * PixelChanel);
    for (int y = 0; y < PixelH; y++)
    {
        for (int x = 0; x < PixelW; x++)
        {
            int index = (y * PixelW + x) * PixelChanel;
            ErrorChamsIMG[index] = 10 + static_cast<unsigned char>(50 * (sin(x * 0.1) + 1));
            ErrorChamsIMG[index + 1] = 10 + static_cast<unsigned char>(50 * (cos(y * 0.1) + 1));
            ErrorChamsIMG[index + 2] = 50 + static_cast<unsigned char>(100 * (sin(x * 0.05) * cos(y * 0.05) + 1));
            ErrorChamsIMG[index + 3] = 255;
        }
    }
    GLuint ErrorChamsZ = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, ErrorChamsIMG.data());
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glDepthRangef(1, 0.5);
    oglDrawElements(mode, count, type, indices);
    glDepthRangef(0.5, 1);
    glDisable(GL_BLEND);
    glDeleteTextures(1, &ErrorChamsZ);
}

void DrawGoldenGalaxyEffect(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    static float time = 0.0f;
    time += AnimacionSpped; // Ahora es ajustable

    int PixelW = 256;
    int PixelH = 256;
    int PixelChanel = 4;
    std::vector<unsigned char> GoldenIMG(PixelW * PixelH * PixelChanel);

    for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
    {
        int x = (i / PixelChanel) % PixelW;
        int y = (i / PixelChanel) / PixelW;

        float distX = x - PixelW / 2.0f;
        float distY = y - PixelH / 2.0f;
        float radius = sqrt(distX * distX + distY * distY);
        float angle = atan2(distY, distX);

        float wave = sin(radius * 0.03f - time + angle * 2.0f) * 127 + 128;

        float r = wave * 1.0f;
        float g = wave * 0.8f;
        float b = wave * 0.2f;

        GoldenIMG[i] = static_cast<unsigned char>(std::clamp(r, 0.0f, 255.0f));
        GoldenIMG[i + 1] = static_cast<unsigned char>(std::clamp(g, 0.0f, 255.0f));
        GoldenIMG[i + 2] = static_cast<unsigned char>(std::clamp(b, 0.0f, 255.0f));
        GoldenIMG[i + 3] = 255;
    }

    GLuint GoldenTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, GoldenIMG.data());

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, GoldenTexture);

    glDepthRangef(1, 0.5);
    oglDrawElements(mode, count, type, indices);
    glDepthRangef(0.5, 1);

    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &GoldenTexture);
}

void DrawStarfieldEffect(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    static float time = 0.0f;
    time += AnimacionSpped; // Ahora es ajustable

    int PixelW = 256;
    int PixelH = 256;
    int PixelChanel = 4;
    std::vector<unsigned char> StarfieldIMG(PixelW * PixelH * PixelChanel);

    for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
    {
        int x = (i / PixelChanel) % PixelW;
        int y = (i / PixelChanel) / PixelW;

        float noise = sin(x * 0.1f + time) * cos(y * 0.1f + time);
        float brightness = noise * 127 + 128;

        if (rand() % 255 < brightness * 0.5f)
        {
            StarfieldIMG[i] = 255;
            StarfieldIMG[i + 1] = 255;
            StarfieldIMG[i + 2] = 200;
        }
        else
        {
            StarfieldIMG[i] = 0;
            StarfieldIMG[i + 1] = 0;
            StarfieldIMG[i + 2] = 50;
        }

        StarfieldIMG[i + 3] = 255;
    }

    GLuint StarfieldTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, StarfieldIMG.data());

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, StarfieldTexture);

    glDepthRangef(1, 0.5);
    oglDrawElements(mode, count, type, indices);
    glDepthRangef(0.5, 1);

    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &StarfieldTexture);
}

void DrawRainbowSwirlEffect(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    static float time = 0.0f;
    time += AnimacionSpped; // Usamos la variable ajustable

    int PixelW = 256;
    int PixelH = 256;
    int PixelChanel = 4;
    std::vector<unsigned char> SwirlIMG(PixelW * PixelH * PixelChanel);

    for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
    {
        int x = (i / PixelChanel) % PixelW;
        int y = (i / PixelChanel) / PixelW;

        float centerX = PixelW / 2.0f;
        float centerY = PixelH / 2.0f;
        float dx = x - centerX;
        float dy = y - centerY;
        float distance = sqrt(dx * dx + dy * dy);
        float angle = atan2(dy, dx);

        float swirl = sin(distance * 0.02f - time + angle * 4.0f) * 127 + 128;

        float r = sin(time + distance * 0.01f) * 127 + 128;
        float g = sin(time + distance * 0.02f + 2.0f) * 127 + 128;
        float b = sin(time + distance * 0.03f + 4.0f) * 127 + 128;

        SwirlIMG[i] = static_cast<unsigned char>(std::clamp(r, 0.0f, 255.0f));
        SwirlIMG[i + 1] = static_cast<unsigned char>(std::clamp(g, 0.0f, 255.0f));
        SwirlIMG[i + 2] = static_cast<unsigned char>(std::clamp(b, 0.0f, 255.0f));
        SwirlIMG[i + 3] = 255;
    }

    GLuint SwirlTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, SwirlIMG.data());

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, SwirlTexture);

    glDepthRangef(1, 0.5);
    oglDrawElements(mode, count, type, indices);
    glDepthRangef(0.5, 1);

    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &SwirlTexture);
}

void DrawVisible(GLenum mode, GLsizei count, GLenum type, const void* indices, const ChamsInfo& chamsDesc)
{
    if (Chams3D == true)
    {
        glDisable(GL_DEPTH_TEST);

        oglDrawElements(mode, count, type, indices);

        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }



    if (Solido == true)
    {
        glDepthRange(1, 0.5);
        glEnable(GL_BLEND);
        glColorMask(1, 1, 1, 1);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
        if (Rgb)
        {
            double time = getCurrentTime();
            float frequency = 0.5f;

            float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
            float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
            float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
            float alpha = 1.0f;

            glBlendColor(red, green, blue, alpha);
        }
        else
        {
            glBlendColor(blendColor1[0], blendColor1[1], blendColor1[2], blendColor1[3]);
        }
        GLTexture2DBindRestore guard(*(chamsDesc.pVisibleChamsTex));
        glPushMatrix();

        oglDrawElements(mode, count, type, indices);
        glPopMatrix();
        glDepthRange(0.5, 1);
        glDisable(GL_BLEND);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (Glow == true)
    {
        glColorMask(1, 1, 1, 1);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_CONSTANT_COLOR);
        glDepthRange(0.5, 1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(lineWidth);

        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_CONSTANT_COLOR);

        if (Rgb)
        {
            double time = getCurrentTime();
            float frequency = 0.5f;

            float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
            float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
            float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
            float alpha = 1.0f;

            glBlendColor(red, green, blue, alpha);
        }
        else
        {
            glBlendColor(blendColor1[0], blendColor1[1], blendColor1[2], blendColor1[3]);
        }

        glDepthRange(1, 0.8);
        oglDrawElements(mode, count, type, indices);
        glDepthRange(0.5, 1);

        glDisable(GL_BLEND);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        oglDrawElements(GL_TRIANGLES, count, type, indices);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        glBlendColor(0, 0, 0, 1);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }


    if (Wireframe)
    {
        glDepthRange(1, 0.5);
        glLineWidth(2);
        glEnable(GL_BLEND);
        glColorMask(1, 1, 1, 1);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);

        // Una sola vez: color dinámico o estático
        if (Rgb)
        {
            double time = getCurrentTime();
            float frequency = 0.5f;

            float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
            float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
            float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
            float alpha = 1.0f;

            glBlendColor(red, green, blue, alpha);
        }
        else
        {
            glBlendColor(blendColor1[0], blendColor1[1], blendColor1[2], blendColor1[3]);
        }

        glDrawElements(GL_TRIANGLES_ADJACENCY, count, type, indices);
        glDepthRangef(1, 0.5);
        glDrawElements(GL_LINES, count, type, indices);

        oglDrawElements(mode, count, type, indices);

        glDepthRange(0.5, 1);
        glDrawElements(GL_LINE_LOOP, count, type, indices);
        glDisable(GL_BLEND);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }


    if (Black == true)
    {
        glDepthRange(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRange(0.5, 1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(lineWidth);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_CONSTANT_COLOR);
        if (Rgb)
        {
            double time = getCurrentTime();
            float frequency = 0.5f;

            float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
            float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
            float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
            float alpha = 1.0f;

            glBlendColor(red, green, blue, alpha);
        }
        else
        {
            glBlendColor(blendColor1[0], blendColor1[1], blendColor1[2], blendColor1[3]);
        }

        oglDrawElements(mode, count, type, indices);

        glColorMask(1, 1, 1, 1);
        glDisable(GL_BLEND);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }


    if (Pick == true)
    {
        if (Rgb)
        {
            double time = getCurrentTime();
            float frequency = 0.5f;

            float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
            float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
            float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
            float alpha = 1.0f;

            glBlendColor(red, green, blue, alpha);
        }
        else
        {
            glBlendColor(blendColor1[0], blendColor1[1], blendColor1[2], blendColor1[3]);
        }

        glColorMask(1, 1, 1, 1);

        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_CONSTANT_COLOR);

        oglDrawElements(GL_TRIANGLES, count, type, indices);

        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);

        glBlendColor(blendColor1[0], blendColor1[1], blendColor1[2], blendColor1[3]);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (Glitch == true)
    {
        int PixelW = 256;
        int PixelH = 256;
        int PixelChanel = 4;
        std::vector<unsigned char> ErrorChamsIMG(PixelW * PixelH * PixelChanel);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
        {
            ErrorChamsIMG[i] = dis(gen);
            ErrorChamsIMG[i + 1] = dis(gen);
            ErrorChamsIMG[i + 2] = dis(gen);
            ErrorChamsIMG[i + 3] = 255;
        }
        ErrorChamsZ = CreateTexture(PixelW, PixelH, PixelChanel, GL_REPEAT, ErrorChamsIMG.data());

        glBindTexture(GL_TEXTURE_2D, ErrorChamsZ);

        if (Rgb)
        {
            glEnable(GL_BLEND);
            glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);

            double time = getCurrentTime();
            float frequency = 0.5f;

            float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
            float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
            float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
            float alpha = 1.0f;

            glBlendColor(red, green, blue, alpha);
        }

        glDepthRangef(1, 0.5f);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5f, 1);

        if (Rgb)
        {
            glDisable(GL_BLEND);
        }

        glDeleteTextures(1, &ErrorChamsZ);
        ErrorChamsZ = 0;
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }


    if (matrix == true)
    {
        static float time = 0.0f;
        time += 0.1f;
        int PixelW = 256;
        int PixelH = 256;
        int PixelChanel = 4;
        std::vector<unsigned char> ScanlineIMG(PixelW * PixelH * PixelChanel);

        for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
        {
            int x = (i / PixelChanel) % PixelW;
            int y = (i / PixelChanel) / PixelW;
            float scan = sin(y * 0.1f - time) * 127 + 128;
            ScanlineIMG[i] = 0;
            ScanlineIMG[i + 1] = static_cast<unsigned char>(scan);
            ScanlineIMG[i + 2] = 0;
            ScanlineIMG[i + 3] = 255;
        }
        GLuint ScanlineTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, ScanlineIMG.data());
        glDepthRangef(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5, 1);
        glDeleteTextures(1, &ScanlineTexture);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (whiteglich == true)
    {
        int PixelW = 256;
        int PixelH = 256;
        int PixelChanel = 4;
        std::vector<unsigned char> StrobeIMG(PixelW * PixelH * PixelChanel);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
        {
            if (dis(gen) == 0)
            {
                StrobeIMG[i] = 255;
                StrobeIMG[i + 1] = 255;
                StrobeIMG[i + 2] = 255;
            }
            else
            {
                StrobeIMG[i] = 0;
                StrobeIMG[i + 1] = 0;
                StrobeIMG[i + 2] = 0;
            }
            StrobeIMG[i + 3] = 255;
        }
        GLuint StrobeTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, StrobeIMG.data());
        glDepthRangef(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5, 1);
        glDeleteTextures(1, &StrobeTexture);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (lataglich == true)
    {
        int PixelW = 256;
        int PixelH = 256;
        int PixelChanel = 4;
        std::vector<unsigned char> WaveIMG(PixelW * PixelH * PixelChanel);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
        {
            int x = (i / PixelChanel) % PixelW;
            int y = (i / PixelChanel) / PixelW;
            float wave = sin(static_cast<float>(x + y) / 10.0f) * 50.0f;
            WaveIMG[i] = static_cast<unsigned char>(128 + wave);
            WaveIMG[i + 1] = static_cast<unsigned char>(128 + wave);
            WaveIMG[i + 2] = static_cast<unsigned char>(128 + wave);
            WaveIMG[i + 3] = 255;
        }
        GLuint WaveTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, WaveIMG.data());
        glDepthRangef(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5, 1);
        glDeleteTextures(1, &WaveTexture);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (txglich == true)
    {
        int PixelW = 256;
        int PixelH = 256;
        int PixelChanel = 4;
        std::vector<unsigned char> PixelArtIMG(PixelW * PixelH * PixelChanel);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 3);

        for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
        {
            int color = dis(gen);
            switch (color)
            {
            case 0:
                PixelArtIMG[i] = 255;
                PixelArtIMG[i + 1] = 0;
                PixelArtIMG[i + 2] = 0;
                break;
            case 1:
                PixelArtIMG[i] = 0;
                PixelArtIMG[i + 1] = 255;
                PixelArtIMG[i + 2] = 0;
                break;
            case 2:
                PixelArtIMG[i] = 0;
                PixelArtIMG[i + 1] = 0;
                PixelArtIMG[i + 2] = 255;
                break;
            case 3:
                PixelArtIMG[i] = 255;
                PixelArtIMG[i + 1] = 255;
                PixelArtIMG[i + 2] = 0;
                break;
            }
            PixelArtIMG[i + 3] = 255;
        }
        GLuint PixelArtTexture = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, PixelArtIMG.data());
        glDepthRangef(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5, 1);
        glDeleteTextures(1, &PixelArtTexture);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (galaxy == true)
    {
        DrawDynamicGalaxyEffect(mode, count, type, indices);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (goldengalaxy == true)
    {
        DrawGoldenGalaxyEffect(mode, count, type, indices);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (starfield == true)
    {
        DrawStarfieldEffect(mode, count, type, indices);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    //Feo
    if (rainbowswirl == true)
    {
        DrawRainbowSwirlEffect(mode, count, type, indices);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }

    if (GlowAnimado == true)
    {
        double time = getCurrentTime();
        float lineWidthM = lineWidth + 2.0f * std::abs(std::sin(2.0 * 3.14159265358979323846 * frequency * time));
        GLfloat originalDepthRange[2];
        glGetFloatv(GL_DEPTH_RANGE, originalDepthRange);
        glDepthRange(1, 0.5);


        oglDrawElements(mode, count, type, indices);

        glDepthRange(0.5, 1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(lineWidthM);
        glEnable(GL_BLEND);
        if (Rgb)
        {
            double time = getCurrentTime(); // Asegúrate que devuelve segundos en double

            float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
            float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
            float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
            float alpha = 1.0f;

            glBlendColor(red, green, blue, alpha);
        }
        else
        {
            glBlendColor(blendColor1[0], blendColor1[1], blendColor1[2], blendColor1[3]);
        }
        glBlendFunc(GL_ONE, GL_CONSTANT_COLOR);
        glDepthRange(1, 0.8);
        oglDrawElements(mode, count, type, indices);
        glDepthRange(originalDepthRange[0], originalDepthRange[1]);
        glDisable(GL_BLEND);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else
    {
        oglDrawElements(mode, count, type, indices);
    }
}

void DrawAlwaysTop(GLenum mode, GLsizei count, GLenum type, const void* indices, const ChamsInfo& chamsDesc)
{
    if (Chams3D == true)
    {
        glDepthRange(1, 0.5);
        glLineWidth(0);
        glEnable(GL_BLEND);
        glColorMask(1, 1, 1, 1);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
        glBlendColor(0, 0, 0, 1);
        glDrawElements(GL_TRIANGLES_ADJACENCY, count, type, indices);
        glBlendColor(GLfloat(0), GLfloat(0), GLfloat(0), 1);
        glDrawElements(GL_LINES, count, type, indices);

        oglDrawElements(mode, count, type, indices);

        glDrawElements(GL_LINE_LOOP, count, type, indices);
        glDisable(GL_BLEND);
        glDepthRange(0.5, 1);
    }
    else
    {

    }

    if (Black == true)
    {

        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ZERO, GL_ZERO);

        oglDrawElements(mode, count, type, indices);

        glEnable(GL_DEPTH_TEST);
    }
    else
    {

    }


    if (Spiderman == true)
    {
        int PixelW = 256;
        int PixelH = 256;
        int PixelChanel = 4;
        std::vector<unsigned char> ErrorChamsIMG(PixelW * PixelH * PixelChanel);
        int boxSize = 16;
        for (int y = 0; y < PixelH; ++y) {
            for (int x = 0; x < PixelW; ++x)
            {
                int colorChoice = (y < PixelH / 2) ? 1 : 2;
                bool isGridLine = (x % boxSize == 0) || (y % boxSize == 0);

                if (colorChoice == 1)
                {
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 0] = 255;
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 1] = 0;
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 2] = 0;
                }
                else if (colorChoice == 2)
                {
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 0] = 0;
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 1] = 0;
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 2] = 255;
                }
                if (isGridLine)
                {
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 0] = 169;
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 1] = 169;
                    ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 2] = 169;
                }
                ErrorChamsIMG[(y * PixelW + x) * PixelChanel + 3] = 255;
            }
        }
        GLuint ErrorChamsZ = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, ErrorChamsIMG.data());
        glDepthRangef(1, 0.5);
        oglDrawElements(GL_TRIANGLES, count, type, indices);
        glDepthRangef(0.5, 1);
        glDeleteTextures(1, &ErrorChamsZ);

    }
    else
    {

    }

    if (Creeper == true)
    {

        int PixelW = 100;  // Ancho  y
        int PixelH = 100;  // Alto   X
        int PixelChanel = 4;
        std::vector<unsigned char> ErrorChamsIMG(PixelW * PixelH * PixelChanel);
        int blockSize = 6;
        for (int y = 0; y < PixelH; ++y)
        {
            for (int x = 0; x < PixelW; ++x)
            {
                int i = (y * PixelW + x) * PixelChanel;
                bool isPinkBlock = ((x / blockSize) + (y / blockSize)) % 2 == 0;

                if (isPinkBlock)
                {
                    // Color Rosa
                    ErrorChamsIMG[i] = 255;
                    ErrorChamsIMG[i + 1] = 255;
                    ErrorChamsIMG[i + 2] = 255;
                }
                else
                {
                    // Color negro
                    ErrorChamsIMG[i] = 0;
                    ErrorChamsIMG[i + 1] = 0;
                    ErrorChamsIMG[i + 2] = 0;
                }
                ErrorChamsIMG[i + 3] = 255;
            }
        }
        GLuint ErrorChamsZ = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, ErrorChamsIMG.data());
        glDepthRangef(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5, 1);
        glDeleteTextures(1, &ErrorChamsZ);

    }
    else
    {

    }

    if (Disco == true)
    {

        int PixelW = 100;
        int PixelH = 100;
        int PixelChanel = 4;
        std::vector<unsigned char> ErrorChamsIMG(PixelW * PixelH * PixelChanel);


        int numParticles = 50;


        struct Particle
        {
            float x, y;
            float r, g, b, a;
            float dx, dy;
        };

        std::vector<Particle> particles(numParticles);


        for (int i = 0; i < numParticles; ++i)
        {
            particles[i].x = rand() % PixelW;
            particles[i].y = rand() % PixelH;
            particles[i].r = (rand() % 256) / 255.0f;
            particles[i].g = (rand() % 256) / 255.0f;
            particles[i].b = (rand() % 256) / 255.0f;
            particles[i].a = 255;
            particles[i].dx = (rand() % 3 - 1) * 0.5f;
            particles[i].dy = (rand() % 3 - 1) * 0.5f;
        }


        for (int y = 0; y < PixelH; ++y)
        {
            for (int x = 0; x < PixelW; ++x)
            {
                int i = (y * PixelW + x) * PixelChanel;


                for (int p = 0; p < numParticles; ++p)
                {
                    Particle& part = particles[p];


                    if (x >= part.x && x < part.x + 5 && y >= part.y && y < part.y + 5)
                    {
                        ErrorChamsIMG[i] = (unsigned char)(part.r * 255);
                        ErrorChamsIMG[i + 1] = (unsigned char)(part.g * 255);
                        ErrorChamsIMG[i + 2] = (unsigned char)(part.b * 255);
                        ErrorChamsIMG[i + 3] = (unsigned char)(part.a);
                    }
                }
            }
        }


        GLuint ErrorChamsZ = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, ErrorChamsIMG.data());


        for (int p = 0; p < numParticles; ++p)
        {
            Particle& part = particles[p];
            part.x += part.dx;
            part.y += part.dy;


            if (part.x <= 0 || part.x >= PixelW - 5) part.dx *= -1;
            if (part.y <= 0 || part.y >= PixelH - 5) part.dy *= -1;
        }

        glDepthRangef(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5, 1);

        glDeleteTextures(1, &ErrorChamsZ);


    }
    else
    {

    }

    if (Lava == true)
    {

        int PixelW = 256;
        int PixelH = 256;
        int PixelChanel = 4;
        std::vector<unsigned char> ErrorChamsIMG(PixelW * PixelH * PixelChanel);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);

        for (int i = 0; i < PixelW * PixelH * PixelChanel; i += PixelChanel)
        {
            int red = dis(gen);
            int green = dis(gen) / 4;
            int blue = dis(gen) / 4;
            if (dis(gen) > 180)
            {
                ErrorChamsIMG[i] = red;
                ErrorChamsIMG[i + 1] = dis(gen) / 2 + 50;
                ErrorChamsIMG[i + 2] = dis(gen) / 4;
            }
            else
            {
                ErrorChamsIMG[i] = red;
                ErrorChamsIMG[i + 1] = green;
                ErrorChamsIMG[i + 2] = blue;
            }


            ErrorChamsIMG[i + 3] = 255;
        }

        GLuint ErrorChamsZ = CreateTextureZ(PixelW, PixelH, PixelChanel, GL_REPEAT, ErrorChamsIMG.data());

        glDepthRangef(1, 0.5);
        oglDrawElements(mode, count, type, indices);
        glDepthRangef(0.5, 1);

        glDeleteTextures(1, &ErrorChamsZ);



    }
    else
    {

    }
}

bool ChamsContextInitialize()
{
    {
        GLTexture2DBindRestore guard(0);
        ColorToTexture({ 0xFF, 0xFF, 0xFF, 0xFF }, &gTexCyan);
        ColorToTexture({ 0xFF, 0xFF, 0xFF, 0xFF }, &gTexYellow);
    }
    return true;
}

void ChamsContextShutdown(bool bUnhookElems = true)
{
    if (bUnhookElems) MH_DisableHook(glDrawElements);

    gbRunning = false;
}

void WukongColoR(GLenum mode, GLsizei count, GLenum type, const void* indices)
{

    glDepthRangef(1, 0.5);
    //
    oglDrawElements(mode, count, type, indices);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(2.f);
    if (Rgb)
    {
        double time = getCurrentTime();
        float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * 0.5f * time));
        float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * 0.5f * time + 2.0 * M_PI / 3.0));
        float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * 0.5f * time + 4.0 * M_PI / 3.0));
        ColorToTexture(ImVec4(red * 255, green * 255, blue * 255, 255), &Color);
    }
    else
    {
        ColorToTexture(ImVec4(blendColor2[0] * 255, blendColor2[1] * 255, blendColor2[2] * 255, 255), &Color);
    }
    oglDrawElements(mode, count, type, indices);
    glDeleteTextures(1, &Color);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDepthRangef(0.5, 1);
}

void colorfenix()
{
    glEnable(GL_BLEND);
    if (Rgb)
    {
        double time = getCurrentTime();
        float frequency = 0.5f;

        float red = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time));
        float green = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 2.0 * M_PI / 3.0));
        float blue = 0.5f * (1.0f + std::sin(2.0 * M_PI * frequency * time + 4.0 * M_PI / 3.0));
        float alpha = 1.0f;

        glBlendColor(red, green, blue, alpha);
    }
    else
    {
        glBlendColor(blendColor2[0], blendColor2[1], blendColor2[2], blendColor2[3]);
    }
    glBlendFunc(GL_ONE, GL_CONSTANT_COLOR);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFuncSeparate(GL_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE, GL_ZERO);
}

void WINAPI hglDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    printf("Draw call: mode=%d, count=%d\n", mode, count);

    static bool bGlewInitialized = false;

    if (!bGlewInitialized)
    {

        if (glewInit() != GLEW_OK)
        {
            printf("Failed Initializing Glew\n");

            glDrawElements(mode, count, type, indices);

            ChamsContextShutdown();

            return;
        }

        bGlewInitialized = true;
    }

    //Oreon
    if (CurrentShaderHasUniform("_UVXX") != NULL)
    {
        if (Oreon) {

            glDisable(GL_DEPTH_TEST);
            oglDrawElements(mode, count, type, indices);
            glEnable(GL_DEPTH_TEST);
        }
    }

    //Legendario
    if (CurrentShaderHasUniform("_AlphaMask") != NULL) {


        if (ChamsLegendario) {

            glDisable(GL_DEPTH_TEST);
            oglDrawElements(mode, count, type, indices);
            glEnable(GL_DEPTH_TEST);
        }

    }

    //Wukong
    if (CurrentShaderHasUniform("_Cutoff") && (count == 474 || count == 1146 || count == 174 || count == 1344)) {

        if (ChamsWokung) {

            WukongColoR(mode, count, type, indices);
        }
    }

    if (WukongSolara)
    {
        if (CurrentShaderHasUniform("_Cutoff") == NULL) {}
        else
        {
            if ((mode != GL_TRIANGLES || (count > 28 && count < 398)) ||
                (mode != GL_TRIANGLES || (count > 886 && count < 1000)))
            {
                glDepthRangef(1, 0.5);
                oglDrawElements(mode, count, type, indices);
                glDepthRangef(0.5, 1);
            }
        }
    }

    if (ChamsWokungOld)
    {
        if (CurrentShaderHasUniform("_Cutoff") == NULL) {}
        else
        {
            if (mode != GL_TRIANGLES || count < 1354)
            {
                if (mode != GL_TRIANGLES || count > 324)
                {
                    glDepthRange(1, 0.5);
                    colorfenix();
                    oglDrawElements(mode, count, type, indices);
                    glDepthRange(0.5, 1);
                }
            }
        }
    }

    if (Santino3D)
    {
        if (CurrentShaderHasUniform("_AlphaMask") == NULL) {}
        else
        {
            if ((mode != GL_TRIANGLES || (count > 1426 && count < 3531)) ||
                (mode != GL_TRIANGLES || (count > 595 && count < 1022)))
            {
                glDepthRangef(1, 0.5);
                oglDrawElements(mode, count, type, indices);
                glDepthRangef(0.5, 1);
            }
        }
    }

    if (Araña3D)
    {
        if (CurrentShaderHasUniform("_AlphaMask") == NULL) {}
        else
        {
            if ((mode != GL_TRIANGLES || (count > 4255 && count < 4256)) ||
                (mode != GL_TRIANGLES || (count > 4758 && count < 6000)))
            {
                glDepthRangef(1, 0.5);
                oglDrawElements(mode, count, type, indices);
                glDepthRangef(0.5, 1);
            }
        }
    }


    //MODE MAP
    GLint currProgram;
    glGetIntegerv(GL_CURRENT_PROGRAM, &currProgram);
    GLuint bloomMaskTextureID = 230;

    if (MapaBendi == true)
    {
        GLint lightmapHDRLocation = glGetUniformLocation(currProgram, "unity_Lightmap_HDR");

        if (lightmapHDRLocation != -1)
        {
            float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
            glUniform4fv(lightmapHDRLocation, 1, color);
            GLint bloomMaskLocation = glGetUniformLocation(currProgram, "bloomMask");
            GLint bloomIntensityFactorLocation = glGetUniformLocation(currProgram, "bloomIntensityFactor");
            GLint bloomColorLocation = glGetUniformLocation(currProgram, "bloomColor");
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, bloomMaskTextureID);
            glUniform1i(bloomMaskLocation, 1);
            glUniform1f(bloomIntensityFactorLocation, 120.75f);
            glUniform4f(bloomColorLocation, 1.0f, 1.0f, 0.8f, 1.0f);
            oglDrawElements(mode, count, type, indices);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
    }

    if (HdRmap == true)
    {
        if (CurrentShaderHasUniform("unity_Lightmap_HDR") == NULL) {}
        else
        {
            GLint loc = glGetUniformLocation(currProgram, "unity_Lightmap_HDR");
            float colorCeleste[4] = { 0.6f, 0.9f, 1.0f, 1.0f };
            glUniform4fv(loc, 1, colorCeleste);
            float ambientLight[4] = { 0.3f, 0.3f, 0.3f, 1.0f };
            glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
            float diffuseLight[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
            glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
            float specularColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
            float shininess = 500.0f;
            glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess);
            GLint locVerde = glGetUniformLocation(currProgram, "unity_Lightmap_HDR");
            float colorVerde[4] = { 0.1f, 0.9f, 0.2f, 1.0f };
            glUniform4fv(locVerde, 1, colorVerde);
            GLint locRojo = glGetUniformLocation(currProgram, "unity_Lightmap_HDR");
            float colorRojo[4] = { 1.0f, 0.2f, 0.2f, 1.0f };
            glUniform4fv(locRojo, 1, colorRojo);
            GLint locAmarillo = glGetUniformLocation(currProgram, "unity_Lightmap_HDR");
            float colorAmarillo[4] = { 1.0f, 1.0f, 0.2f, 1.0f };
            glUniform4fv(locAmarillo, 1, colorAmarillo);
            oglDrawElements(mode, count, type, indices);
        }
    }

    if (MapaOcuro == true)
    {
        if (CurrentShaderHasUniform("unity_Lightmap_HDR") == NULL) {
        }
        else {
            GLint loc = glGetUniformLocation(currProgram, "unity_Lightmap_HDR");
            float colorVerde[4] = { 0.1f, 0.9f, 0.2f, 1.0f };
            glUniform4fv(loc, 1, colorVerde);

            float ambientLight[4] = { 0.0f, 0.5f, 0.0f, 1.0f };
            glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);

            float diffuseLight[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
            glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
        }
    }

    if (mode != GL_TRIANGLES || count < countThreshold)
    {
        return oglDrawElements(mode, count, type, indices);
    }

    const std::pair<const std::string, ChamsInfo>* pChamDescKv = nullptr;

    for (const auto& chamDescKv : gChamsDescs)
    {
        if (!CurrentShaderHasUniform(chamDescKv.first)) continue;

        pChamDescKv = &chamDescKv;
        break;
    }

    if (pChamDescKv == nullptr)
    {
        return oglDrawElements(mode, count, type, indices);
    }

    static bool gbChamsCtxInitialized = false;

    if (!gbChamsCtxInitialized && !(gbChamsCtxInitialized = ChamsContextInitialize()))
    {
        oglDrawElements(mode, count, type, indices);

        MH_DisableHook(glDrawElements);
        gbRunning = false;

        return;
    }

    DrawAlwaysTop(mode, count, type, indices, pChamDescKv->second);
    DrawVisible(mode, count, type, indices, pChamDescKv->second);
}

HWND CreateDummyWindow()
{
    WNDCLASSA wc = { 0 };
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = DefWindowProcA;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "DummyGLWindow";

    RegisterClassA(&wc);
    HWND hwnd = CreateWindowA("DummyGLWindow", "", WS_OVERLAPPEDWINDOW,
        0, 0, 1, 1, NULL, NULL, wc.hInstance, NULL);

    return hwnd;
}

void* LoadGLFunc(const char* name)
{
    void* ptr = (void*)wglGetProcAddress(name);
    if (!ptr)
    {
        HMODULE gl = GetModuleHandleA("opengl32.dll");
        if (gl)
            ptr = (void*)GetProcAddress(gl, name);
    }
    return ptr;
}

// Estructura para definir hooks OpenGL
struct GLHookEntry
{
    const char* name;
    void* hookFunc;
    void** originalFunc;
    bool        isHooked;
};


// Prototipos de funciones que querés hookear
void (WINAPI* oglUseProgram)(GLuint) = nullptr;

void (WINAPI* oglBindTexture)(GLenum, GLuint) = nullptr;

void WINAPI hglUseProgram(GLuint program) {
    oglUseProgram(program);
}

void WINAPI hglBindTexture(GLenum target, GLuint texture) {
    oglBindTexture(target, texture);
}

// Tabla de hooks que querés aplicar
std::vector<GLHookEntry> gGLHooks =
{
    {"glDrawElements", (void*)hglDrawElements, (void**)&oglDrawElements, false},
    {"glUseProgram",   (void*)hglUseProgram,   (void**)&oglUseProgram,   false},
    {"glBindTexture",  (void*)hglBindTexture,  (void**)&oglBindTexture,  false},
};

bool Run()
{
    if (MH_Initialize() != MH_OK)
        return false;

    MH_CreateHook((LPVOID)glDrawElements, hglDrawElements, (LPVOID*)&oglDrawElements);
    MH_EnableHook(glDrawElements);

    while (gbRunning)
    {
        Sleep(1200);
    }

    MH_Uninitialize();

    return true;
}

void WINAPI Fenix_GLS(HMODULE hMod)
{
    bool result = 1;

    result = Run();

    FreeLibraryAndExitThread(hMod, result);
}
