//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int TForm2::ZoomX(float x)
{
     int ret;
     ret = xx1 + (int)((x-x1)*(xx2-xx1)/(x2-x1));
     return ret;
}

int TForm2::ZoomY(float y)
{
     int ret;
     ret = yy2 + (int)((y-y1)*(yy1-yy2)/(y2-y1));
     return ret;
}

float TForm2::func(float x)
{
     float ret;
     ret = sin(x); // функция, для которой строится график
     return ret;
}
void __fastcall TForm2::FormActivate(TObject *Sender)
{
TCanvas * canv; // дополнительная переменная
     int tx, ty;
     int i;
     float x, y, h;

     canv = Image1->Canvas;

     // 1. Установка границ экранных координат
     xx1 = 0;
     yy1 = 0;
     xx2 = Image1->Width;
     yy2 = Image1->Height;

     // 2. Рисование графика
     canv->Pen->Color = clBlue;
     canv->Brush->Color = clWhite;
     canv->Rectangle(0, 0, Image1->Width, Image1->Height);

     // 2.1. Рисование осей координат
     canv->Pen->Color = clBlack;
     // 2.2. Взять экранную точку начала координат X
     tx = ZoomX(0);
     ty = ZoomY(y1);
     canv->MoveTo(tx,ty);

     // провести линию оси координат X
     tx = ZoomX(0);
     ty = ZoomY(y2);
     canv->LineTo(tx,ty);

     // 2.3. Точка начала координат Y
     canv->Pen->Color = clBlack;
     tx = ZoomX(x1);
     ty = ZoomY(0);
     canv->MoveTo(tx,ty);

     // нарисовать ось Y
     tx = ZoomX(x2);
     ty = ZoomY(0);
     canv->LineTo(tx,ty);

     // 3. Рисование графика функции
     canv->Pen->Color = clRed; // цвет
     canv->Pen->Width = 2; // толщина линии

     // координаты первой точки
     x = x1;
     y = func(x);
     h = (x2-x1)/n;
     tx = ZoomX(x);
     ty = ZoomY(y);
     canv->MoveTo(tx,ty);

     // цикл перебора точек и рисование соединительных линий
     for (i = 0; i < n; i++)
     {
         x = x + h;
         y = func(x);
         tx = ZoomX(x);
         ty = ZoomY(y);
         canv->LineTo(tx,ty);
     }
}
//---------------------------------------------------------------------------
