//
// Created by roi on 1/19/23.
//

#include "Utilities.h"
/**
 * checks if passed string is numerical, if it is returns true.
 * @param str string to check
 * @return true if numeric, false if not
 */
bool isInt(string str) {
    int iter = 0;
    for (auto c: str) {
        if(!isdigit(c) && !(c == '-' && iter == 0)){
            return false;
        }
        iter++;
    }
    return true;
}

bool isNumeric(const string& str) {
    int pointCount = 0, iterCount = 0, length = str.length(), exponentCount = 0, signCount = 0, exponentPosition;
    for (auto c: str) {
        if (c == '.' && pointCount == 0 && 0 <= iterCount && iterCount < length - 1) {
            pointCount++;
        } else if (c == 'E' && exponentCount == 0 && 0 < iterCount && iterCount < length - 1){
            exponentPosition = iterCount;
            exponentCount++;
        } else if (c == '-' && signCount < 2 && (iterCount == 0 || iterCount == exponentPosition + 1)){
            signCount++;
        } else if (!isdigit(c)) {
            return false;
        }
        iterCount++;
    }
    return true;
}

/**
 * Checks if a number is contained in a vector.
 * @param numVector is the vector
 * @param num is the number
 * @return true if number is in vector
 */
bool isContained(vector<int> numVector, int num){
    for(auto x: numVector){
        if(num == x){
            return true;
        }
    }
    return false;
}
/**
 * Validates distance type setting
 * @param type is the type
 * @return returns true if is of valid type
 */
bool checkMetric(const string& type){
    // validate distance
    if  (!type.empty() &&
        (type != "AUC") && (type != "MAN") &&
        (type != "CHB") && (type != "CAM") &&
        (type != "MIN")) {
        return false;
    }
    return true;
}
/**
 * Checks if a string is a of classified vector type , e.g (x1, x2, x3, classification)
 * @param elements are the elements concatenated to a string
 * @return true if is of type classified vector, otherwise false
 */
bool checkClassifiedVec(const string& elements){
    if (elements.empty()){return false;}
    stringstream ss(elements);
    string element;
    bool classFlag = false;
    int iter = 0, decPointCount = 0;
    while(getline(ss, element, ' ')){
        for (auto x: element) {
            if (!isdigit(x) && x != '.' && iter != 0) {
                classFlag = true;
            } else if(!isdigit(x) && x == '.' && decPointCount == 0){
                decPointCount++;
            } else if(!isdigit(x) && decPointCount > 1){
                return false;
            }
        }
        if (classFlag) { break; }
        iter++;
    }
    if (element.empty()) {return false;}
    getline(ss, element, ' ');
    if(ss.eof()){
        return true;
    } else {
        return false;
    }
}

/**
 * Reads all data from file and returns it as a string
 * @param path is the file path to read from
 * @return is the string to return
 */
string readFile(string path){
    ifstream inputFile;
    inputFile.open(path);
    // try to open file with stream
    if (!inputFile.is_open()) {
        return "invalid input";
    }
    string line, output;
    while(getline(inputFile, line)){
        if(!line.empty() && line.back() == '\r'){
            line.pop_back();
            output.append(line);
            output.append("\n");
        } else {
            output.append(line);
            output.append("\n");
        }
    }
    return output;
}
/**
 * Writes to data to file and saves to a certain path
 * @param path
 */
void writeFile(string toWrite, string path){
    ofstream file(path);
    if (!file.is_open()) {
        return;
    }
    file << toWrite;
    file.close();
}

bool checkVectors(vector<Classified> train, vector<vector<double>> test) {
    unsigned long size = train[0].getVector().size();
    for (Classified vector: train) {
        if (vector.getVector().size() != size) {
            return false;
        }
    }
    for (const vector<double>& vector: test) {
        if (vector.size() != size) {
            return false;
        }
    }
    return true;
}