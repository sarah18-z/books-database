#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int maxrow = 10;


string EmpTitle[maxrow]={};
string EmpAuthor[maxrow]={};
string EmpYear[maxrow]={};
string EmpID[maxrow] = {};


void Openfile(){
    string line;
    ifstream myfile("books.txt");


    if (myfile.is_open()){
        int x = 0;
        while(getline(myfile, line)){
            int l = line.length();
            EmpID[x] = line.substr(0,3);
            EmpTitle[x] = line.substr(4, 1 - 4);
            /*EmpAuthor[x] = line.substr(5, 1 - 5);
            EmpYear[x] = line.substr(6, 1 - 6);*/
            x++;
        }
    } else {
        cout << "Enable to open the file !" << endl;
    }

}

void Addrecord() {
    char title[25];
    char author[25];
    char year[10];
    char empno[5];


    cin.ignore();
    cout << "book ID.";
    cin.getline(empno, 5);
    cout << "book title." ;
    cin.getline(title, 25);
    cout << "book author." ;
    cin.getline(author, 25);
    cout << "book year." ;
    cin.getline(year, 10);


    for (int x = 0; x < maxrow; x++){
        if (EmpID[x] == "\0"){
            EmpID[x]= empno;
            EmpTitle[x] = title;
            EmpAuthor[x] = author;
            EmpYear[x] = year;
            break;
        }
    }
}

void Listrecord(){
    system("CLS");
    cout << "Current Record(s)" << endl;
    cout << "====================================================================" << endl;

    int counter = 0;
    cout << "No.   |    ID      |     TITLE      |     AUTHOR    |     Year     " << endl << "--------------------------------------------------------------------\n";
    for (int x = 0; x < maxrow ; x++){
        counter++;
        cout << "  " << counter << "       " << EmpID[x] << "            " << EmpTitle[x] << "            " << EmpAuthor[x] << "            " << EmpYear[x] << endl;
     }
    if (counter == 0){
        cout << "No Record found! "<< endl;
}
    cout << "--------------------------------------------------------------------" << endl;

}

void Searchrecord(string search) {
    system("CLS");
    cout << "Current Record(s)" << endl;
    cout << "=========================================" << endl;
    int counter = 0;

    for (int x = 0; x < maxrow; x++){
        if (EmpID[x] == search){
            counter++;
            cout << "  " << counter << "       " << EmpID[x] << "            " << EmpTitle[x] << "            " << EmpAuthor[x] << "            " << EmpYear[x] << endl;
            break;
        }

    }
    if (counter == 0){
        cout << "No record found !";
    }

    cout << "=========================================" << endl;
}
void Updaterecord(string search){
    char title[25];
    char author[25];
    char year[10];
    char empno[5];

    int counter = 0;


    for (int x = 0; x < maxrow; x++){
        if (EmpID[x] == search) {
            counter++;
            cout << "Book Name." ;
            cin.getline(title, 25);

            cout << "Book Author." ;
            cin.getline(author, 25);

            cout << "Book Year." ;
            cin.getline(year, 10);

            EmpTitle[x] = title;
            EmpAuthor[x] = author;
            EmpYear[x] = year;


            cout << "update successull" << endl;
            break;
        }
    }
    if (counter == 0){
        cout << "ID doest not exist !";
    }
}


void Deleterecord(string search){
    int counter = 0;


    for (int x = 0; x < maxrow; x++){
    if (EmpID[x] == search) {
        counter++;

        EmpTitle[x] = "";
        EmpTitle[x] = "";
        EmpAuthor[x] = "";
        EmpYear[x] = "";

        EmpID[x] = "";

        cout << "Successully Deleted!" << endl;
        break;
    }
    }

    if (counter == 0){
        cout << "ID  number doest not exist !";
    }

}

void Savetofile(){
    ofstream myfile;
    myfile.open("books.txt");
    for (int x = 0; x < maxrow; x++){
        if (EmpID[x]== "\0"){
            break;
        } else{
            myfile << EmpID[x] + "," + EmpTitle[x] + "," + EmpAuthor[x] + "," + EmpYear[x] << endl;

        }
    }

}
int main (){
    std::cout << "MENU\n";
    int option;
    string empID;
    system("CLS");
    Openfile();


    do
    {
    cout << "MENU" << endl;
    cout << "1- create records" << endl;
    cout << "2- update records" << endl;
    cout << "3- Delete book" << endl;
    cout << "4- Search records" << endl;
    cout << "5- Display all records" << endl;
    cout << "6- Exit and save to textfile" << endl;
    cout << "-------------------------------------"<< endl;
    cout << "Select option";
    cin >> option;

    switch (option)
    {
    case 1:
        Addrecord();
        system("CLS");
        break;

    case 2:
        cin.ignore();
        cout << "Search by ID >>" ;
        getline(cin, empID);
        Updaterecord(empID);
        cin.ignore();
        system("CLS");
        break;

    case 3:
        cin.ignore();
        cout << "Delete by ID >>" ;
        getline(cin, empID);
        Deleterecord(empID);
        break;

    case 4:
        cin.ignore();
        cout << "Search by ID >>" ;
        getline(cin, empID);
        Searchrecord(empID);
        break;

    case 5:
        Listrecord();
        break;


    }

    } while (option != 6) ;
    Savetofile();
    cout << "Exit... Saving to file!" << endl;
    return 0;


}

