using namespace std;

int getInt(int* S) {
    int code = scanf("%i", S);
    if (code != 1)
        return code;
    char temp;
    while ((temp = getchar()) != '\n') {
        if ((temp > '9') || (temp < '0'))
            return -2;
        continue;
    }
    return 1;
}

int getFloat(float* S) {
    int code = scanf("%f", S);
    if (code != 1)
        return code;
    char temp;
    while ((temp = getchar()) != '\n') {
        if ((temp > '9') || (temp < '0') || (temp != '.'))
            return -2;
        continue;
    }
    return 1;
}

template<class Data>
void check_type(Data* el, int i, char* text){
    if(typeid(Data).name() == typeid(int).name()){
        do{
            fflush(stdin);
            cout << text << "[" << i << "] = ";
        }while(getInt(el) != 1);
        cout << endl;
    }
    else if(typeid(Data).name() == typeid(float).name() || typeid(Data).name() == typeid(double).name()){
        do{
            fflush(stdin);
            cout << text << "[" << i << "] = ";
        }while(getInt(el) != 1);
        cout << endl;
    }
    else{
        cout << text << "[" << i << "] = ";
        cin >> *el;
        cout << endl;
    }
}

template<class Data>
void swap(Data* a, Data* b){
    Data temp = *a;
    *a = *b;
    *b = temp;
}

void inputInt(int* integer){
    cout << "Enter some number: " << endl;
    do{
        fflush(stdin);
    }while(getInt(integer) != 1);
}

void showTime(time_t t, char* text){
    cout << "Time of " << text << "'s func - " << (float)(clock() - t) << " ms" << endl;
}