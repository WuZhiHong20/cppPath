//deduplicate(), uniquify(), traverse()
//$ addItems <infile >outfile
//addItems可执行文件，<infile读infile文件，>outfile输出到,均在当前目录中
typedef int Rank;
#define DEFAULT_CAPACITY 3
template <typename T> class Vector{
protected:
    Rank _size;
    int _capacity;
    T* _elem;
    void expand();
    void shrink();
    void insert();
    T& operator[](Rank i) const;

    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){
        _elem = new T[_capacity = c];
        for(_size = 0;_size < s;_elem[_size++] = v);
    }
};

template <typename T> void Vector<T>::expand(){
    if(_size < _capacity) return ;
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* oddElem = _elem;
    _elem = new T[_capacity<<1];
    for(int i=0;i<_size();i++){
        _elem[i] = oddElem[i];
    }
    delete [] oddElem;
}

template <typename T> T& Vector<T>::operator[](Rank i) const{
    return _elem[i];
}