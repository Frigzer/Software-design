#include "getRooms.h"
#include <fstream>
#include <string>
void rooms::getFromFile()
{
    string contents, line;
    fstream file;
    file.open("rooms.txt");
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            int flag=0;
            int o;
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
                    if (isalnum(line[i]))
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
            newRoom->occupants = o;
            newRoom->roomClass = c;
            newRoom->isForService = s;
            Rooms.push_back(newRoom);
        }
    }

}