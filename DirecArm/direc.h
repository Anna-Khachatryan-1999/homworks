#include <iostream>
#include <vector>
#include <string>

class DirecFile
{
public:
    DirecFile(std::string name);
    virtual std::string getName() = 0;
    std::string getData() {return data;};
protected:
    std::string data;
};

class Dir : public DirecFile
{
public:
    Dir(std::string);
    void mkdir (std::string);
    void mkfile (std::string);
    void rm (std::string);
    void ls ();
    Dir* cd(std::string);
    std::string getName(){
         return ("Director :" + data);
    }

private:
    std::vector<DirecFile*> m_dir;
};

class File : public DirecFile
{
public:
    File(std::string);
    std::string getName(){
         return ("File :" + data);
    }
};

class MainDir
{
private:
    struct Node
    {
        Node(Dir* dir, Node* previous = nullptr): dir{dir},
           previous{previous} {}

        Dir* dir;
        Node* previous;
    };

public:
    void mkdir (std::string name)
    {
        if (!currentDir) {
            currentDir = new Node (new Dir(name));
        } else {
            currentDir->dir->mkdir(name);
        }
   }
    void mkfile (std::string name)
    {
        if (!currentDir) {
            std::cout << "can not create file, because have not directory" << std::endl;
        } else {
            currentDir->dir->mkfile(name);
        }
    }
    void rm (std::string name)
    {
        if (!currentDir) {
            std::cout << "have not directory" << std::endl;
        } else {
            currentDir->dir->rm(name);
        }
    }
    void ls()
    {
        if (!currentDir) {
            std::cout << "have not directory" << std::endl;
        } else {
            currentDir->dir->ls();
        }

    }
    void cd (std::string name)
    {
        if (!currentDir) {
           std::cout << "have not directory" << std::endl;
           return;
        }
        if (name == "..") {
            if (!currentDir->previous) {
                return;
            }
            Node* newcur = currentDir;
            currentDir = currentDir->previous;
            delete newcur;
            return;
        }
        Dir* ddir = currentDir->dir->cd(name);
        Node* newNode = new Node (ddir);
        newNode->previous = currentDir;
        currentDir = newNode;
    }

private:
    Node* currentDir = nullptr;

};

