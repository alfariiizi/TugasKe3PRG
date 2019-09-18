// Moh Rizal Alfarizi
// Fisika
// 19/445591/PA/19415

#include <iostream>
#include <algorithm>	// sorting function
#include <vector>		// dinamic memory

using namespace std;

void InitData(vector<int>& Data, int& i, int& nData);
bool HasTaken(int& DataVal, vector<int>& b, int& nData, int& i);

int main()
{
	int nData = 0;	// inisialisasi banyak data

	cout << "Data yang di-inginkan : "; cin >> nData; cin.get();	// input banyaknya data
	nData = abs(nData);	// tetap mengambil nilai positif jika input n data negatif

	vector<int> Data(nData, 0);	// vector dengan nama "Data", mengalokasikan memori sebanyak "nData", serta menginialisasikan nilai awal seluruh anggota ke 0

	for (int i = 0; i < nData; i++)
	{
		InitData(Data, i, nData);	// fungsi untuk menginialisasikan data, dan diantara data tersebut tidak ada yang memiliki nilai yang sama
		cout << Data[i] << " ";		// menampilkan data yang sudah mendapatkan nilai
		if ((i + 1) % 10 == 0 && i + 1 != nData)	// membuat double new line dalam output, jika data yang dioutputkan sudah sampai 10
		{
			cout << endl << endl;
		}
	}

	sort(Data.begin(), Data.end());		// men-sorting seluruh data

	cout << endl << endl << endl << endl;

	cout << "Diurutkan : " << endl;
	for (int i = 0; i < nData; i++)		// menampilkan semua data yang sudah diurutkan
	{
		cout << Data[i] << " ";
		if ((i + 1) % 10 == 0 && i + 1 != nData)	// membuat double new line dalam output, jika data yang dioutputkan sudah sampai 10
		{
			cout << endl << endl;
		}
	}

	Data.clear();	// menghapus memori yang sudah dialokasikan, karena sudah tidak terpakai
	cin.get();
	return 0;
}

void InitData(vector<int>& Data, int& i,int& nData)	// menginialisasikan Data ke suatu nilai, tetapi tdk ada yg menyamai nilai tersebut
{
	do
	{
		Data[i] = rand() % nData + 1;	// menginisialisasikan data ke suatu nilai dari rentang 1 sampai nData
	} while ( HasTaken(Data[i], Data, nData, i) );	// jika nilai dalam data tersebut pernah dimiliki oleh data lain, maka akan looping keatas lagi
													// jika nilai dalam data tersebut belum pernah dimiliki oleh data lain, maka akan stop looping
}

bool HasTaken(int& DataVal, vector<int>& b, int& nData, int& i)	// mengecek apakah nilai dalam data tersebut pernah dimiliki oleh data lain
{
	bool equivalent = false;
	for (int j = 0; j < nData; j++)
	{
		if (j != i && DataVal == b[j])	// jika nilai dalam data tersebut pernah dimiliki oleh data lain, maka equivalent = true
		{
			equivalent = true;
			break;	// agar tidak usah meneruskan looping jika memang sudah ada 1 data yang mempunyai nilai sama
		}
	}

	return equivalent;
}