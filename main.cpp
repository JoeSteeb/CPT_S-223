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
void addCommand(linkedList<std::string, std::string> Storage);
void removeCommand(linkedList<std::string, std::string> Storage);
void gamePlay(linkedList<std::string, std::string> Storage, int& score);
node<std::string, std::string> *getRandomNode(linkedList<std::string, std::string> Storage);

int main()
{
    srand(time(0));
    linkedList<std::string, std::string> storage;
    std::string currentName;
    int currentScore = 0;
    bool exit = false;
    
    std::ifstream commands("../commands.csv");

    std::string command;
    std::string definition;
    
    //Loading commands to list
    while(commands.good())
    {
        getline(commands, command, ','); //commands and definitions seperated by a comma
        getline(commands, definition, '\n'); //each pair has it's own line so they are seperated by \n
        storage.addNode(new node<std::string, std::string>(command, definition));
    }

/*  node<std::string, std::string> *current = storage.getHead();

    while(current != NULL)
    {
        std::cout << current->getCommand();
        std::cout << current->getDefinition() << std::endl;

        current = current->getNext();
    }
*/
    std::cout << "length:" << storage.getLength() << std::endl;
    std::cout << "Welcome to Linux Command Learner \n";

    //main loop
    while(!exit)
    {
        //menu selection
        switch(menu())
        {
            case 1:
                printRules();
                break;
            case 2:
                gamePlay(storage, currentScore);
                break;
            case 3:
                // Load
                break;
            case 4:
                addCommand(storage);
                break;
            case 5:
                removeCommand(storage);
                break;
            case 6:
                exit = true;
                break;

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

    std::cin >> selection;

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

    std::cout << "Pleas enter a number between 5 and 30 to determine the ammount of questions \n";
    std::cin >> length;

    for(int i = 0; i < length && !exit; i++)
    {
        node<std::string, std::string> *current = getRandomNode(Storage);
        std::cout << "Score: " << score << '\n';
        std::cout << current->getCommand() << ':' << '\n';
        int correctAnswer = rand() % 2;

        for(int j = 0; j < 3; j++)
        {
            std::cout << j << '.';
            if(j == correctAnswer)
                std::cout << current->getDefinition();
            else
                std::cout << getRandomNode(Storage)->getDefinition(); 
            std::cout << '\n';
        }
        
        //std::cout << "teenis teenis teenis teenis teenis teenis";
        int userInput;
        std::cin.ignore(80, '\n');
        std::cin >> userInput;

        if(userInput == correctAnswer)
        {
            score++;
            std::cout << "Correct!" << '\n';
        }
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

    for(int i = 1; i <  rand() % Storage.getLength(); i++)
    {
        current = current->getNext();
    }
    return current;
}

void addCommand(linkedList<std::string, std::string> Storage)
{
    std::string addedCommand;
    std::string addedDefinition;
    std::cout << "Enter a command to be added";
    std::cin >> addedCommand;
    std::cout << "Enter the discription for the added command";
    std::cin >> addedDefinition;
    Storage.addNode(new node<std::string, std::string>(addedCommand, addedDefinition));
}

void removeCommand(linkedList<std::string, std::string> Storage)
{
    std::string removed;
    std::cout << "Enter a command to be removed";
    std::cin >> removed;
    Storage.removeNode(removed);
}