//
// Created by roi on 1/18/23.
//

#include "CLI.h"

/**
 * Constructor takes default io and fills command vectors with current commands.
 * @param dio is the default io
 */
CLI::CLI(DefaultIO *dio){
    this->dio = dio;
    Upload upload = Upload(getDio());
    this->commands.push_back(&upload);
    Settings settings = Settings(getDio());
    this->commands.push_back(&settings);
    Classify classify = Classify(getDio());
    this->commands.push_back(&classify);
    Display display = Display(getDio());
    this->commands.push_back(&display);
    Download download = Download(getDio());
    this->commands.push_back(&download);
    Exit exit = Exit(getDio());
    this->commands.push_back(&exit);
}

vector<Command *> CLI::getCommands() {
    return this->commands;
}

DefaultIO *CLI::getDio() {
    return this->dio;
}
/**
 * The start method initiates the interaction between the client and server,
 * and is responsible for the flow of the interaction between client and server.
 * When the connection ends and the user decides to exit it ends.
 */
void CLI::start() {
    string menu;
    for(auto command : getCommands()){
        menu.append(command->getDescription());
        menu.append("\n");
    }
    getDio()->write(menu);
    string option;
    while(true){
        option = getDio()->read();
        if(!isInt(option)){
            dio->write("Invalid option!\n");
            continue;
        }
        int optionNum = stoi(option);
        vector<int> validOptions = {1, 2, 3, 4, 5, 8};
        if(!isContained(validOptions, optionNum)){
            dio->write("Invalid option!\n");
            continue;
        }
        if(optionNum == 8){
            getCommands().at(optionNum - 1)->execute();
            break;
        }
        getCommands().at(optionNum - 1)->execute();
    }
}