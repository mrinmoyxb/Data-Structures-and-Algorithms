#include <iostream>
using std::string;

class Node{
    public:
    string data;
    Node* prev;
    Node* next;
    Node(string data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

int length(Node* head){
    int count = 0;
    while(head!=NULL){
        count+=1;
        head = head->next;
    }
    return count;
}

class BrowserHistory{
    public:
    Node* homePage = nullptr;
    Node* current = nullptr;
    int count;

    BrowserHistory(string Homepage){
        this->homePage = new Node(Homepage);
        this->current = homePage;
        count = 1;
    }

    void visit(string url){
        Node* newPage = new Node(url);
        if(current->next!=NULL){
            Node* forward = current->next;
            current->next = newPage;
            current = newPage;
            delete forward;
            count+=1;
        }else{
            current->next = newPage;
            newPage->prev = current;
            current = newPage;
            count+=1;
        }
    }
    
    string back(int steps){
        if(steps<count){
            int check = 0;
            while(check!=steps){
                check+=1;
                //Node* delPage = current;
                current = current->prev;
                //delete  delPage;
                count-=1;
            }
            return current->data;
        }else{
            return "Not possible";
        }
    }

    // string forward(){
    //     if(current->next!=NULL){

    //     }else{

    //     }
    // }

    void showPages(){
        Node* current = homePage;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    int checkCount(){
        return count;
    }

};

int main(){
    BrowserHistory b = BrowserHistory("web1.com");
    b.visit("web2.com");
    b.visit("web3.com");
    b.visit("web4.com");
    b.visit("web5.com");

    b.showPages();
    std::cout<<"\nCurrent after back 2: "<<b.back(2)<<"\n";
    std::cout<<"\nCount: "<<b.checkCount()<<"\n";

    b.showPages();
    std::cout<<"\nCurrent after back 4: "<<b.back(4)<<"\n";
    std::cout<<"\nCount: "<<b.checkCount()<<"\n";

    b.visit("random.com");
    std::cout<<"\n";
    b.showPages();
    std::cout<<"\nCount: "<<b.checkCount()<<"\n";
    
    return 0;
}
