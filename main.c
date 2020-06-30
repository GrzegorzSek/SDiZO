// lab1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace std::chrono;

/*void ReadFromFile(char FileName[], int storage[], int &NumberOfElements) {
    ifstream take(FileName);
    take >> NumberOfElements;

    for (int i = 0; i < NumberOfElements; i++) {
        take >> storage[i];
    }
}
void Show(int Entries, int Array[]) {
    for (int i = 0; i < Entries; i++) {
        cout << Array[i] << '\t';
        if (!(i % 10))
            cout << endl;
    }
}*/
/*void ileCzasu(int i) {
    if (i == 0) {
        auto start = high_resolution_clock::now();
    }
    if (i == 1) {
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by function: "
            << duration.count() << " microseconds" << endl;
    }
}*/
void zapisDoPlikuCzas(long int Czas[100]) {
    int i = 0;
    cout << "Trwa zapis czasu do pliku... " << endl;
    ofstream outputFile("czas.csv");
    for (int i = 0; i < 100; i++) { // wypisanie czasu
        outputFile << Czas[i] << endl;
    }
    cout << "zapisano! " << endl;
}
void zapisDoPliku(vector<float>& Liczby, int i) {
        cout << "Trwa zapis do pliku... " << endl;
        ofstream outputFile(std::to_string(i) + ".csv");
        for (int i = 0; i < Liczby.size(); i++) { // wypisanie posortowanej tablicy
            outputFile << Liczby[i] << endl;
        }
        cout << "zapisano! " << endl;
}
void zapisDoPlikuInt(vector<int>& LiczbyIntKopia, int i) {
    cout << "Trwa zapis do pliku... " << endl;
    ofstream outputFile(std::to_string(i) + ".csv");
    for (int i = 0; i < LiczbyIntKopia.size(); i++) { // wypisanie posortowanej tablicy
        outputFile << LiczbyIntKopia[i] << endl;
    }
    cout << "zapisano! " << endl;
}
void srednia(vector<float>& Liczby) {
    float srednia = 0;
    float suma = 0;
    for (int i = 0; i < Liczby.size(); i++) {
        suma = suma + Liczby[i];
    }
    srednia = suma / Liczby.size();
    cout << "srednia jest rowna: " << srednia << endl;
}
//-------------------------------BĄBELKOWE--------------------INT--------------------
void babelkoweInt(vector<int>& LiczbyIntKopia) {
    int czyPosortowane = 0;
    for (int i = 1; i < LiczbyIntKopia.size(); i++) {
        if (LiczbyIntKopia[i - 1] > LiczbyIntKopia[i]) {
            czyPosortowane = 1;
        }
    }
    if (czyPosortowane == 1) {
        //cout << "Zaczynam sortowac..." << endl;
        for (int i = 0; i < LiczbyIntKopia.size(); i++) {
            for (int j = 1; j < LiczbyIntKopia.size() - i; j++) {
                if (LiczbyIntKopia[j - 1] > LiczbyIntKopia[j]) {
                    swap(LiczbyIntKopia[j - 1], LiczbyIntKopia[j]);
                }
            }
        }
    }
    else {
        cout << "Liczby sa juz posortowane" << endl;
    }
}
//-------------------------------BĄBELKOWE-------------------INT---------------------
//-------------------------------QUICKSORT-------------------INT---------------------
void quicksortInt(vector<int>& LiczbyIntKopia, int lewy, int prawy)
{
    int v = LiczbyIntKopia[(lewy + prawy) / 2];
    int i, j;
    int x;
    i = lewy;
    j = prawy;
    do {
        while (LiczbyIntKopia[i] < v) i++;
        while (LiczbyIntKopia[j] > v) j--;
        if (i <= j) {
            x = LiczbyIntKopia[i];
            LiczbyIntKopia[i] = LiczbyIntKopia[j];
            LiczbyIntKopia[j] = x;
            i++; j--;
        }
    } while (i <= j);
    if (j > lewy) quicksortInt(LiczbyIntKopia, lewy, j);
    if (i < prawy) quicksortInt(LiczbyIntKopia, i, prawy);
}
//-------------------------------QUICKSORT------------------INT----------------------
//-------------------------------HEAPSORT------------------INT----------------------
void heapifyInt(vector<int>& LiczbyIntKopia, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && LiczbyIntKopia[l] > LiczbyIntKopia[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && LiczbyIntKopia[r] > LiczbyIntKopia[largest])
        largest = r;

    // If largest is not root 
    if (largest != i)
    {
        swap(LiczbyIntKopia[i], LiczbyIntKopia[largest]);

        // Recursively heapify the affected sub-tree 
        heapifyInt(LiczbyIntKopia, n, largest);
    }
}

// main function to do heap sort 
void heapSortInt(vector<int>& LiczbyIntKopia, int n)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyInt(LiczbyIntKopia, n, i);

    // One by one extract an element from heap 
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end 
        swap(LiczbyIntKopia[0], LiczbyIntKopia[i]);

        // call max heapify on the reduced heap 
        heapifyInt(LiczbyIntKopia, i, 0);
    }
}
//-------------------------------HEAPSORT--------------INT--------------------------
//-------------------------------BĄBELKOWE----------------------------------------
void babelkowe(vector<float>& Liczby) {
    int czyPosortowane = 0;
    for (int i = 1; i < Liczby.size(); i++) {
        if (Liczby[i - 1] > Liczby[i]) {
            czyPosortowane = 1;
        }
    }
    if (czyPosortowane == 1) {
        cout << "Zaczynam sortowac..." << endl;
        for (int i = 0; i < Liczby.size(); i++) {
            for (int j = 1; j < Liczby.size() - i; j++) {
                if (Liczby[j - 1] > Liczby[j]) {
                    swap(Liczby[j - 1], Liczby[j]);
                }
            }
        }
    }
    else {
        cout << "Liczby sa juz posortowane" << endl;
    }
}
//-------------------------------BĄBELKOWE----------------------------------------
//-------------------------------QUICKSORT----------------------------------------
void quicksort(vector<float>& Liczby, int lewy, int prawy)
{
    float v = Liczby[(lewy + prawy) / 2];
    int i, j;
    float x;
    i = lewy;
    j = prawy;
    do {
        while (Liczby[i] < v) i++;
        while (Liczby[j] > v) j--;
        if (i <= j) {
            x = Liczby[i];
            Liczby[i] = Liczby[j];
            Liczby[j] = x;
            i++; j--;
        }
    } while (i <= j);
    if (j > lewy) quicksort(Liczby, lewy, j);
    if (i < prawy) quicksort(Liczby, i, prawy);
}
//-------------------------------QUICKSORT----------------------------------------
//-------------------------------HEAPSORT----------------------------------------
void heapify(vector<int>& LiczbyIntKopia, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && LiczbyIntKopia[l] > LiczbyIntKopia[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && LiczbyIntKopia[r] > LiczbyIntKopia[largest])
        largest = r;

    // If largest is not root 
    if (largest != i)
    {
        swap(LiczbyIntKopia[i], LiczbyIntKopia[largest]);

        // Recursively heapify the affected sub-tree 
        heapify(LiczbyIntKopia, n, largest);
    }
}

// main function to do heap sort 
void heapSort(vector<int>& LiczbyIntKopia, int n)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(LiczbyIntKopia, n, i);

    // One by one extract an element from heap 
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end 
        swap(LiczbyIntKopia[0], LiczbyIntKopia[i]);

        // call max heapify on the reduced heap 
        heapify(LiczbyIntKopia, i, 0);
    }
}
//-------------------------------HEAPSORT----------------------------------------
//-------------------------------ZLICZANIE----------------------------------------
void countSort(vector <int>& LiczbyIntKopia)
{
    int max = *max_element(LiczbyIntKopia.begin(), LiczbyIntKopia.end());
    int min = *min_element(LiczbyIntKopia.begin(), LiczbyIntKopia.end());
    int range = max - min + 1;

    vector<int> count(range), output(LiczbyIntKopia.size());
    for (int i = 0; i < LiczbyIntKopia.size(); i++)
        count[LiczbyIntKopia[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = LiczbyIntKopia.size() - 1; i >= 0; i--)
    {
        output[count[LiczbyIntKopia[i] - min] - 1] = LiczbyIntKopia[i];
        count[LiczbyIntKopia[i] - min]--;
    }

    for (int i = 0; i < LiczbyIntKopia.size(); i++)
        LiczbyIntKopia[i] = output[i];
}
//-------------------------------ZLICZANIE----------------------------------------

void printInterface(vector <string> options, int select)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    unsigned int max_length = 0;
    int swt = 2;
    char LG = 201;
    char PG = 187;
    char LD = 200;
    char PD = 188;
    char LK = 204;
    char PK = 185;
    char poz = 205;
    char pion = 186;
    for (string s : options)
    {
        if (s.length() > max_length) max_length = s.length();
    }
    if (max_length < 4)
    {
        cout << "Nadluzsza z opcji musi miec przynajmniej 4 znaki" << endl;
        return;
    }
    if (max_length % 2 == 0) swt = 1;
    cout << LG;
    for (int i = 0; i < max_length + 2; i++) cout << poz;
    cout << PG << endl << pion;
    for (int i = 0; i < (max_length - 4) / 2 + 1; i++) cout << " ";
    cout << "MENU";
    for (int i = 0; i < (max_length - 4) / 2 + swt; i++) cout << " ";
    cout << pion << endl << LK;
    for (int i = 0; i < max_length + 2; i++) cout << poz;
    cout << PK << endl;
    int x = 0;
    for (string s : options)
    {
        cout << pion;
        for (int i = 0; i < (max_length - s.length()) / 2 + 1; i++) cout << " ";
        if (x == select) SetConsoleTextAttribute(hOut, FOREGROUND_RED);
        cout << s;
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        if (s.length() % 2 == 0)
        {
            for (int i = 0; i < (max_length - s.length()) / 2 + swt; i++) cout << " ";
        }
        else
        {
            for (int i = 0; i < (max_length - s.length()) / 2 + abs(swt - 3); i++) cout << " ";
        }
        cout << pion << endl;
        x++;
    }
    cout << LD;
    for (int i = 0; i < max_length + 2; i++) cout << poz;
    cout << PD;
}

int main()
{
    float max = 0;
    float min = 0;
    float mean = 0;
    vector<float> LiczbyOryg;
    vector<float> Liczby;
    vector<int> LiczbyInt;
    vector<int> LiczbyIntKopia;
    vector <string> options;
    long int Czas[100];
    int floatCzyInt;
    int iloscPowtorzen;
    int NumberOfElements;
    string Tryb;
    int czas;
    int srednia;
    int selected = 0;
    options.push_back("1. Wgraj plik wejsciowy");
    options.push_back("2. Sortowanie algorytmem babelkowym");
    options.push_back("3. Sortowanie algorytmem szybkim");
    options.push_back("4. Sortowanie przez zliczanie");
    options.push_back("5. Sortowanie BST");
    options.push_back("6. Sortowanie kopcowe");
    options.push_back("7. Zamknij program");
    while (true)
    {
        system("cls");
        printInterface(options, selected);
        char pick;
        pick = _getch();
        if (pick == 'w')
        {
            if (selected > 0) selected--;
            else selected = options.size() - 1;
        }
        else if (pick == 's')
        {
            if (selected < options.size() - 1) selected++;
            else selected = 0;
        }
        else if (pick == 13)
        {
            system("cls");
            cout << "Wybrano opcje: " << selected + 1 << endl<< "wcisnij Enter" << endl;
            cin.get();

            if (selected + 1 == 1) {
                ifstream in("dane.csv");
                //ifstream in("dane.csv");
                string line, field;

                vector <string> v;

                getline(in, line);
                getline(in, line);
                //wczytanie rekordow
                getline(in, line);
                line = line.substr(13);
                line.erase(line.begin() + line.find(" "), line.end());
                NumberOfElements = stoi(line);
                //FLOAT/INT
                getline(in, line);
                line = line.substr(8);
                line.erase(line.begin() + line.find(" "), line.end());
                Tryb = line;
                if (Tryb == "int") {
                    floatCzyInt = 1;
                }
                else {
                    floatCzyInt = 0;
                }
                //liczba powtorzen
                getline(in, line);
                line = line.substr(17);
                line.erase(line.begin() + line.find(" "), line.end());
                iloscPowtorzen = stoi(line);
                //[DATA]
                getline(in, line);

                while (getline(in, line))
                {
                    stringstream ss(line);
                    v.push_back(line);
                }
                /*for (size_t i = 0; i < v.size(); ++i)
                {
                    //cout << v[i];

                    //cout << "\n";
                }
                */
                for (size_t i = 0; i < NumberOfElements; ++i)
                {
                    float k = 0;
                    stringstream dd(v[i]);
                    dd >> k;
                    LiczbyOryg.push_back(k);
                    //cout << k << endl; //Wyświetlanie liczb
                    
                } 

                cout << "Tyle jest liczb: " << LiczbyOryg.size() << endl;
                cout << "Ilosc powtorzen wybranego sposobu sortowania: " << iloscPowtorzen << endl << endl;
                //wczytanie intów
                for (size_t i = 0; i < NumberOfElements; ++i)
                {
                    int k = 0;
                    stringstream dd(v[i]);
                    dd >> k;
                    LiczbyInt.push_back(k);
                    //cout << k << endl; //Wyświetlanie liczb

                }
                //Wczytanie intów
                //for (size_t i = 0; i < Liczby.size(); ++i)
                //{
                //    cout << Liczby[i];
                //    cout << "\n";
                //}
                //float average = accumulate(Liczby.begin(), Liczby.end(), 0.0 / Liczby.size());
                //cout << "srednia: " << average << endl;
                //float minimum = *min_element(Liczby.begin(), Liczby.end());
                //cout << "minimum: " << minimum << endl;
                //float maximum = *max_element(Liczby.begin(), Liczby.end());
                //cout << "maksimum: " << maximum << endl;
                system("pause");
            }
            // ------------------------BABELKOWE-------------------------------
            if (selected + 1 == 2) {
                for (int i = 0; i < iloscPowtorzen; i++) {
                    Liczby = LiczbyOryg;
                    LiczbyIntKopia = LiczbyInt;
   
                    if (floatCzyInt == 1) {
                        auto start = high_resolution_clock::now();
                        babelkoweInt(LiczbyIntKopia); // wywolanie funkcji sortujacej
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);

                        cout << i << endl;
                        //cout << "zajelo czasu: "
                        //    << duration.count() << " mikrosekund" << endl;

                        //cout << "zapisano! " << endl;
                        //zapisDoPlikuInt(LiczbyIntKopia, i);

                        auto rawValue = duration.count();
                        Czas[i] = rawValue;
                        //system("pause");
                    }
                    else {
                        auto start = high_resolution_clock::now();
                        babelkowe(Liczby); // wywolanie funkcji sortujacej
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);
                        cout << i << endl;

                        //cout << "zajelo czasu: "
                        //    << duration.count() << " mikrosekund" << endl;
                        //cout << "zapisano! " << endl;
                        //zapisDoPliku(Liczby, i);

                        auto rawValue = duration.count();
                        Czas[i] = rawValue;
                        //system("pause");
                    }
                }
                zapisDoPlikuCzas(Czas);
            }
            // ------------------------BABELKOWE-------------------------------
            // ------------------------QUICKSORT-------------------------------
            if (selected + 1 == 3) {
                for (int i = 0; i < iloscPowtorzen; i++) {
                    cout << "Zaczynam sortowac..." << endl;
                    Liczby = LiczbyOryg;
                    LiczbyIntKopia = LiczbyInt;

                    
                    if (floatCzyInt == 1) {
                        auto start = high_resolution_clock::now();
                        quicksortInt(LiczbyIntKopia, 0, LiczbyIntKopia.size() - 1); // wywolanie funkcji sortujacej
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);
                        cout << "zajelo czasu: " << duration.count() << " mikrosekund" << endl;
                        auto rawValue = duration.count();
                        Czas[i]= rawValue;

                        //  for (int i = 0; i < Liczby.size(); i++) { // wypisanie posortowanej tablicy
                         //     cout << Liczby[i] << endl;
                         // }
                        cout << "Dane zostaly posortowane." << endl;
                       // zapisDoPlikuInt(LiczbyIntKopia, i);
                        //system("pause");
                    }
                    else {
                        auto start = high_resolution_clock::now();
                        quicksort(Liczby, 0, Liczby.size() - 1); // wywolanie funkcji sortujacej
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);
                        cout << "zajelo czasu: "
                            << duration.count() << " mikrosekund" << endl;
                        //  for (int i = 0; i < Liczby.size(); i++) { // wypisanie posortowanej tablicy
                         //     cout << Liczby[i] << endl;
                         // }
                        cout << "Dane zostaly posortowane." << endl;
                        //zapisDoPliku(Liczby, i);

                        auto rawValue = duration.count();
                        Czas[i] = rawValue;
                        //system("pause");

                    
                    }
                }
                zapisDoPlikuCzas(Czas);
            }
            // ------------------------QUICKSORT-------------------------------
            // ------------------------ZLICZANIE-------------------------------
            if (selected + 1 == 4) {
                  for (int i = 0; i < iloscPowtorzen; i++) {
                      LiczbyIntKopia = LiczbyInt;
                      auto start = high_resolution_clock::now();
                      countSort(LiczbyIntKopia); // wywolanie funkcji sortujacej
                      auto stop = high_resolution_clock::now();
                      auto duration = duration_cast<microseconds>(stop - start);

                      cout << "zajelo czasu: "
                          << duration.count() << " mikrosekund" << endl;
                      //for (int i = 0; i < Liczby.size(); i++) { // wypisanie posortowanej tablicy
                      //    cout << Liczby[i] << endl;
                      //}
                      //zapisDoPlikuInt(LiczbyIntKopia, i);

                      auto rawValue = duration.count();
                      Czas[i] = rawValue;
                      //system("pause");
                  }
                  zapisDoPlikuCzas(Czas);
            }
            // ------------------------ZLICZANIE-------------------------------
            // ------------------------BST-------------------------------
            if (selected + 1 == 5) {
            }
            // ------------------------BST-------------------------------
            // ------------------------KOPCOWE-------------------------------
            if (selected + 1 == 6) {
                for (int i = 0; i < iloscPowtorzen; i++) {
                    LiczbyIntKopia = LiczbyInt;
                    auto start = high_resolution_clock::now();
                    heapSort(LiczbyIntKopia, LiczbyIntKopia.size()); // wywolanie funkcji sortujacej
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);

                    cout << "zajelo czasu: "
                        << duration.count() << " mikrosekund" << endl;
                    //for (int i = 0; i < Liczby.size(); i++) { // wypisanie posortowanej tablicy
                    //    cout << Liczby[i] << endl;
                    //}
                    //zapisDoPlikuInt(LiczbyIntKopia, i);

                    auto rawValue = duration.count();
                    Czas[i] = rawValue;
                    //system("pause");
                }
                zapisDoPlikuCzas(Czas);
            }
            // ------------------------KOPCOWE-------------------------------
            // ------------------------WYJSCIE-------------------------------
            if (selected + 1 == 7) {
                cout << "";
                break;
            }
            // ------------------------WYJSCIE-------------------------------
        }
    }
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
