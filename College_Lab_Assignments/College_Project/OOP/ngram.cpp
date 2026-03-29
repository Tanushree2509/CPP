#include <iostream>
#include <fstream> // ifstream (input file stream) is used to read training_text.txt
#include <sstream> // to read the entire file content at once.
#include <unordered_map> // Used to store N-grams efficiently
#include <vector> // Used to store a list of words after tokenization.
#include <algorithm> // find the most frequent next word.

using namespace std;

/* ---------------- TEXT PROCESSOR ---------------- */
class TextProcessor {
public:
    vector<string> tokenize(const string& text) {
        vector<string> words;
        string word;
        for (char ch : text) {
            if (isalnum(ch))
                word += tolower(ch);
            else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) // adds the last word
            words.push_back(word);
        return words;
    }
};

/* ---------------- N-GRAM MODEL ---------------- */
class NGramModel {
private:
    unordered_map<string, unordered_map<string, int>> bigram;
    unordered_map<string, unordered_map<string, int>> trigram;

public:
    void train(const vector<string>& words) {
        for (size_t i = 0; i + 1 < words.size(); i++) {
            bigram[words[i]][words[i + 1]]++;
        }

        for (size_t i = 0; i + 2 < words.size(); i++) {
            string key = words[i] + " " + words[i + 1];
            trigram[key][words[i + 2]]++;
        }
    }

    unordered_map<string, int> getBigram(const string& word) {
        return bigram[word];
    }

    unordered_map<string, int> getTrigram(const string& w1, const string& w2) {
        string key = w1 + " " + w2;
        return trigram[key];
    }
};

/* ---------------- PREDICTOR ---------------- */
class Predictor {
private:
    NGramModel& model;

public:
    Predictor(NGramModel& m) : model(m) {}

    void predictNextWords(const vector<string>& inputWords) {
    unordered_map<string, int> candidates;

    if (inputWords.size() >= 2) {
        candidates = model.getTrigram(
            inputWords[inputWords.size() - 2],
            inputWords[inputWords.size() - 1]
        );
    }

    if (candidates.empty() && !inputWords.empty()) {
        candidates = model.getBigram(inputWords.back());
    }

    if (candidates.empty()) {
        cout << "No prediction available\n";
        return;
    }

    vector<pair<string, int>> vec(candidates.begin(), candidates.end());

    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    cout << "Possible predictions:\n";
    for (auto &p : vec) {
        cout << p.first << endl;
    }
}

private:
    string getMaxFrequencyWord(const unordered_map<string, int>& freqMap) {
        return max_element(freqMap.begin(), freqMap.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            })->first;
    }
};

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    TextProcessor processor;
    NGramModel model;
    Predictor predictor(model);

    int choice;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Train model (manual input)\n";
        cout << "2. Predict next word\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter training text:\n";
            string text;
            getline(cin, text);

            vector<string> words = processor.tokenize(text);
            model.train(words);

            cout << "Model trained successfully!\n";
        }

        else if (choice == 2) {
            cout << "Enter a sentence: ";
            string input;
            getline(cin, input);

            vector<string> inputWords = processor.tokenize(input);
            predictor.predictNextWords(inputWords);
        }

        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
//to execute / compile
//g++ ngram.cpp -o ngram.exe  
//.\ngram.exe  
