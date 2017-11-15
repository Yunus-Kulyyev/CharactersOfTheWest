#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

class person
{
public:

    string firstName;
    string lastName;

    person()
    {
        firstName="NULL";
        lastName="NULL";
    }

    void namePerson()
    {
        cout<<"Please enter the first name: ";
        cin>>firstName;
        cout<<"Please enter the last name: ";
        cin>>lastName;
        cout<<endl;
    }

    void showName()
    {
        cout<<"First Name: "<<firstName<<endl<<"Last Name: "<<lastName<<endl;
    }
};

class gunslinger: public virtual person
{
public:
    double drawTime;
    int notches;

    gunslinger()
    {
        srand(time(NULL));
        drawTime=rand()%2;
        notches = 0;
    }

    void show()
    {
        cout<<"Gunslinger's draw time: "<<drawTime<<endl;
        cout<<"Number of notches on gun: "<<notches<<endl;
    }
};

class pokerplayer: public person
{
public:

    int card;

    pokerplayer()
    {
        srand(time(NULL));
        card = rand()%53;
        card = card+1;
    }

    void showCard()
    {
        cout<<"The card value is: "<<card<<endl;
    }

};


int main()
{
    gunslinger shooter;
    pokerplayer player;
    int option = 0;
    char letter;

    cout<<"Enter the person category: "<<endl<<"1. Gunslinger"<<endl<<"2. Poker Player"<<endl;
    cin>>option;

    while (option == 1 || option == 2)
    {
        if (option == 1)
        {
            shooter.namePerson();
            shooter.showName();
            shooter.show();
        }
        else if (option == 2)
        {
            player.namePerson();
            player.showName();
            player.showCard();
        }

        cout<<"Do you want to repeat? Y/N"<<endl;
        cin>>letter;
        if (letter == 'y' || letter == 'Y')
        {
            cout<<"Enter the person category: "<<endl<<"1. Gunslinger"<<endl<<"2. Poker Player"<<endl;
            cin>>option;
        }
        else if (letter != 'y' || letter != 'Y')
        {
            option = 0;
        }
    }

    return 0;
}
