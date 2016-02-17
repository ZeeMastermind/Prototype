#include "Ticket.h"


Ticket::Ticket(string customerName, string ticketID, string creationDate, string serialNumber, string modelNumber, bool isOpen, Note note)
{
    //ctor
    this->customerName = customerName;
    this->ticketID = ticketID;
    this->creationDate = creationDate;
    this->serialNumber = serialNumber;
    this->modelNumber = modelNumber;
    this->isOpen = isOpen;
    notes = new Note[100];
    addNote(note);
}

Ticket::~Ticket()
{
    //dtor
    delete notes;
}

void Ticket::saveToFile()
{
    string fileName = "ticket_" + ticketID + ".txt";

    ofstream myFile;
    myFile.open(fileName);

    myFile << getTicket();

    myFile.close();
}

void Ticket::readFromFile(string fileName)
{
    noteIndex = 0;

    string line;
    bool isTicket = false;
    int lineCount = 0;
    int index = 0;
    int noteTotal = 0;
    bool goodReturn = false;
    string tempNote;
    string tempDate;

    ifstream myFile;
    myFile.open(fileName);

    if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
            if (line == "TICKET_START")
            {
                //checks if the file is a ticket
                isTicket = true;
            }
            if (line == "TICKET_END")
            {
                isTicket = false;
                goodReturn = true;
            }
            if (isTicket) //will only run if file is a ticket
            {
                //Checks if in a note
                if (line == "NOTES_START")
                {
                    index = 1;
                }
                if (line == "NOTE_START")
                {
                    index = 2;
                }
                if (line == "NOTE_END")
                {
                    Note newNote;
                    newNote.note = tempNote;
                    newNote.date = tempDate;
                    addNote(newNote);

                    index = 1;
                    noteTotal++;
                }
                if (line == "NOTES_END")
                {
                    index = 0;
                }

                //Data for notes
                if (index > 0)
                {
                    if (index == 3)
                    {
                        tempDate = line;
                        index = 4;
                    }
                    if (index == 2)
                    {
                        tempNote = line;
                        index = 3;
                    }

                }
                else //Each line number is associated with a different variable, as shown below.
                {
                    if (lineCount == 1)
                    {
                        customerName = line;
                    }
                    if (lineCount == 2)
                    {
                        ticketID = line;
                    }
                    if (lineCount == 3)
                    {
                        creationDate = line;
                    }
                    if (lineCount == 4)
                    {
                        serialNumber = line;
                    }
                    if (lineCount == 5)
                    {
                        modelNumber = line;
                    }
                    if (lineCount == 6)
                    {
                        if (line == "true")
                        {
                            isOpen = true;
                        }
                        else if (line == "false")
                        {
                            isOpen = false;
                        }
                    }

                }

            }

            lineCount++;
		}
		myFile.close();
	}

	if (goodReturn)
    {
        cout << "Ticket read successfully." << endl;
    }
    else
    {
        cout << "Ticket did not read successfully." << endl;
    }

}

void Ticket::setCustomerName(string customerName)
{
    this->customerName = customerName;
}

void Ticket::setTicketID(string ticketID)
{
    this->ticketID = ticketID;
}

void Ticket::setCreationDate(string creationDate)
{
    this->creationDate = creationDate;
}

void Ticket::setSerialNumber(string serialNumber)
{
    this->serialNumber = serialNumber;
}

void Ticket::setModelNumber(string modelNumber)
{
    this->modelNumber = modelNumber;
}

void Ticket::setIsOpen(bool isOpen)
{
    this->isOpen = isOpen;
}

void Ticket::clearNotes()
{
    noteIndex = 0;
}

void Ticket::addNote(Note note)
{
    notes[noteIndex] = note;
    noteIndex++;
}

string Ticket::getCustomerName()
{
    return customerName;
}

string Ticket::getTicketID()
{
    return ticketID;
}

string Ticket::getCreationDate()
{
    return creationDate;
}

string Ticket::getSerialNumber()
{
    return serialNumber;
}

string Ticket::getModelNumber()
{
    return modelNumber;
}

bool Ticket::getIsOpen()
{
    return isOpen;
}

Note* Ticket::getNotes()
{
    return notes;
}

Note Ticket::getNoteAt(int index)
{
    if (index < noteIndex)
    {
        return notes[index];
    }
    else
    {
        cout << "Note not found. Returning note at index 0." << endl;
        return notes[0];
    }
}

string Ticket::getTicket()
{
    string ticketFull = "";
    ticketFull += "TICKET_START\n"; //starts ticket

    ticketFull += customerName + "\n"; //enters basic variables
    ticketFull += ticketID + "\n";
    ticketFull += creationDate + "\n";
    ticketFull += serialNumber + "\n";
    ticketFull += modelNumber + "\n";
    if (isOpen)
        ticketFull += "true\n";
    else
        ticketFull += "false\n";

    ticketFull += "NOTES_START\n"; //Starts notes
    int i = 0;
    while (i < noteIndex)
    {
        ticketFull += "NOTE_START\n"; //details of each note
        ticketFull += notes[i].note + "\n";
        ticketFull += notes[i].date + "\n";
        ticketFull += "NOTE_END\n";
        i++;
    }
    ticketFull += "NOTES_END\n"; //ends notes and ticket
    ticketFull += "TICKET_END";

    return ticketFull;
}
