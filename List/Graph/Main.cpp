#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

vector<string> readDictionary(string fileName);

void createGraph(list::Graph graph, vector<string> words, int length);

int main() {
    string dictionaryFilename = "";

    vector<string> dictionaryWords = readDictionary(dictionaryFilename);

    list::Graph graph(26);
    createGraph(graph,dictionaryWords,3);

}
/*
vector<string> readDictionary(string fileName) {
    vector<string> words;
    ifstream dictionaryFile(fileName);
    string word;
    while (dictionaryFile>>words){
        words.push_back(word);
    }
    return words;
}

void createGraph(list::Graph graph, vector<string> words, int length){
    for (string word : words) {
        if(word.length() == length){
            graph.addEdge(word);
        }
    }
}*/
