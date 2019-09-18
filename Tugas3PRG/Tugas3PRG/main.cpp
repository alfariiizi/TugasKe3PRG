// Moh Rizal Alfarizi
// Fisika
// 19/445591/PA/19415

#include <iostream>
#include <algorithm>	// sorting function
#include <vector>		// dinamic memory

using namespace std;

void notRepeat(vector<int>& Data, int& i, int& nData);
bool IsRepeat(int& DataVal, vector<int>& b, int& nData, int& i);

int main()
{
	int nData = 0;	// inisialisasi banyak data

	cout << "Data yang di-inginkan : "; cin >> nData; cin.get();	// input banyaknya data
	nData = abs(nData);	// tetap mengambil nilai positif jika input n data negatif

	vector<int> Data(nData, 0);	// vector dengan nama "Data", mengalokasikan memori sebanyak "nData", serta menginialisasikan nilai awal seluruh anggota ke 0

	for (int i = 0; i < nData; i++)
	{
		notRepeat(Data, i, nData);
		cout << Data[i] << " ";
		if ((i + 1) % 10 == 0 && i + 1 != nData)
		{
			cout << endl << endl;
		}
	}

	sort(Data.begin(), Data.end());

	cout << endl << endl << endl << endl;
	cout << "Diurutkan : " << endl;
	for (int i = 0; i < nData; i++)
	{
		cout << Data[i] << " ";
		if ((i + 1) % 10 == 0 && i + 1 != nData)
		{
			cout << endl << endl;
		}
	}

	Data.clear();
	cin.get();
	return 0;
}

void notRepeat(vector<int>& Data, int& i,int& nData)
{
	do
	{
		Data[i] = rand() % nData + 1;
	} while ( IsRepeat(Data[i], Data, nData, i) );

}

bool IsRepeat(int& DataVal, vector<int>& b, int& nData, int& i)
{
	bool equivalent = false;
	for (int j = 0; j < nData; j++)
	{
		if (j != i && DataVal == b[j])
		{
			equivalent = true;
			break;
		}
	}

	return equivalent;
}