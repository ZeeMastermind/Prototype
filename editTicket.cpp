#include "editTicket.h"



editTicket::editTicket()
{
	ticket1 = Ticket();
	custNameForm = "";
	idForm = "";
	dateForm = "";
	dateForm = "";
	serialForm = "";
	modelForm = "";
	noteForm = "";
	noteDate = "";
}


editTicket::~editTicket()
{
}

//SETTERS
void editTicket::setID(string id)
{
	idForm = id;
}

void editTicket::setCustName(string name)
{
	this->custNameForm = name;
}

void editTicket::setDate(string date)
{
	this->dateForm = date;
}

void editTicket::setSerialNum(string serialNum)
{
	this->serialForm = serialNum;
}

void editTicket::setModelNum(string modelNum)
{
	this->modelForm = modelNum;
}

void editTicket::setNote(string note)
{
	this->noteForm = note;
}

void editTicket::setNoteDate(string date)
{
	this->noteDate = date;
}

//GETTERS
string editTicket::getId()
{
	return idForm;
}

string editTicket::getCustName()
{
	return custNameForm;
}

string editTicket::getDate()
{
	return dateForm;
}

string editTicket::getSerialNum()
{
	return serialForm;
}

string editTicket::getModelNum()
{
	return modelForm;
}

string editTicket::getNote()
{
	return noteForm;
}

string editTicket::getNoteDate()
{
	return noteDate;
}

//Create and sumbit ticket
void editTicket::makeTicket()
{
	ticket1.setCreationDate(dateForm);
	ticket1.setCustomerName(custNameForm);
	ticket1.setIsOpen(true);
	ticket1.setModelNumber(modelForm);
	ticket1.setSerialNumber(serialForm);
	ticket1.setTicketID(serialForm);

	Note newNote;
	newNote.note = getNote();
	newNote.date = getNoteDate();
	ticket1.addNote(newNote);
}

void editTicket::submitTicket()
{
	makeTicket();
	ticket1.saveToFile();
}

//Set ticket to closed
void editTicket::closeTicket()
{
	ticket1.setIsOpen(false);
}

//Read in a ticket and set form values to that ticket
void editTicket::readInTicket(string filename)
{
	ticket1.readFromFile(filename);
	setCustName(ticket1.getCustomerName());
	setDate(ticket1.getCreationDate());
	setID(ticket1.getTicketID());
	setModelNum(ticket1.getModelNumber());
	setSerialNum(ticket1.getModelNumber());
}

void editTicket::displayTicket()
{
	cout << ticket1.getTicket() << endl;
}
