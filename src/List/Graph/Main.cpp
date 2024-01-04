#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
using namespace std;

vector<string> readDictionary(string fileName) {
    vector<string> words;
    ifstream dictionaryFile(fileName);
    string word;
    while (dictionaryFile >> word){
        words.push_back(word);
        //cout << word << endl ;
    }
    return words;
}

bool checkDiff(string word1, string word2){
    int count = 0;
    for(int i= 0; i<word1.length();i++){
        if(word1[i] != word2[i]){
            count++;
        }
    }
    if(count ==1){
        return true;
    }else{
        return false;
    }
}

void createGraph(list::Graph& graph, vector<string> words){
    for (string word1 : words) {
        for (string word2 : words){
            if (checkDiff(word1, word2)) {
                graph.addEdge(word1, word2);
            }

        }
    }
}

int countWords(string filename ,int length){
    ifstream dictionaryFile(filename);
    string word;
    int count=0;
    while (dictionaryFile >> word){
        if (word.length() == length){
            count++;
        }
    }
    dictionaryFile.close();
    return count;
}

vector<string> wordList(vector<string> words ,int length){
    vector<string> subList;
    for (string word : words) {
        if(word.length() == length){
            subList.push_back(word);
        }
    }
    return subList;
}

int main() {
    string filename = "C:\\Users\\TEMP\\Desktop/english-dictionary.txt";

    vector<string> dictionaryWords = readDictionary(filename);

    int vertexCount = countWords(filename,3);
    vector<string> TreeLetterWords = wordList(dictionaryWords,3);
    list::Graph graph(vertexCount);
    createGraph(graph,TreeLetterWords);
    
    return 0;
}




