using namespace std;

template <class Data>
class Node {
    public:
        Data data;
        Node<Data>* next;
        Node<Data>* prev;
        Node(Data dat = 0) {
            data = dat; 
            next = 0;
            prev = 0;
        }
};

template <class Data>
class List {
    public:
        Node<Data>* pbeg;
        Node<Data>* pend;
        List() {
            pbeg = 0;
            pend = 0;
        }
        ~List();
        void print();
        void print_back();

        int length();

        int index(Data key);
        int index_back(Data key);

        void add(Data data);
        void add(List<Data>* list);
        void insert(int key, Data d);
        void insert(int key, List<Data>* list);
        void remove(int i);
        Node<Data>* operator [](int i){
            Node<Data>* pv = pbeg;
            for(int j = 0; j < i; j++)
                pv = pv->next;
            return pv;
        }

        void sort(int start, int end);
};

template <class Data>
List<Data>::~List() {
    if (pbeg != 0) {
        Node<Data>* pv = pbeg;
        while (pv) {
            pv = pbeg->next;
            delete pbeg;
            pbeg = pv;
        }
    }
}

//PRINT ELEMENTS FUNCTIONS

template <class Data>
void List<Data>::print(){
    Node<Data>* pv = pbeg;
    cout << endl << "List: ";
    while(pv){
        cout << pv->data << " ";
        pv = pv->next;
    }
    cout << endl;
}

template <class Data>
void List<Data>::print_back(){
    Node<Data>* pv = pend;
    cout << endl << "List: ";
    while(pv){
        cout << pv->data << " ";
        pv = pv->prev;
    }
    cout << endl;
}

template <class Data>
int List<Data>::length() {
    Node<Data>* pv = pbeg;
    int length = 0;
    while(pv){
        pv = pv->next;
        length++;
    }
    return length;
}

//FIND ELEMENT FUNCTIONS
template <class Data>
int List<Data>::index(Data key) {
    Node<Data>* pv = pbeg;
    int i = 0;
    while(pv && pv->data != key){
        pv = pv->next;
        i++;
    }
    if(pv)
        return i;
    return -1;
}

template <class Data>
int List<Data>::index_back(Data key) {
    Node<Data>* pv = pend;
    int i = length()-1;
    while(pv->data != key && pv){
        pv = pv->prev;
        i--;
    }
    if(pv)
        return i;
    return -1;
}

//MODIFY ELEMENT IN LIST
template <class Data>
void List<Data>::add(Data data) {
    Node<Data>* pv = new Node<Data>(data);
    if(pbeg == 0){
        pbeg = pv;
        pend = pv;
    }
    else{
        pv->prev = pend;
        pend->next = pv;
        pend = pv;
    }
}

template <class Data>
void List<Data>::add(List<Data>* list) {
    pend->next = list->pbeg;
    (list->pbeg)->prev = pend;
    pend = list->pend;
}

template <class Data>
void List<Data>::insert(int key, Data d) {
    if(Node<Data>* pkey = (*this)[key]){
        Node<Data>* pv = new Node<Data>(d);
        pv->next = pkey->next;
        pv->prev = pkey;
        pkey->next = pv;
        if(pkey != pend)
            (pv->next)->prev = pv;
        else
            pend = pv;
    }
}

template <class Data>
void List<Data>::insert(int key, List<Data>* list) {
    if(Node<Data>* pkey = (*this)[key]){
        (list->pbeg)->prev = pkey;
        (list->pend)->next = pkey->next;
        pkey->next = list->pbeg;
        if(pkey != pend)
            (pkey->next)->prev = list->pend;
        else
            pend = list->pend;
    }
}

template <class Data>
void List<Data>::remove(int i) {
    if(Node<Data>* pkey = (*this)[i]){
        if(pkey == pbeg){
            pbeg = pkey->next;
            pbeg->prev = 0;
        }
        else if(pkey == pend){
            pend = pkey->prev;
            pend->next = 0;
        }
        else{
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }
        delete pkey;
    }
}

template <class Data>
void List<Data>::sort(int start, int end){
    if(start < end){
        Data pivot = ((*this)[end])->data;
        int less = start;

        for(int i = start; i < end; ++i){
            Data* el = &(((*this)[i])->data);
            if(*el <= pivot){
                swap(el, &(((*this)[less])->data));
                ++less;
            }
        }
        swap(&(((*this)[less])->data), &(((*this)[end])->data));
        sort(start, less-1);
        sort(less+1, end);
    }
}