#include "direc.h"
DirecFile::DirecFile(std::string name) : data(name) {}
Dir::Dir (std::string name) : DirecFile{name} {}
File::File (std::string name) : DirecFile{name} {}

void Dir::mkdir (std::string name)
{
  m_dir.push_back (new Dir(name));
}
void Dir::mkfile (std::string name)
{
  m_dir.push_back (new File(name));
}
void Dir::rm (std::string name)
{
    for (std::vector<DirecFile*>::iterator it = m_dir.begin();
            it != m_dir.end(); ++it) {
        if ((*it)->getData() == name) {
            m_dir.erase(it);
            return;
        }
    }
}
void Dir::ls()
{
    for (std::vector<DirecFile*>::iterator it = m_dir.begin();
            it != m_dir.end(); ++it) {
        std::cout << (*it)->getName() << std::endl;
    }
    std::cout << std::endl;
}

Dir* Dir::cd(std::string name)
{
    for (std::vector<DirecFile*>::iterator it = m_dir.begin();
            it != m_dir.end(); ++it) {
        if ((*it)->getData() == name) {
            return dynamic_cast<Dir*>(*it);
        }
    }
    return nullptr;

}
