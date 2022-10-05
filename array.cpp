using namespace std;

//PRINT ELEMENTS FUNCTIONS

template <class Data>
void print(Data* array, int* n){
    cout << "Array: ";
    for(int i = 0; i < *n; i++)
        cout << *(array+i) << " ";
    cout << endl;
}

template <class Data>
void print_back(Data* array, int* n){
    cout << "Array: ";
    for(int i = *n-1; i >= 0; i--)
        cout << *(array+i) << " ";
    cout << endl;
}

//FIND ELEMENT FUNCTIONS
template <class Data>
int index(Data* array, int* n, Data key) {
    for(int i = 0; i < *n; i++)
        if(key == array[i])
            return i;
    return -1;
}

template <class Data>
int index_back(Data* array, int* n, Data key) {
    for(int i = *n-1; i >= 0; i--)
        if(key == array[i])
            return i;
    return -1;
}

//MODIFY ELEMENT IN LIST
template <class Data>
void add(Data* array, int* n, Data data) {
    array = (Data*)realloc(array, (*n+1) * sizeof(Data));
    array[*n] = data;
    (*n)++;
}

template <class Data>
void add(Data* array1, int* n1, Data* array2, int* n2) {
    array1 = (Data*)realloc(array1, (*n1 + *n2) * sizeof(Data));
    for(int i = 0; i < *n2; i++)
        array1[*n1-1+i] = array2[i];
    *n1 += *n2;
}

template <class Data>
void insert(Data* array, int* n, int key, Data d) {
    array = (Data*)realloc(array, (*n + 1) * sizeof(Data));
    for(int i = *n; i >= key+1; i--)
        array[i] = array[i-1];
    array[key+1] = d;
    (*n)++;
}

template <class Data>
void removeFromArray(Data* array, int* n, int key) {
    for(int i = key; i < *n-1; i++)
        array[i] = array[i+1];
    array = (Data*)realloc(array, (*n - 1) * sizeof(Data));
    (*n)--;
}

template <class Data>
void sort(Data* array, int start, int end){
    if(start < end){
        Data pivot = array[end];
        int less = start;

        for(int i = start; i < end; ++i){
            if(array[i] <= pivot){
                swap(array[i], array[less]);
                ++less;
            }
        }
        swap(array[less], array[end]);
        sort(array, start, less-1);
        sort(array, less+1, end);
    }
}