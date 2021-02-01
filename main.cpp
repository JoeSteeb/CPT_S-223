#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "node.h"
#include "linkedList.h"

int menu();
void printRules();
//TODO: Template the templates
void addCommand(linkedList<std::string, std::string> &Storage);
void removeCommand(linkedList<std::string, std::string> &Storage);
void printList(linkedList<std::string, std::string> Storage);
void writeChanges(node<std::string, std::string> *writtenNode);
void gamePlay(linkedList<std::string, std::string> Storage, int &score);
void writeNode(node<std::string, std::string> *writtenNode, std::ofstream &writeFile);
void printArray(node<std::string, int> *profileStorage[], int size, int &score, int &currentPlayer);
void addUser(node<std::string, int> *profileStorage[], int size, int score);
void writeUsers(node<std::string, int> *profileStorage[], int size, int score, int &currentPlayer);

node<std::string, std::string> *getRandomNode(linkedList<std::string, std::string> Storage);

int main()
{
    srand(time(0));
    linkedList<std::string, std::string> commandStorage;
    std::string currentName;
    int currentPlayer = -1;
    int currentScore = 0;
    bool exit = false;
    bool loaded = false;

    std::ifstream infile("../commands.csv");

    //Loading commands to list
    while (infile.good())
    {
        std::string command;
        std::string definition;

        getline(infile, command, ',');     //commands and definitions seperated by a comma
        getline(infile, definition, '\n'); //each pair has it's own line so they are seperated by \n

        commandStorage.addNode(new node<std::string, std::string>(command, definition));
    }
    infile.close();

    int length;
    std::string input;
    std::ifstream infile2("../profiles.csv");

    getline(infile2, input, '\n');
    std::stringstream convert(input);
    convert >> length;

    //storage array for profiles
    node<std::string, int> *profileStorage[length + 1]; //+1 to make space for current users save

    for (int i = 0; i < length; i++)
    {
        std::string name;
        std::string scoreString;
        int score;

        getline(infile2, name, ',');
        getline(infile2, scoreString, '\n');
        std::stringstream convert2(scoreString);
        convert2 >> score;

        profileStorage[i] = new node<std::string, int>(name, score);
    }

    //std::cout << "length:" << commandStorage.getLength() << std::endl;
    std::cout << "Welcome to Linux Command Learner \n";

    //main loop
    while (!exit)
    {
        //menu selection
        switch (menu())
        {
        case 1:
            printRules();
            break;
        case 2:
            gamePlay(commandStorage, currentScore);
            break;
        case 3:
            printArray(profileStorage, length, currentScore, currentPlayer);
            loaded = true;
            break;
        case 4:
            addCommand(commandStorage); //most of these functions are not necessary,
            length++;                   //but I think they make the code more readable.
            break;
        case 5:
            removeCommand(commandStorage);
            break;
        case 6:
            writeChanges(commandStorage.getHead());
            if (!loaded)
            {
                addUser(profileStorage, length + 1, currentScore);
                length++;
            }
            writeUsers(profileStorage, length, currentScore, currentPlayer);
            commandStorage.deleteList(commandStorage.getHead());
            exit = true;
            break;
        case 7:
            printList(commandStorage);
            break;
        }
    }
}

int menu()
{
    int selection;
    std::cout << "To select an option press the coresponding number on the keyboard \n";
    std::cout << "1. Game Rules \n";
    std::cout << "2. Play Game \n";
    std::cout << "3. Load Game \n";
    std::cout << "4. Add Command \n";
    std::cout << "5. Remove Command \n";
    std::cout << "6. Exit \n";
    std::cout << "7. Print List \n";

    std::cin >> selection;
    std::cin.ignore();

    return selection;
}

void printRules()
{
    std::cout << "Rules: \n";
    std::cout << "The objective of the game is to match the given linux command with the correct explanation";
    std::cout << "points are gained by selecting the correct answer points are lost if the answer is incorrect";
}

void gamePlay(linkedList<std::string, std::string> Storage, int &score)
{
    bool exit = false;
    int length;

    std::cout << "Pleas enter a number between 5 and 30 to determine the amount of questions \n";
    std::cin >> length;
    std::cin.ignore();

    //game loop: terminates upon selected number of questions or
    //upon entering the exit key
    for (int i = 0; i < length && !exit; i++)
    {
        node<std::string, std::string> *current = getRandomNode(Storage);
        std::cout << "Score: " << score << '\n';
        std::cout << current->getCommand() << ':' << '\n';
        int correctAnswer = rand() % 2 + 1;

        for (int j = 1; j <= 3; j++)
        {
            std::cout << j << ". ";
            if (j == correctAnswer)
                std::cout << current->getDefinition();
            else
            {
                node<std::string, std::string> *temp;
                temp = getRandomNode(Storage);
                if (temp == current)
                {
                    if (temp->getNext() != NULL)
                        temp = temp->getNext();
                    else
                        temp = Storage.getHead();
                }

                std::cout << temp->getDefinition();
            }
            std::cout << '\n';
        }

        std::cout << "4. exit" << '\n';
        int userInput;
        std::cin >> userInput;
        std::cin.ignore();

        if (userInput == correctAnswer)
        {
            score++;
            std::cout << "Correct!" << '\n';
        }
        else if (userInput == 4)
            break;
        else
        {
            score--;
            std::cout << "Incorrect" << '\n';
        }
    }
}
node<std::string, std::string> *getRandomNode(linkedList<std::string, std::string> Storage)
{
    node<std::string, std::string> *current = Storage.getHead();

    for (int i = 0; i < rand() % Storage.getLength(); i++)
    {
        current = current->getNext();
    }
    return current;
}

void addCommand(linkedList<std::string, std::string> &Storage)
{
    std::string addedCommand;
    std::string addedDefinition;
    std::cout << "Enter a command to be added \n";
    std::getline(std::cin, addedCommand);
    std::cout << "Enter the description for the added command \n";
    std::getline(std::cin, addedDefinition);
    Storage.addNode(new node<std::string, std::string>(addedCommand, addedDefinition));
}

void removeCommand(linkedList<std::string, std::string> &Storage)
{
    std::string removed;
    std::cout << "Enter a command to be removed \n";
    std::cin >> removed;
    std::cin.ignore();
    Storage.removeNode(removed);
}

//outputs commands, and any changes to commands.csv
void writeChanges(node<std::string, std::string> *writtenNode)
{
    std::ofstream writeFile;
    writeFile.open("../commands.csv");
    writeNode(writtenNode, writeFile);
    writeFile.close();
}

//I made this recursive method to not reverse command order when writing to file
//not necissary, but it keeps things nicely organized.
void writeNode(node<std::string, std::string> *writtenNode, std::ofstream &writeFile)
{
    if (writtenNode->getNext() != NULL)
    {
        writeNode(writtenNode->getNext(), writeFile);
        writeFile << '\n';
    }
    writeFile << writtenNode->getCommand() << ',';
    writeFile << writtenNode->getDefinition();
}

void printArray(node<std::string, int> *profileStorage[], int size, int &score, int &currentPlayer)
{
    std::cout << "Input the coresponding number for the user you would like to choose" << '\n';

    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". ";
        std::cout << profileStorage[i]->getCommand() << ',';
        std::cout << profileStorage[i]->getDefinition() << '\n';
    }

    int selection;
    std::cin >> selection;
    currentPlayer = selection;
    score = profileStorage[selection - 1]->getDefinition();
}

void addUser(node<std::string, int> *profileStorage[], int size, int score)
{
    std::string username;
    std::cout << "enter a username";
    std::cin >> username;

    profileStorage[size - 1] = new node<std::string, int>(username, score);
}

void writeUsers(node<std::string, int> *profileStorage[], int size, int score, int &currentPlayer)
{
    if (currentPlayer > -1)
        profileStorage[currentPlayer - 1]->setDefinition(score);

    std::ofstream writeFile2;
    writeFile2.open("../profiles.csv");
    writeFile2 << size << '\n';

    for (int i = 0; i < size; i++)
    {
        writeFile2 << profileStorage[i]->getCommand() << ',';
        writeFile2 << profileStorage[i]->getDefinition();
        if (i < size - 1)
            writeFile2 << '\n';
    }
    writeFile2.close();
}

void printList(linkedList<std::string, std::string> Storage)
{
    node<std::string, std::string> *current = Storage.getHead();

    while (current != NULL)
    {
        std::cout << current->getCommand() << '\n';
        std::cout << current->getDefinition() << '\n';

        current = current->getNext();
    }
}