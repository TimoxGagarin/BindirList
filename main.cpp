#include <iostream>
#include <cstdlib>
#include <time.h>
#include <typeinfo>
#include "general_functions.cpp"
#include "list.cpp"
#include "array.cpp"
#include "inputs.cpp"
using namespace std;

int main(){
    List<int> list;
    int arrayLength;
    int* array = (int*)calloc(0, sizeof(int));

    int optionInputMode = 0;
    int operation = 0;
    clock_t t;

    int number;
    int temp;

    //Set array length
    cout << "Enter length of array ";
    do{
        fflush(stdin);
    }while(getInt(&arrayLength) != 1 || arrayLength < 1);

    //Set input mode
    cout << "Choose input mode: " << endl << "1. Manual input" << endl << "2. Random input" << endl;
    do{
        fflush(stdin);
    }while(getInt(&optionInputMode) != 1 || (optionInputMode != 1 && optionInputMode != 2));
    switch (optionInputMode){
        case 1:
            input(array, arrayLength);
            break;
        case 2:
            input_rand(array, arrayLength);
            break;
    }
    //copy array to list
    array_to_list(array, &list, arrayLength);

    while(1){
        //Choose operation
        cout << "Choose operation with array and list: " << endl
         << "1. Print" << endl
         << "2. Back print" << endl
         << "3. Find" << endl
         << "4. Index" << endl
         << "5. Index back" << endl
         << "6. Add element" << endl
         << "7. Insert element" << endl
         << "8. Remove element" << endl
         << "9. QuickSort" << endl
         << "10. Quit" << endl;
        do{
            fflush(stdin);
        }while(getInt(&operation) != 1 || (operation < 1 && operation > 10));
        switch (operation){
            case 1: //Print
                t = clock();
                list.print();
                showTime(t, (char*)"list");

                t = clock();
                print(array, &arrayLength);
                showTime(t, (char*)"array");
                break;
            case 2: // Back print
                t = clock();
                list.print_back();
                showTime(t, (char*)"list");

                t = clock();
                print_back(array, &arrayLength);
                showTime(t, (char*)"array");
                break;
            case 3: // Find
                inputInt(&number);

                t = clock();
                cout << "List[" << number << "] = " << list[number]->data << endl;
                showTime(t, (char*)"list");

                t = clock();
                cout << "Array[" << number << "] = " << array[number] << endl;
                showTime(t, (char*)"array");
                break;
            case 4: // Index
                inputInt(&number);

                t = clock();
                temp = list.index(number);
                if(temp != -1)
                    cout << "Index of " << number << " is " << temp << endl;
                else
                    cout << "No index with this value" << endl;
                showTime(t, (char*)"list");

                t = clock();
                temp = index(array, &arrayLength, number);
                if(temp != -1)
                    cout << "Index of " << number << " is " << temp << endl;
                else
                    cout << "No index with this value" << endl;
                showTime(t, (char*)"array");
                break;
            case 5: // Back index
                inputInt(&number);

                t = clock();
                temp = list.index_back(number);
                if(temp != -1)
                    cout << "Index of " << number << " is " << temp << endl;
                else
                    cout << "No index with this value" << endl;
                showTime(t, (char*)"list");

                t = clock();
                temp = index_back(array, &arrayLength, number);
                if(temp != -1)
                    cout << "Index of " << number << " is " << temp << endl;
                else
                    cout << "No index with this value" << endl;
                showTime(t, (char*)"array");
                break;
            case 6: //Add element
                inputInt(&number);

                t = clock();
                list.add(number);
                showTime(t, (char*)"list");

                t = clock();
                add(array, &arrayLength, number);
                showTime(t, (char*)"array");
                break;
            case 7: //Insert
                inputInt(&number);
                inputInt(&temp);

                t = clock();
                list.insert(temp, number);
                showTime(t, (char*)"list");

                t = clock();
                insert(array, &arrayLength, temp, number);
                showTime(t, (char*)"array");
                break;
            case 8: //Remove
                inputInt(&temp);

                t = clock();
                list.remove(temp);
                showTime(t, (char*)"list");

                t = clock();
                removeFromArray(array, &arrayLength, temp);
                showTime(t, (char*)"array");
                break;
            case 9: //QuickSort
                t = clock();
                list.sort(0, arrayLength-1);
                showTime(t, (char*)"list");

                t = clock();
                sort(array, 0, arrayLength-1);
                showTime(t, (char*)"array");
                break;
            case 10: //Quit
                fflush(stdin);
                getchar();
                return 0;
        }
    }
}