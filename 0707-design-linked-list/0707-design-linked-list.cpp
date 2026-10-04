 
class MyLinkedList {
public:
struct node{
    public:
        int val;
        node* next;
        node(int val){
            this->val=val;
            this->next=NULL;
        }
    };
    node* head;
    node* tail;
    int size;
    MyLinkedList() {
        head=tail=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0||index>=size)return -1;
        else if(index==0)return head->val;
        else if(index==size-1)return tail->val;
        else {
            node* temp=head;
            for(int i=1;i<=index;i++){
                temp=temp->next;
            }
            return temp->val;
        }
    }
    
    void addAtHead(int val) {
        node* temp=new node(val);
        temp->next=head;
        if(!head)tail=temp;
        head=temp;
        size++;
    }
    
    void addAtTail(int val) {
        node* temp=new node(val);
        if(!tail)head=tail=temp;
        else{tail->next=temp;
        tail=temp;}
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>size)return ;
        if(index==0){addAtHead(val);return;}
        if(index==size){addAtTail(val);return ;}

        node*temp=new node(val);
        node* t=head;
        for(int i=1;i<=index-1;i++){
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size)return;
        else if(index==0){
            head=head->next;
            size--;
            if(size==0)tail=NULL;
            return ;
        }
        else if(index==size-1){
            node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
        }
        else{
            node* temp=head;
            for(int i=1;i<=index-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */