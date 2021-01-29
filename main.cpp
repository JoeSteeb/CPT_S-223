#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "node.h"
#include "linkedList.h"

struct player
{
    std::string name;
    int score;
};

int menu();
void printRules();
//TODO: Template the templates
void addCommand(linkedList<std::string, std::string> &Storage);
void removeCommand(linkedList<std::string, std::string> &Storage);
void printList(linkedList<std::string, std::string> Storage);
void writeChanges(node<std::string, std::string> *writtenNode);
void gamePlay(linkedList<std::string, std::string> Storage, int &score);
void writeNode(node<std::string, std::string> *writtenNode, std::ofstream &writeFile);
node<std::string, std::string> *getRandomNode(linkedList<std::string, std::string> Storage);

int main()
{
    srand(time(0));
    linkedList<std::string, std::string> commandStorage;
    std::string currentName;
    int currentScore = 0;
    bool exit = false;

    std::ifstream commands("../commands.csv");

    std::string command;
    std::string definition;

    //Loading commands to list
    while (commands.good())
    {
        getline(commands, command, ',');     //commands and definitions seperated by a comma
        getline(commands, definition, '\n'); //each pair has it's own line so they are seperated by \n
        commandStorage.addNode(new node<std::string, std::string>(command, definition));
    }

    commands.close();

    std::cout << "length:" << commandStorage.getLength() << std::endl;
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
            // Load
            break;
        case 4:
            addCommand(commandStorage); //most of these functions are not necisary,
            break;                      //but I think they make the code more readable.
        case 5:
            removeCommand(commandStorage);
            break;
        case 6:
            writeChanges(commandStorage.getHead());
            exit = true;
            break;
        case 7:
            printList(commandStorage);
        }
    }
}

int menu()
{
    int selection;
    std::cout << "To select an option press the corisponding number on the keyboard \n";
    std::cout << "1. Game Rules \n";
    std::cout << "2. Play Game \n";
    std::cout << "3. Load Previous Game \n";
    std::cout << "4. Add Command \n";
    std::cout << "5. Remove Command \n";
    std::cout << "6. Exit \n";
    std::cout << "7. Print List \n";

    std::cin >> selection;
    std::cin.ignore();

    return selection;
}
void writeNode(node<std::string, std::string>);

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

    std::cout << "Pleas enter a number between 5 and 30 to determine the ammount of questions \n";
    std::cin >> length;
    std::cin.ignore();

    //game loop: terminates upon selected number of questions or
    //apon entering the exit key
    for (int i = 0; i < length && !exit; i++)
    {
        node<std::string, std::string> *current = getRandomNode(Storage);
        std::cout << "Score: " << score << '\n';
        std::cout << current->getCommand() << ':' << '\n';
        int correctAnswer = rand() % 2;

        for (int j = 0; j < 3; j++)
        {
            std::cout << j << ". ";
            if (j == correctAnswer)
                std::cout << current->getDefinition();
            else
                std::cout << getRandomNode(Storage)->getDefinition();
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

    for (int i = 1; i < rand() % Storage.getLength(); i++)
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
    std::cout << "Enter the discription for the added command \n";
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

//outputs commands, and any changes to commands.csv
void writeChanges(node<std::string, std::string> *writtenNode)
{
    std::ofstream writeFile;
    writeFile.open("../commands.csv");
    writeNode(writtenNode, writeFile);
    writeFile.close();
}

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