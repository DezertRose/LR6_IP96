#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

struct OrgData{
    string client;
    string text;
    string decor;
    string graf;
    int sum=0;
};

struct CostForPage {
    string page;
    int coast=0;
};

template <class T, typename T1, class T2>
class Cadvjournal {
 public:
   void AllFunction();

   Cadvjournal(){srand((unsigned int)(time(0)));}
   ~Cadvjournal() {};

 private:
   int  size = SizeOfData();
   T* dataArr = new T[size];
   T1* helpArr = new T1[4];
   T2* place = new T2[5];
   int* usedArr=new int[5];
   int* modelArr = new int[15];
   int SizeOfData();

   int fillHelpArrGraf();
   void CheckOnmodel();
   void ReadFromFile();
   int fillHelpArrDecor();
   int fillHelpArrText();
   string ChooseOne(int j, int start);
   int fillTopickArr(int i);
   void fillNumb(int* tempArr, int size, int numb);
};

template<> class Cadvjournal <OrgData, string, CostForPage>{
public:
    void AllFunction();

    Cadvjournal() { srand((unsigned int)(time(0))); }
    ~Cadvjournal() {};

private:
    int  size = SizeOfData();
    OrgData* dataArr = new OrgData[size];
    string* helpArr = new string[4];
    CostForPage* place = new CostForPage[5];
    int* usedArr = new int[5];
    int* modelArr = new int[15];

    int SizeOfData();
    int fillHelpArrGraf();
    void CheckOnmodel();
    void ReadFromFile();
    int fillHelpArrDecor();
    int fillHelpArrText();
    string ChooseOne(int j, int start);
    int fillTopickArr(int i);
    void fillNumb(int* tempArr, int size, int numb);
};

void Cadvjournal<OrgData, string, CostForPage>::AllFunction() {
    ReadFromFile();
    fillNumb(modelArr, 15, 0);
    CheckOnmodel();
    fillNumb( usedArr, 5, 0);
    for (int i = 0; i < size; i++) {
        cout << "For client " << i + 1 << " " << dataArr[i].client << endl;
        fillTopickArr(i);
    }

    int i = 0;
    cout << "For text model: " << endl;
    for (i = 0; i < 5; i++) {
        cout << i + 1 << ". "
            << modelArr[i]<<endl;
    }
    cout << "For design model: " << endl;
    while (i < 10) {
        if (10 > i && i>= 5){
            cout << i + 1 - 5 << ". "
                << modelArr[i]<<endl;
        }
        i++;
    }
    cout << "For graphic model: " << endl;
    while(i<15){
        if (i >= 10) {
             cout << i + 1 - 10 << ". "
                << modelArr[i]<<endl;
        }
        i++;
    }
}   

void Cadvjournal<OrgData, string, CostForPage>::fillNumb(int* tempArr,int size, int numb) {
    for (int i = 0; i < size; i++) {
        tempArr[i] = numb;
    }
}

int Cadvjournal<OrgData, string, CostForPage>::fillTopickArr(int i) {
    for (int i = 0; i < 5; i++) {
        int a = (11 * rand()) % 100+10;
        place[i].coast = a;
    }

    place[0].page = { "On first pagen in the middle." };
    place[1].page = { "On first page, at the bottom of the page." };
    place[2].page = { "On two page in the middle, on all page" };
    place[3].page = { "At the end, on all page." };
    place[4].page = { "At the end, on half a page." }; 

    int ans=0; 
    cout << "What you whant to choose?(you can choose until write -1) " << endl;
    for (int i = 0; i < 5; i++) {
        cout << i+1 << ". " << place[i].page << "prise: " << place[i].coast<<" UAH "<<endl;
    } 
    cout << "Your answer is: ";
    cin >> ans;
    while (ans != -1) {
        if (usedArr[ans - 1] == 0) {
            usedArr[ans - 1] = i+1;
            dataArr[i].sum = dataArr[i].sum + place[ans - 1].coast;
        }
        else { cout << "This one is not available. " << endl; }
        cout << "Your answer is: ";
        cin >>  ans;
    }
     return ans;
}

int Cadvjournal<OrgData, string, CostForPage>::fillHelpArrGraf() {
    helpArr[0] = { "Moving picture." };
    helpArr[1] = { "Moving button." };
    helpArr[2] = { "Diagram." };
    helpArr[3] = { "Tree." };
    int cost = rand() % 57 + 10;
    return cost;
}

int Cadvjournal<OrgData, string, CostForPage>::fillHelpArrText() {
    helpArr[0] = { "A fashion week." };
    helpArr[1] = { "New in science sphere." };
    helpArr[2] = { "Your future." };
    helpArr[3] = { "Your best friends in life." };
    int cost = rand() % 57 + 10;
     return cost;
}

int Cadvjournal<OrgData, string, CostForPage>::fillHelpArrDecor() {
    helpArr[0] = {"Mounting image."};
    helpArr[1] = { "Paris image." };
    helpArr[2] = { "Blue frame." };
    helpArr[3] = { "Paper background." };   

    int cost = rand() % 57 + 10;
    
    return cost;
}

int Cadvjournal<OrgData, string, CostForPage>::SizeOfData(){
    string path = "Data.txt";
    int temp = 0;
    ifstream fin;
    fin.open(path);
    int count = 0;
    string str;
    if (!fin.is_open()) { cout << "Can't open file!"; }
    else {
        while (!fin.eof()) {
            getline(fin, str, '\n');
            temp++;
        }
    }
    fin.close();
     return temp;
}

void Cadvjournal<OrgData, string, CostForPage>::ReadFromFile() {
    string path = "Data.txt";
    int temp = 0;
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) { cout << "Can't open file!"; }
    else {
        while (!fin.eof()) {
            getline(fin, dataArr[temp].client, ',');
            getline(fin, dataArr[temp].text, ',');
            getline(fin, dataArr[temp].decor, ',');
            getline(fin, dataArr[temp].graf, '\n');
            temp++;
        }
    }
    fin.close();
}

string Cadvjournal<OrgData, string, CostForPage>::ChooseOne(int j, int start) {
    int ans= 0;
    cout << "Wixh one is better for you? "<<endl;
    for (int i = 0; i < 4; i++) {
        cout << i+1 <<". " << helpArr[i]<< endl;
    }
    cin >> ans;
    modelArr[start+ans - 1] = modelArr[start + ans - 1] + j;
    return helpArr[ans - 1];
}

void Cadvjournal<OrgData, string, CostForPage>::CheckOnmodel()
{
    for (int i = 0; i < size; i++) {
        if (dataArr[i].decor.empty()) {
            cout << "Any wishes about decoration(if not 0): "<<endl;
            cin >> dataArr[i].decor;
            if (dataArr[i].decor == "0") {
                int a = fillHelpArrText();
                dataArr[i].sum= dataArr[i].sum+a;
                cout <<"Price: " <<a<<endl;
                dataArr[i].decor = ChooseOne(a, 5);
            }
        }
        if (dataArr[i].text.empty()) {
            cout << "Any wishes about text(if not 0): "<<endl;
            cin >> dataArr[i].text;
            if (dataArr[i].text == "0") {
                int a = fillHelpArrText();
                dataArr[i].sum = dataArr[i].sum + a;
                cout << "Price: " << a<<endl;
                dataArr[i].text = ChooseOne(a, 0);
            }
        }
        if (dataArr[i].graf.empty()) {
            cout << "Any wishes about grafic(if not 0): "<<endl;
            cin >> dataArr[i].graf;
            if (dataArr[i].graf == "0") {
                int a = fillHelpArrText();
                dataArr[i].sum = dataArr[i].sum + a;
                cout << "Price: " << a<<endl;
                dataArr[i].graf = ChooseOne(a, 10);
            }
        }
    }
}


int main()
{
    Cadvjournal<OrgData, string, CostForPage> mainC;
    mainC.AllFunction();    
}


