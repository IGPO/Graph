//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Graph.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	 Edit1->Text = "30";
     Edit2->Text = "-4";
	 Edit3->Text = "4";
	 Edit4->Text = "-2";
     Edit5->Text = "2";
	 Edit1->SetFocus(); // установить фокус ввода в Edit1
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Form2->n = StrToInt(Edit1->Text);
     Form2->x1 = StrToFloat(Edit2->Text);
     Form2->x2 = StrToFloat(Edit3->Text);
     Form2->y1 = StrToFloat(Edit4->Text);
     Form2->y2 = StrToFloat(Edit5->Text);
     Form2->ShowModal();
}
//---------------------------------------------------------------------------
