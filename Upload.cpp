//
// Created by alik on 1/18/23.
//

#include "Upload.h"

Upload::Upload(DefaultIO *dio) : Command(dio) {
    this->description = "1. upload an unclassified csv data file";
}
void Upload::execute() {

}
