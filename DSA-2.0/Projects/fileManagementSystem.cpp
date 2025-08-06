#include <iostream>
#include <string>

class File{
    public:
    std::string fileName;
    std::string fileType;
    int fileSize;
    File* next;
    File(std::string fileName, std::string fileType, int fileSize){
        this->fileName = fileName;
        this->fileType = fileType;
        this->fileSize = fileSize;
    }
};

class FileManager{
    public:
    File* head = NULL;
    File* tail = NULL;

    void addFiles(std::string fileName, std::string fileType, int fileSize){
        File* newFile = new File(fileName, fileType, fileSize);
        if(head==NULL){
            head = tail = newFile;
        }else{
            tail->next = newFile;
            tail = newFile;
        }
    }

    void removeFiles(std::string fileName){
        if(head->fileName==fileName){
            File* tempFile = head;
            head = head->next;
            delete tempFile;
            tempFile = NULL;
        }else{
            File* current = head;
            while(current->next!=NULL){
                if(current->next->fileName==fileName){
                    File* tempFile = current->next;
                    current->next = current->next->next;
                    delete tempFile;
                    std::cout<<"File: "<<fileName<<" removed"<<std::endl;
                    return;
                }
                current = current->next;
            }
        }
    }

    void searchFiles(std::string fileName){
        File* file = head;
        while(file!=NULL){
            if(file->fileName==fileName){
                std::cout<<std::endl;
                std::cout<<fileName<<" is available"<<std::endl;
                std::cout<<"size: "<<file->fileSize<<"MB"<<std::endl;
                std::cout<<"type: "<<file->fileType<<std::endl;
                return;
            }else{
                file = file->next;
            }
        }
    }

    void displayFiles(){
        File* file = head;
        std::cout<<"\nList of files: "<<std::endl;
        while(file!=NULL){
            std::cout<<"\nFile Name: "<<file->fileName<<std::endl;
            std::cout<<"File Type: "<<file->fileType<<std::endl;
            std::cout<<"File Size: "<<file->fileSize<<"MB"<<std::endl;
            file = file->next;
        }
    }

    ~FileManager(){
        File* file = head;
        while(file!=NULL){
            File* forward = file->next;
            File* tempFile = file;
            delete tempFile;
            file = forward;
            tempFile = NULL;
        }
    }
};

int main(){
    FileManager f;
    f.addFiles("ppt1.ppt", "powerpoint", 12);
    f.addFiles("ppt2.ppt", "powerpoint", 15);
    f.addFiles("music.mp3", "music", 6);
    f.addFiles("movie.mp4", "movie", 700);

    f.displayFiles();

    f.searchFiles("music.mp3");
    f.removeFiles("music.mp3");

    f.displayFiles();
    return 0;
}