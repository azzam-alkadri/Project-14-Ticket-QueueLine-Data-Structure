

#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<queue>
#include<string>
#include <ctime>
#include <stack>

using namespace std;

class clsQueueLine
{
public:

    class clsTicket
    {
    private:
        string _TicketNumber;
        string _DateTime;
        int _WaitingClients;

    public:
        clsTicket(string TicketNumber, string DateTime, int WaitingClients)
        {
            _TicketNumber = TicketNumber;
            _DateTime = DateTime;
            _WaitingClients = WaitingClients;
        }
        string GetTicketNumber()
        {
            return _TicketNumber;
        }

        string GetDateTime()
        {
            return _DateTime;
        }

        int GetWaitingClients()
        {
            return _WaitingClients;
        }
       
    };

    clsQueueLine(string Prefix, int ServiceTime)
    {
        _Prefix = Prefix;
        _ServiceTime = ServiceTime;
        _TotalTickets = 0;
        _ServedClients = 0;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        string TicketNumber = _Prefix + to_string(_TotalTickets);
        int WaitingClients = _Queue.size();
        time_t CurrentTime = time(0);
        clsTicket Ticket(TicketNumber, ctime(&CurrentTime), WaitingClients);
        _Queue.push(Ticket);
       

    }
    void PrintInfo()
    {
        cout << "\n\t\t__________________\n";
        cout << "\t\t    Queue Info";
        cout << "\n\t\t__________________\n\n";

        cout << "\t\tPrefix          = " << _Prefix << "\n";
        cout << "\t\tTotal Tickets   = " << _TotalTickets << "\n";
        cout << "\t\tServed Clients  = " << _ServedClients << "\n";
        cout << "\t\tWaiting Clients = " << _Queue.size() << "\n";

        cout << "\t\t__________________\n\n";
    }

    
    
    void PrintTicketsLineRTL()
    {
       
        queue<clsTicket> TempQueue = _Queue;

        
        cout << "\nTickets: ";
        while (!TempQueue.empty())
        {
            cout << TempQueue.front().GetTicketNumber() << " <-- ";
            TempQueue.pop();
        }
        cout << "\n";
    }

    void PrintTicketsLineLTR()
    {
        stack<clsTicket> TempStack;
        queue<clsTicket> TempQueue = _Queue;

        while (!TempQueue.empty())
        {
            TempStack.push(TempQueue.front());
            TempQueue.pop();
        }

        cout << "\nTickets: ";
        while (!TempStack.empty())
        {
            cout << TempStack.top().GetTicketNumber() << " --> ";
            TempStack.pop();

        }
        cout << "\n";

    }

    void PrintAllTickets()
    {
        queue<clsTicket> TempQueue = _Queue;

        cout << "\n\t\t--- Tickets --- \n";

        while (!TempQueue.empty())
        {
            cout << "\n\t\t__________________\n";
            cout << "\t\t\t " << TempQueue.front().GetTicketNumber() << "\n\n";
            cout << "\t\t " << TempQueue.front().GetDateTime(); 
            cout << "\t\t Waiting Clients = " << TempQueue.front().GetWaitingClients() << "\n";
            cout << "\t\t Serve Time In \n\t\t  " << TempQueue.front().GetWaitingClients() * _ServiceTime << " Minutes.\n";
            cout << "\t\t__________________\n\n";

            TempQueue.pop(); 
        }
    }

    bool ServeNextClient()
    {
        if (_Queue.empty())
        {
            return false;
        }
        _ServedClients++;
        _Queue.pop();
        return true;

    }

private:

    string _Prefix;
    int _ServiceTime;
    int _TotalTickets;
    int _ServedClients;

    queue<clsTicket> _Queue;

   

};