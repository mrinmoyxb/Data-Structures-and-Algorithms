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
            newPage->prev = current;
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
                current = current->prev;
                count-=1;
            }
            return current->data;
        }else{
            Node* temp = homePage;
            while(current!=temp){
                current = current->prev;
                count-=1;
            }
            return current->data;
        }
    }

    string forward(int steps){
        int remLength = length(current->next);
        if(steps<=remLength){
            int check = 0;
            while(check!=steps){
                check+=1;
                current = current->next;
                count+=1;
            }
            return current->data;
        }else{
            return "Cannot move forward any steps";
        }
    }

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
    BrowserHistory b = BrowserHistory("leetcode.com");
    b.visit("google.com");
    b.visit("facebook.com");
    b.visit("youtube.com");
    std::cout<<"\n";
    b.showPages();

    std::cout<<"\nBack 1: "<<b.back(1)<<"\n";
    std::cout<<"Back 1: "<<b.back(1)<<"\n";
    std::cout<<"Forward 1: "<<b.forward(1)<<"\n";
    b.showPages();
    std::cout<<"\n";

    b.visit("linkedin.com");
    b.showPages();

    std::cout<<"\nForward 2: "<<b.forward(2)<<"\n";
    std::cout<<"Back 2: "<<b.back(2)<<"\n";
    std::cout<<"\n";

    b.showPages();
    std::cout<<"\nBack 7: "<<b.back(7)<<"\n";
    
    return 0;
}
