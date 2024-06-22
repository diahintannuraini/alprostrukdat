#include <iostream>
using namespace std;

void tampilGraph(string *simpul, int **busur, int intan_2311110046)
{
    cout << endl;
    for (int i = 0; i < intan_2311110046; i++)
    {
        cout << "\t" << simpul[i];
    }
    cout << endl;
    for (int i = 0; i < intan_2311110046; i++)
    {
        cout << simpul[i] << "\t";
        for (int j = 0; j < intan_2311110046; j++)
        {
            cout << busur[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int intan_2311110046;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> intan_2311110046;
    cin.ignore();
    cout << "Silahkan masukkan nama simpul" << endl;

    string *simpul = new string[intan_2311110046];
    for (int i = 0; i < intan_2311110046; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        getline(cin, simpul[i]);
    }

    int **busur = new int *[intan_2311110046];
    for (int i = 0; i < intan_2311110046; i++)
    {
        busur[i] = new int[intan_2311110046];
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < intan_2311110046; i++)
    {
        for (int j = 0; j < intan_2311110046; j++)
        {
            cout << simpul[i] << "-->" << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    tampilGraph(simpul, busur, intan_2311110046);

    for (int i = 0; i < intan_2311110046; i++)
    {
        delete[] busur[i];
    }
    delete[] busur;
    delete[] simpul;

    return 0;
}