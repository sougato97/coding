class Node {

private:
    int val;
    Node *next;

public:
    // need the variables to be declared as private as it helps us access those fro the 
    // other function. 

    // default constructor 
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }

    friend class LinkedList;
};

class LinkedList {
private:
    Node *head;
public:

    // default constructor
    LinkedList() {
        head = new Node(-1); 
        // this is the init value, also that is mentioned in the question. 
    }

    int get(int index) {
        int count = 0;
        Node *temp = head->next;
        if (temp == nullptr){
            return -1;
        }
        while (temp != nullptr){
            if (count == index)
                return temp->val;
            temp = temp->next;
            count++;
        }
        return -1; // index out of bound
    }

    void insertHead(int val) {
        Node *temp = new Node(val);
        temp->next = head->next;
        head->next = temp;
        // print();
    }
    
    void insertTail(int val) {
        Node *ptr = head->next;
        Node *temp = new Node(val);
        temp->next = nullptr; 
        if (ptr == nullptr)
        {
            head->next = temp;
        }
        else{       
            while (ptr->next != nullptr)
            {
                ptr=ptr->next;
            }
            ptr->next = temp;
        }
        // print();
    }

    void print(){
        Node *ptr=head->next;
        while (ptr!=nullptr)
        {
            cout<<ptr->val;
            ptr=ptr->next;
        }
        cout<<endl;
    }

    bool remove(int index) {
        Node *ptr = head->next;
        Node *prev = ptr;
        int count = 0;
        if (index == 0 && head->next){
            head = head->next;
            return true;
        }
        while (ptr != nullptr)
        {
            if (count < index){
                prev = ptr;
                ptr = ptr->next;
                count++;
            }
            else if (count == index){
                prev->next = ptr->next;
                return true;
            } 
            else{
                return false;
            }
        }
    }

    vector<int> getValues() {
        vector<int> res;
        Node *ptr = head->next;
        while (ptr != nullptr) { // Changed to include the last node
            res.push_back(ptr->val);
            ptr = ptr->next;
        }
        return res;
    }
};
