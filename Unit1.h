// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>

// ---------------------------------------------------------------------------
class TSzachy : public TForm {
__published: // IDE-managed Components
	TStringGrid *szachownica;
	TButton *Zamknij;
	TLabel *Teraz_gra;
	TLabel *Wybrany_pionek;
	TLabel *gracz;
	TLabel *pionek;
	TButton *zmien_pionka;

	void __fastcall ustawParametry(TObject *Sender);
	void __fastcall rysowaniePol(TObject *Sender, int ACol, int ARow,
		TRect &Rect, TGridDrawState State);
	void __fastcall naKlikniecie(TObject *Sender, int ACol, int ARow,
		bool &CanSelect);

	void __fastcall startoweUstawienieN(TStringGrid& tabelka);
	void __fastcall ZamknijClick(TObject *Sender);
	void __fastcall kontrola_rundy(int runda_);
	void __fastcall zmien_pionkaClick(TObject *Sender);

private: // User declarations
	struct pionki {
		int col, row, gracz;
		UnicodeString nazwa;
	};

	pionki tab[8][8];
	// tablica z rozmieszczeniem oraz oznaczeniem czyje s¹ pionkoi na planszy

	int lastCol = 4;
	int lastRow = 4;
	int runda = 1;
	bool czyZatwierdzono = false;

public: // User declarations
	__fastcall TSzachy(TComponent* Owner);
	void __fastcall ruch(pionki tab[8][8], int ACol, int ARow, int lastCol,
		int lastRow, TStringGrid &szachownica);
	void __fastcall decyzja_ruch(pionki tab[8][8], int ACol, int ARow,
		int lastCol, int lastRow, TStringGrid &szachownica);

};

// ---------------------------------------------------------------------------
extern PACKAGE TSzachy *Szachy;
// ---------------------------------------------------------------------------
#endif
