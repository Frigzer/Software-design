#include "getRooms.h"
#include <fstream>
#include <iostream>
#include <string>
void rooms::getFromFile()
{
    string contents, line;
    fstream file;
    file.open("rooms.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            int flag=0;
            string o;
            char c;
            bool s;
            string num;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '/')
                {
                    flag++;
                }
                switch (flag)
                {
                case 0:
                    num += line[i];
                    break;
                case 1:
                    if (isdigit(line[i]))
                    {

                        o = line[i];
                    }
                    break;
                case 2:
                    if (isalnum(line[i]))
                    {
                        c = line[i];
                    }
                    break;
                case 3:
                    if (isalnum(line[i]))
                    {
                        if (line[i] == 'Y')
                        {
                            s = true;
                        }
                        else if (line[i] == 'N')
                        {
                            s = false;
                        }
                    }
                    break;

                }
                
            }
            rooms* newRoom = new rooms;
            newRoom->roomNumber = stoi(num);
            newRoom->occupants = stoi(o);
            newRoom->roomClass = c;
            newRoom->isForService = s;
            Rooms.push_back(newRoom);
        }
    }
    file.close();

}

void rooms::writeToFile()
{
    fstream file;
    file.open("rooms.txt", ios::out | ios::trunc);
    string text;
    for (int i = 0; i < Rooms.size(); i++)
    {
        text += to_string(Rooms[i]->roomNumber);
        text += "/";
        text += to_string(Rooms[i]->occupants);
        text += "/";
        text += Rooms[i]->roomClass;
        text += "/";
        if (Rooms[i]->isForService == true)
        {
            text += "Y";
        }
        else if (Rooms[i]->isForService == false)
        {
            text += "N";
        }
        text += "\n";

    }
    cout << text;
    file << text;
    file.close();

}

void rooms::modifyRooms()
{
    string continuation;
    do
    {
   
        int choice;
        cout << "would you like to modify room data or add a new room? 1 - modify   2 - add    3 - remove" << endl;
        cin >> choice;
        if (choice == 1)
        {
            Rooms.clear();
            rooms::getFromFile();
            for (int i = 0; i < Rooms.size(); i++)
            {
                cout << Rooms[i]->roomNumber;
                if (i < (Rooms.size() - 1))
                {
                    cout << " - ";
                }
            }
            bool correct = false;
            while(correct==false)
            {
                cout << endl << "which room would you like to modify: ";
                int number;
                cin >> number;

                for (int i = 0; i < Rooms.size(); i++)
                {
                    if (number == Rooms[i]->roomNumber)
                    {
                        correct = true;
                        cout << "Room number " << number << ":" << endl;
                        cout << "Maximum number of guests in the room: " << Rooms[i]->occupants << endl;
                        cout << "Room's standard: ";
                        switch (Rooms[i]->roomClass)
                        {
                        case 'S':
                            cout << "Standard";
                            break;
                        case 'P':
                            cout << "Penthouse";
                            break;
                        case 'L':
                            cout << "Luxury";
                            break;
                        }
                        cout << endl;
                        switch (Rooms[i]->isForService)
                        {
                        case true:
                            cout << "Room is up for service!";
                            break;
                        case false:
                            cout << "Room does not need service";
                            break;
                        }
                        cout << endl << endl;
                        int choiceOfParam = 0;
                        while (choiceOfParam == 0)
                        {
                            cout << "Select a parameter you would like to modify: 1 - max number of guests in the room   2 - room standard   3 - is room up for service" << endl;

                            cin >> choiceOfParam;
                            if (choiceOfParam == 1)
                            {
                                cout << "Specify the new maximum number of guests: ";
                                cin >> Rooms[i]->occupants;
                            }
                            else if (choiceOfParam == 2)
                            {
                            standard:
                                cout << "Select new standard: Standard     Penthouse     Luxury" << endl;
                                string newStandard;
                                cin >> newStandard;
                                if (newStandard == "Standard")
                                {
                                    Rooms[i]->roomClass = 'S';
                                }
                                else if (newStandard == "Penthouse")
                                {
                                    Rooms[i]->roomClass = 'P';
                                }
                                else if (newStandard == "Luxury")
                                {
                                    Rooms[i]->roomClass = 'L';
                                }
                                else
                                {
                                    cout << "Wrong word!" << endl;
                                    goto standard;
                                }

                            }
                            else if (choiceOfParam == 3)
                            {
                                if (Rooms[i]->isForService == true)
                                {
                                    Rooms[i]->isForService = false;
                                    cout << "Changed to: Room does not need service" << endl;
                                }
                                else
                                {
                                    Rooms[i]->isForService = true;
                                    cout << "Changed to: Room is up for service!" << endl;

                                }
                            }
                            else
                            {
                                cout << "this option does not exist!" << endl;
                            }
                        }
                    }
                }
                if (correct == false)
                {
                    cout << "choose a valid room number: " << endl;
                }
            }
            writeToFile();
        }
        else if (choice == 2)
        {
        Rooms.clear();
        rooms::getFromFile();
        rooms* newRoom = new rooms;
        int newNumber;
        begin:
        cout << endl << "Insert room number: ";
        cin >> newNumber;
        for (int i = 0; i < Rooms.size(); i++)
        {
            if (newNumber == Rooms[i]->roomNumber)
            {
                cout << "Room with that number already exists!";
                goto begin;
            }
        }
        newRoom->roomNumber = newNumber;
        cout << endl << "Specify the maximum number of guests: ";
        cin >> newRoom->occupants;
        standard1:
        cout << "Select standard: Standard     Penthouse     Luxury" << endl;
        string newStandard;
        cin >> newStandard;
        if (newStandard == "Standard")
        {
            newRoom->roomClass = 'S';
        }
        else if (newStandard == "Penthouse")
        {
            newRoom->roomClass = 'P';
        }
        else if (newStandard == "Luxury")
        {
            newRoom->roomClass = 'L';
        }
        else
        {
            cout << "Wrong word!" << endl;
            goto standard1;
        }
        newRoom->isForService = false;
        Rooms.push_back(newRoom);
        writeToFile();
        }
        else if (choice == 3)
        {
            Rooms.clear();
            rooms::getFromFile();
            int roomToDelete;
            static bool flag = false;
            begin1:
            for (int i = 0; i < Rooms.size(); i++)
            {
                cout << Rooms[i]->roomNumber;
                if (i < (Rooms.size() - 1))
                {
                    cout << " - ";
                }
            }
            cout << endl << "which room would you like to remove? ";
            cin >> roomToDelete;
            for (int i = 0; i < Rooms.size(); i++)
            {
                if (Rooms[i]->roomNumber == roomToDelete)
                {
                    Rooms.erase(Rooms.begin() + i);
                    rooms::writeToFile();
                    flag = true;
                }
            }
            if (flag == true);
            {
                Rooms.clear();
                rooms::getFromFile();
                cout << endl << "Room number: " << roomToDelete << " removed succesfully" << endl;
                for (int i = 0; i < Rooms.size(); i++)
                {
                    cout << Rooms[i]->roomNumber;
                    if (i < (Rooms.size() - 1))
                    {
                        cout << " - ";
                    }
                }
            }
            if (flag == false)
            {
                goto begin1;
            }
        }
        else
        {
            cout << "choose between 0 and 1" << endl;
        }
        cout << "Would you like to make any more changes? Y/N: ";
        cin >> continuation;
    }while (continuation == "Y" || continuation == "y");

}
