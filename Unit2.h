//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TImage *Image1;
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	int xx1, xx2, yy1, yy2;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
    float x1, x2, y1, y2;
	int n;
	int ZoomX(float x);
	int ZoomY(float y);
	float func(float x);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
