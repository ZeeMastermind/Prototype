#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <direct.h>

using namespace std;

struct Note
{
    string note;
    string date;
};

class Ticket
{
    public:
        Ticket(string customerName, string ticketID, string creationDate, string serialNumber, string modelNumber, bool isOpen, Note note);
        virtual ~Ticket();

        //File savers/readers
        void saveToFile();
        void readFromFile(string fileName);

        //setters
        void setCustomerName(string customerName);
        void setTicketID(string ticketID);
        void setCreationDate(string creationDate);
        void setSerialNumber(string serialNumber);
        void setModelNumber(string modelNumber);
        void setIsOpen(bool isOpen);

        //setters for notes
        void clearNotes();
        void addNote(Note note);

        //getters
        string getCustomerName();
        string getTicketID();
        string getCreationDate();
        string getSerialNumber();
        string getModelNumber();
        bool getIsOpen();

        //getters for notes
        Note* getNotes();
        Note getNoteAt(int index);

        //Full text getter, used for saving to files
        string getTicket();

    protected:
    private:
        //variables
        string customerName;
        string ticketID;
        string creationDate;
        string serialNumber;
        string modelNumber;
        bool isOpen;
        Note *notes; //Number of notes may change
        int maximumNotes = 100; //Maximum notes on a ticket is 100
        int noteIndex = 0; //Important for keeping track of notes

};

#endif // TICKET_H
