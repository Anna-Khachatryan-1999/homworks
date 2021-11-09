#ifndef ENTITYRECOGNITION_H
#define ENTITYRECOGNITION_H

#include "untility.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Entity
{
    std::string entity;
    friend std::ostream& operator<<(std::ostream& os, const Entity& dt) {
        os << dt.entity;
        return os;
    }
};

class EntitySpecifier : public Untility
{
public:
    EntitySpecifier(const std::string& word, const std::string& sentence, const std::string& text);
    ~EntitySpecifier();

public:
    Entity getEntity() const;           //return entity

private:
    void analyzeText_();                     //find possible entity
    void devideTheSentenceIntoWords_();
    void removeUnusedEntities_();
    void updateRepetitionsOfEntities_();

private:
    std::vector<std::string> mWordsInText; //keeps the text word

private:
    std::string mWord;
    std::string mText;
    Entity mEntity;
    std::string mSentence;
    std::map<std::string, int> mNameEntities = {{"person", 0}, {"waterfall", 0}, {"company", 0}, {"state", 0}};
};


#endif //ENTITYRECOGNITION_H
