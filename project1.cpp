#include <iostream>
#include <vector>
#include<string>

using namespace std;

// Base class for Tickets
class Ticket {
public:
    Ticket(string name, float price, int count)
    : name(name), price(price), count(count) {}

    virtual void display() const = 0;
    virtual void book(int num) = 0;
    


protected:
    string name;
    float price;
    int count;
};

// Derived class for SeatTickets
class BookSeat : public Ticket {
public:
    BookSeat(string name, float price, int count, string seatRow)
        : Ticket(name, price, count), seatRow(seatRow) {}

    void display() const override {
        cout << "Ticket: " << name << " (" << seatRow << "): Rs " << price << " Available: " << count << endl;
    }

    void book(int num) override {
        if (count >= num) {
            cout << "Booking " << num << " " << seatRow << " tickets for " << name << " at Rs " << int(price * num) << endl;
            count -= num;
        } else {
            cout << "Not enough available " << seatRow << " tickets for " << name << endl;
        }
    }
protected:
    string seatRow;
};

// Derived class for Payment
class Payment {
public:
    virtual void paymentMethod() = 0;
};

// Derived class for CardPayment
class CardPay : public Payment {
public:
    void paymentMethod() override {
        cout << "Enter card details (CVV, Expiry Date): ";
        string cvv, expDate;
        cin >> cvv >> expDate;
        cout << "Your card payment has been processed successfully." << endl;
    }
};

// Derived class for UPIPayment
class UPIPay : public Payment 
{
public:
    void paymentMethod() override {
        cout << "Enter UPI phone number: ";
        string phoneNumber;
        cin >> phoneNumber;
        if(size(phoneNumber)<10 || size(phoneNumber)>10){
            cout<<"Enter valid 10-digit phone number : ";
            cin>>phoneNumber;
            if((size(phoneNumber=10))){
                cout<<"Your UPI payment has been processed successfully."<<endl;
            }
        }
        else{
            cout << "Your UPI payment has been processed successfully." << endl;
        }
        
    }
};

// Function to draw a seating layout
void showLayout(string movieName, int frontRowCount, int backRowCount) {
    cout << "Seating Layout for " << movieName << ":\n";
    cout << "Front Row: ";
    for (int i = 0; i < frontRowCount; ++i) {
        cout << "[ ]";
    }
    cout << endl;

    cout << "Back Row: ";
    for (int i = 0; i < backRowCount; ++i) {
        cout << "[ ]";
    }
    cout << endl;
}
void generateTicket(string movieName,  string showtime) {
    // Create a ticket format with stars as borders
    string stars = "****************************************";
    
    cout << "\n" << stars << "\n";
    cout << "*  Movie: " << movieName << "\n";
    cout << "*  Showtime: " << showtime << "\n";
    cout << stars << "\n";
}


int main() {
    // Define available movies and their showtimes
    vector<string> movies = { "Movie A", "Movie B", "Movie C" };
    vector<string> showtimes = { "10:00 AM", "02:30 PM", "07:00 PM" };

    // Create instances of SeatTicket for each movie and showtime
    BookSeat TicketsforA("Movie A", 100.0, 20, "Front");
    BookSeat TicketsforB("Movie B", 250.0, 30, "Front");
    BookSeat TicketsforC("Movie C", 350.0, 18, "Front");
    string selectedMovie;
    int choice;
    while (true) {
        cout << "\nOnline Movie Ticket Booking System\n";
        cout << "1. See Available Movies and Showtimes\n";
        cout << "2. Book Tickets and make payment\n";
       // cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        

        switch (choice) {
            case 1:
                cout << "\nAvailable Movies and Showtimes:\n";
                for (int i = 0; i < movies.size(); ++i) {
                    cout << i + 1 << ". " << movies[i] << " - " << showtimes[i] << endl;
                }
                break;

            case 2:
                int ChoiceOfMovie, numOfTickets;
                cout << "Enter the movie number to book tickets: ";
                cin >> ChoiceOfMovie;
                if (ChoiceOfMovie >= 1 && ChoiceOfMovie <= movies.size()) {
                    cout << "Enter the number of tickets to book: ";
                    cin >> numOfTickets;

                    selectedMovie = movies[ChoiceOfMovie - 1];
                    int frontRowCount, backRowCount;
                    if (selectedMovie == "Movie A") {
                        frontRowCount = 20;
                        backRowCount = 30;
                    } else if (selectedMovie == "Movie B") {
                        frontRowCount = 25;
                        backRowCount = 35;
                    } else {
                        frontRowCount = 18;
                        backRowCount = 25;
                    }

                    showLayout(selectedMovie, frontRowCount, backRowCount);

                    cout << "Enter the row choice (1: Front Row, 2: Back Row): ";
                    int ChoiceOfRow;
                    cin >> ChoiceOfRow;

                    if (ChoiceOfRow == 1) {
                        if(selectedMovie=="Movie A"){
                            TicketsforA.book(numOfTickets);
                        }
                        else if(selectedMovie=="Movie B"){
                            TicketsforB.book(numOfTickets);
                        }
                        else if(selectedMovie=="Movie C"){
                            TicketsforC.book(numOfTickets);
                        }
                        
                        
                    } else if (ChoiceOfRow == 2) {
                        //TicketsforB.book(numOfTickets);
                        if(selectedMovie=="Movie A"){
                            TicketsforA.book(numOfTickets);
                        }
                        else if(selectedMovie=="Movie B"){
                            TicketsforB.book(numOfTickets);
                        }
                        else if(selectedMovie=="Movie C"){
                            TicketsforC.book(numOfTickets);
                        }
                       
                    } else {
                        cout << "Invalid row choice." << endl;
                    }
                } else {
                    cout << "Invalid movie choice." << endl;
                }int paymentChoice;
                cout << "Select Payment Method:\n";
                cout << "1. Card\n";
                cout << "2. UPI\n";
                cout << "Enter your choice: ";
                cin >> paymentChoice;

                Payment* paymentProcess;
                if (paymentChoice == 1) {
                    paymentProcess = new CardPay();
                } else if (paymentChoice == 2) {
                    paymentProcess = new UPIPay();
                } else {
                    cout << "Invalid payment choice." << endl;
                    continue;
                }

                paymentProcess->paymentMethod();
                delete paymentProcess;
                cout<<"\nYour online ticket :"<<endl;
                generateTicket(selectedMovie, showtimes[ChoiceOfMovie - 1]);
                 cout << "\nThank you for using our Online Movie Ticket Booking System!\n";
                return 0;
            
            /*case 3:
                cout << "\nThank you for using our Online Movie Ticket Booking System!\n";
                return 0;*/

            default:
                cout << "Invalid choice. Please select a valid option.\n";
                break;
        }
    }

    return 0;
}