#include "Book.h"
#include <algorithm>
#include <string>
#include <regex>
#include <list>

using namespace std;

Book::Book(const string& filepath) {
    // Open the file at the specified filepath
    ifstream file(filepath);

    // Check if the file is successfully opened
    if (file.is_open()) {
        // Read the entire content of the file into a stringstream
        stringstream buffer;
        buffer << file.rdbuf();
        content = buffer.str();
        file.close();

        // Transform the content to lowercase
        transform(content.begin(), content.end(), content.begin(), ::tolower);

        // Replace consecutive whitespaces with a single space using regular expressions
        regex pattern("\\s+"); // Matches one or more whitespace characters
        content = regex_replace(content, pattern, " ");

        // Insert content into the trie
        processContent();
    }
    else {
        // If the file fails to open, throw an exception
        throw invalid_argument("Unable to open file");
    }
}

void Book::processContent() {
    istringstream stream(content);
    // TODO: Go over the book content and add any triplet of consecutive words to the trie.
    // Assume the words are separated by spaces.
    Trie* trie = new Trie;
    // separte content into words
    string word1;
    string word2;
    string word3;
    stream >> word1;
    stream >> word2;
    int offset = 0;
    while (stream >> word3) {
		// add word1, word2, word3 to trie
		trie->insert(word1 + " " + word2 + " " + word3, offset);
		word1 = word2;
		word2 = word3;
        offset += word1.length() + 1;
	}
    this->trie = trie;
}


void Book::searchAndPrint(const string& query) {
    // TODO: Use the trie to find the locations of the string (At most 3 sentences)
    list<int> locations = trie->search(query);
    // TODO: For each location, use the extractSentence function to extract the sentence in that location
    list<string> sentences;
    for (int location : locations) {
		sentences.push_back(extractSentence(location));
	}

    if (locations.empty()) {
        cout << "No results" << endl;
        return;
    }

    cout << "Sentences matching the prefix:" << endl;

    // TODO: Print each sentence
    for (string sentence : sentences) {
        cout << sentence << endl;
    }    

}

string Book::extractSentence(int location) {
    // TODO: Go over the characters of the content from the location backwards until finding a '.' or until accumulating 5 words.
    
    int start = location;
    int end = location;

    bool begginingCut = true;
    bool endCut = true;

    int words = 0;
    while (start > 0 && words < 5) {
		if (content[start] == ' ') {
			words++;
		}
		if (content[start] == '.') {
            begginingCut = false;
            start++;
			break;
		}
		start--;
	}
    if (words == 5) {
		start+= 2;
	}
    // TODO: Go over the characters of the content from the location forwards until finding a '.' or until accumulating a total of 10 words.

    while (end < content.length() && words < 11) {
        if (content[end] == ' ') {
            words++;
		}
        if (content[end] == '.') {
            endCut = false;
            break;   
        }
        end++;
    }
    if (words == 11) {
		end--;
	}
    // TODO: Assemble the sentence by adding the two parts with a '*' marker for the location and '...' if the sentence was cut.

    string sentence = content.substr(start, end - start);
    sentence = sentence.substr(0, location - start) + "*" + sentence.substr(location - start);
    if (begginingCut) {
		sentence = "..." + sentence;
	}
    if (endCut) {
        sentence = sentence + "...";
    }
    
    return sentence;
}

void Book::censorQuery(const string& query) {
    //TODO: remove the query from the trie (mark it as a non end-of-word)
    trie->remove(query);
}
