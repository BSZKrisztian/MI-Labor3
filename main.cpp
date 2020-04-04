#include<iostream>
#include<string>
#include <iomanip>
#include<cmath>
using namespace std;


void SetParameters(int&, bool&);
void Tabla(int, char[]);
void GepKore(char[], int&, int);
void JatekosKore(char[], int&, int);
void TablaKiirat(char[], int);


void SetParameters(int& pieces, bool& COMPUTER_TURN)
{
	char answer;
	cout << "NIM j�t�k " << endl << endl;
	do
	{

		cout << "H�ny sz�mmal szeretn� j�tszani a NIM j�t�kot?" << endl;
		cin >> pieces;
		if (pieces < 5 || 20 < pieces)

			cout << "Csak 5 �s 20 k�z�tt lehet v�lasztani. " << endl << endl;

	} while (pieces < 5 || 20 < pieces);

	cout << "Szeretne kezdeni? (I/N)";
	cin >> answer;
	if (answer == 'i' || answer == 'I')
	{
		cout << "Kezdjen. " << endl;
		COMPUTER_TURN = false;
	}


	else
	{
		COMPUTER_TURN = true;
		cout << "Rendben, kezdek �n." << endl;
	}


}
void Tabla(int pieces, char GamePieces[])
{
	for (int i = 0; i < pieces; i++)

		GamePieces[i] = 'o';

}


void GepKore(char GamePieces[], int& piecesChoice, int pieces)
{
	int computerMove = piecesChoice + 1;
	cout << endl << endl << "Most �n k�vetkezek. " << endl;
	if (computerMove <= pieces && GamePieces[computerMove] != '_')
		GamePieces[computerMove] = '_';
}


void JatekosKore(char GamePieces[], int& piecesSel, int size)
{
	char answer, count = 0;

	cout << "Maga j�n. Melyik sz�mot v�lassza?";
	do {
		cin >> piecesSel;
		count = count++;
		if (piecesSel > size || GamePieces[piecesSel] == '_')
		{
			do
			{
				cout << "Helytelen l�p�s. \n";
				cout << "K�rem m�s sz�mot �rjon. \n";
				cin >> piecesSel;


			} while (piecesSel > size || GamePieces[piecesSel] == '_');
		}
		GamePieces[piecesSel] = '_';
		cout << "M�gegyet ki akar venni? \n";
		cin >> answer;
		if (answer == 'i'&&count < 3 || answer == 'I'&&count < 3)
			cout << "Melyik sz�mot szeretn�: \n";
		if (count > 2)
			cout << "El�rte a max megengedett sz�mot. Maxim�lisan 3-at v�laszthat egy k�r alatt. " << endl;
	} while (answer == 'i'&&count < 3 || answer == 'I'&&count < 3);
}



void TablaKiirat(char GamePieces[], int pieces)
{
	cout << endl << endl << "Jelenlegi �ll�s: " << endl << endl;

	for (int i = 0; i < pieces; i++)
		cout << left << setw(3) << i;
	cout << endl;
	for (int i = 0; i < pieces; i++)
		cout << setw(2) << GamePieces[i] << ' ';
	cout << endl;


}


int main()
{
	int pieces, size, piecesSlection = 0;
	char GamePieces[20];
	bool  COMPUTER_TURN = false;


	SetParameters(pieces, COMPUTER_TURN);
	size = pieces - 1;
	Tabla(pieces, GamePieces);

	do
	{
		if (COMPUTER_TURN == true)
		{
			GepKore(GamePieces, piecesSlection, pieces);
			TablaKiirat(GamePieces, pieces);
			COMPUTER_TURN = false;
		}
		else
		{
			JatekosKore(GamePieces, piecesSlection, size);
			TablaKiirat(GamePieces, pieces);
			COMPUTER_TURN = true;
		}
	} while (GamePieces[0] != '_');

	return 0;
}
