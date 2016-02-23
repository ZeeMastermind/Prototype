#ifndef EDITTICKET_H
#define EDITTICKET_H
#include "ticket.h"

class editTicket
{

private: //Forms for all data and a Ticket object that is the ticket being edited 
	Ticket ticket1;
	string custNameForm;
	string idForm;
	string dateForm;
	string serialForm;
	string modelForm;
	string noteForm;
	string noteDate;

public:
	editTicket();
	~editTicket();
	//getters for form data
	string getId();
	string getCustName();
	string getDate();
	string getSerialNum();
	string getModelNum();
	string getNote();
	string getNoteDate();

	//setters for form data
	void setID(string id);
	void setCustName(string name);
	void setDate(string date);
	void setSerialNum(string serialNum);
	void setModelNum(string modelNum);
	void setNote(string note);
	void setNoteDate(string date);

	//Create/submit
	void makeTicket();
	void submitTicket();

	//Close a ticket
	void closeTicket();

	//Read in ticket and set form variables to that ticket
	void readInTicket(string filename);
	void displayTicket();

};

#endif

