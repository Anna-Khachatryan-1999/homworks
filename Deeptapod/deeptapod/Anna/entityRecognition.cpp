#include "entityRecognition.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

EntitySpecifier::EntitySpecifier(const std::string& word, const std::string& sentence, const std::string& text)
    : mWord{word}, mSentence{sentence}, mText{text}
{
    //DianEntityFunction(mWord) -> mNameEntities
     if (mNameEntities.size() == 1) {
        mEntity.entity = mNameEntities.begin()->first;
    } else if (mNameEntities.size() > 1) {
        analyzeText_();
    } else {
        Untility::logMassage("unknown word");
    }
}

EntitySpecifier::~EntitySpecifier()
{}

Entity EntitySpecifier::getEntity() const
{
    return mEntity;
}

void EntitySpecifier::analyzeText_()
{
    removeUnusedEntities_();
    if (mNameEntities.size() == 1) {
        mEntity.entity = mNameEntities.begin()->first;
    } else if (mNameEntities.size() > 1) {
        updateRepetitionsOfEntities_();
        int maxEntityValue = -1;
        int countMaxEntityValue = 0;
        bool isRepetitiousMaxValue = true;
        for (const auto& [key, value] : mNameEntities) {
            if (maxEntityValue < value) {
                if (!isRepetitiousMaxValue) {
                    --countMaxEntityValue;
                    isRepetitiousMaxValue = true;
                }
                mEntity.entity = key;
                maxEntityValue = value;
            } else if (maxEntityValue == value) {
                isRepetitiousMaxValue = false;
                ++countMaxEntityValue;
            }
        }
        if (countMaxEntityValue >= 1) {
            Untility::logWarning("There are many entities");
            mEntity.entity = "";
            //call new function, logica
        }
    } else {
        Untility::logMassage("unknown word");
    }
}

//maybe is wrong
void EntitySpecifier::removeUnusedEntities_()
{
    std::size_t firstEntity;
    for (auto it = mNameEntities.begin(); it != mNameEntities.end(); ) {
        firstEntity = mText.find(it->first);
        if (firstEntity == std::string::npos) {
            it = mNameEntities.erase(it);
        } else {
            ++it;
        }
    }
}

void EntitySpecifier::updateRepetitionsOfEntities_()
{
    devideTheSentenceIntoWords_();
    for (auto& [key, value] : mNameEntities) {
        for (int i = 0; i < mWordsInText.size(); ++i) {
            if (key == mWordsInText[i]) {
                ++value;
            }
        }
    }
}

void EntitySpecifier::devideTheSentenceIntoWords_()
{
    std::string tmp;
    for (int i = 0; i < mText.size(); ++i) {
        if (mText[i] == ' ' && tmp.size() > 0) {
            mWordsInText.push_back(tmp);
            tmp.clear();
        } else {
            tmp += mText[i];
        }
    }
    if (tmp.size() > 1) {
        mWordsInText.push_back(tmp);
    }
}
