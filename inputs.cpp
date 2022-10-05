template<class Data>
void input(List<Data>* list, int length){
    Data el;
    int natLen = 0;
    while(natLen < length){
        check_type(&el, natLen, (char*)"List");
        list->add(el);
    }
}

template<class Data>
void input(Data* array, int length){
    Data el;
    int natLen = 0;
    while(natLen < length){
        check_type(&el, natLen, (char*)"Array");
        add(array, &natLen, el);
    }
}

template<class Data>
void input_rand(List<Data>* list, int length){
    srand(time(NULL));
    for(int i = 0; i < length; i++)
        list->add((Data) (rand() - RAND_MAX/2));
}

template<class Data>
void input_rand(Data* array, int length){
    srand(time(NULL));
    int natLen = 0;
    while(natLen < length)
        add(array, &natLen, (Data) (rand() - RAND_MAX/2));
}

template<class Data>
void array_to_list(Data* array, List<Data>* list, int length){
    for(int i = 0; i < length; i++)
        list->add(array[i]);
}