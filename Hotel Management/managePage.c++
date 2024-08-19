#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "./strData.h"
#include "./kotaLiburan/denpasar.h"
#include "./kotaLiburan/yogyakarta.h"
using namespace std;

// Struct 2nd
struct userData
{
  string nama, user, pass;
};

// Main code
int main()
{

  strData kota;
  string user, pass, nama;

  string arrKota[] = {"Yogyakarta", "Denpasar"};
  kota.jumlah = sizeof(arrKota) / sizeof(arrKota[0]);
  cout << "================================================================" << endl;
  cout << "\t\t\tLuxury Hotel" << endl;
  cout << "================================================================" << endl;
  cout << "\t\t\tLogin Form" << endl;
  cout << "================================================================" << endl;
  cout << "\t\tSilahkan buat akun terlebih dahulu" << endl;
  cout << endl;
  while (true)
  {
    cout << "Masukkan nama anda\t: ";
    cin >> nama;
    cout << "Masukkan akun anda\t: ";
    cin >> user;
    cout << "Masukkan password anda\t: ";
    cin >> pass;
    ofstream fileAkun("akunData.txt", ios::app);
    if (!fileAkun.is_open())
    {
      cerr << "File tidak dapat terbuka!!" << endl;
    }
    fileAkun << "================================================================" << endl;
    fileAkun << "Nama\t\t\t\t: " << nama << "\n";
    fileAkun << "User\t\t\t\t: " << user << "\n";
    fileAkun << "Password\t\t: " << pass << "\n";
    fileAkun << "================================================================" << endl;
    fileAkun.close();
    cout << "\033[2J\033[H";

    string file_simpan = "akunData.txt";
    ifstream akunOutput(file_simpan);
    if (!akunOutput.is_open())
    {
      cout << "Tidak dapat terbuka!" << endl;
      return 1;
    }
    userData accountUser;
    bool loginAcc = true;

    string lineData;
    while (getline(akunOutput, lineData))
    {
      stringstream ss(lineData);
      vector<string> dataAkun;
      string token;

      while (getline(ss, token, ':'))
      {
        dataAkun.push_back(token);
      }

      if (dataAkun.size() >= 2)
      {
        string label = dataAkun[0];
        string value = dataAkun[1];

        if (label.find("User") != string::npos)
        {
          accountUser.user = value;
        }
        else if (label.find("Password") != string::npos)
        {
          accountUser.pass = value;
        }
      }
    }
    akunOutput.close();
    if (accountUser.user == user && accountUser.pass == pass)
    {
      loginAcc = false;
    }

    if (loginAcc)
    {
      cout << "================================================================" << endl;
      cout << "\t\tLogin successful! Welcome " << nama << endl;
      cout << "================================================================" << endl;
      cout << "\t\t\tLuxury Hotel" << endl;
      cout << "================================================================" << endl;
      for (int i = 0; i < kota.jumlah; ++i)
      {
        cout << "\t" << i + 1 << ". " << arrKota[i] << endl;
      }
      cout << "Masukkan kota tujuan liburan\t: ";
      cin >> kota.kotaLiburan;
      cout << "\033[2J\033[H";

      if (kota.kotaLiburan == 1)
      {
        yogyakarta();
      }
      else if (kota.kotaLiburan == 2)
      {
        denpasar();
      }
      break;
    }
    else
    {
      cout << "Password anda salah!!" << endl;
    }
  }
  // Menu check in

  return 0;
}
