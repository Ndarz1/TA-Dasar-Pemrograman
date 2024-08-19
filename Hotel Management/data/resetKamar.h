#include <iostream>
#include <fstream>
#ifndef resetKamar_h
#define resetKamar_h
using namespace std;

void resetKamar(const char *dataKamar)
{
  ofstream file(dataKamar);

  if (file.is_open())
  {
    file << " " << endl;

    file.close();
  }
  else
  {
    cout << "Gagal membuka file untuk di reset" << endl;
  }
}

#endif // !resetKamar_h