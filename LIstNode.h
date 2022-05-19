typedef int Rank;

template <typename T> struct ListNode{
    T data ;
    ListNode<T>* pred;
    ListNode<T>* succ;

    ListNode(){};
    ListNode(){T e,ListNode* p = NULL,ListNode* s = NULL}
    :data(e),pred(p),succ(s){}
    
    ListNode<T>* List<T> find(T const& e, int n,ListNode* p);
};

template <typename T>
T& ListNode* List<T>::find(T const& e,int n, ListNode* p) const{
    while(0 < n--){
        if(e == (p = p->pred)->data) return p;
    } 
    return NULL;
}
