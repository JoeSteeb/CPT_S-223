#include <map>
#include "TwitterData.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    std::map<string, TwitterData> Map;
    std::map<string, TwitterData> Map2;

    for (int i = 0; i < 5; i++)
    {
        Map[twitter_data[i].getActualName()] = twitter_data[i];
    }

    cout << '\n'
         << "map1: " << '\n';

    //print key values

    cout << '\n'
         << "printing every element: " << '\n';

    for (auto element : Map)
    {
        cout << "key = " << element.first << "\n";
        cout << "value = " << element.second.print() << '\n';
    }

    cout << '\n'
         << "printing data of user savage1: " << '\n';

    for (auto element : Map)
    {
        if (element.second.getUserName() == "savage1")
            cout << element.second.print() << '\n';
    }

    cout << '\n'
         << "map2: " << '\n';

    for (int i = 0; i < 5; i++)
    {
        Map2[twitter_data[i].getEmail()] = twitter_data[i];
    }

    //print key values

    cout << '\n'
         << "printing every element: " << '\n';

    for (auto element : Map2)
    {
        cout << "key = " << element.first << "\n";
        cout << "value = " << element.second.print() << '\n';
    }

    cout << '\n'
         << "printing data of user with email kat@gmail.com: " << '\n';

    for (auto element : Map2)
    {
        if (element.first == "kat@gmail.com")
            cout << element.second.print() << '\n';
    }

    Map2.erase("kat@gmail.com");

    cout << '\n';

    return 0;
}