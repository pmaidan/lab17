// Polina Maidanova
// Programming Fundamentals
// CS 1436
// 005
// Due Date: 11/02/2024
// Date Completed: 10/31/2024
// Date Submitted: 11/02/2024


// This program estimates the data for a paint job.

#include <iostream> // Header file allowing the use of input/output objects.
#include <iomanip>  // Header file allowing to manipulate the output.
using namespace std;    // Use standard namespace.

// Prototypes for the functions that will be called in the program.
double paintFractionalGallons(int);
int paintWholeGallons(int);
double laborHours(int);
double paintCost(double, double);
double laborCost(double);
double totalCost(double, double);
void displayResults(double, double, double, double, double);

int main()  // Main function is the starting point of the program execution.
{
    int iRooms, iWallSpace, iPaintAmount, iWallSpaceTotal = 0;
    double fPaintPrice, fGallonsTotal, fHoursTotal, fPaintCost, fLaborCost, fTotalCost;

    // Get the number of rooms to be painted.
    cout << "Enter the number of rooms to be painted: ";
    cin >> iRooms;

    // Validate the input.
    while (iRooms < 1)  // If the number of rooms less than 1 was entered, display an error message and get new input.
    {
        cout << "Invalid input. Please enter a number of rooms greater than 0: ";
        cin >> iRooms;
    }

    // Get the wall space to be painted for each room.
    for (int iRoomCount = 0; iRoomCount < iRooms; iRoomCount++) // Increment the room counter until the number of rooms is reached.
    {
        // Request the wall space to be painted in a room.
        cout << "Enter the number of square feet of wall space to be painted ";
        cout << "in room " << iRoomCount + 1 << ": ";
        cin >> iWallSpace;

        // Validate the input.
        while (iWallSpace < 0)  // If a negative amount of wall space was entered, display the error message.
        {
            cout << "Invalid input. Please enter a positive value for wall space to be painted: ";
            cin >> iWallSpace;
        }

        // Accumulate the total wall space to be painted.
        iWallSpaceTotal += iWallSpace;
    }

    // Get the paint price.
    cout << "Enter the price of the paint per gallon: ";
    cin >> fPaintPrice;

    // Validate the input.
    while (fPaintPrice < 10.0)  // If the price of less than 10 has been entered, request new input.
    {
        cout << "Invalid input. Please enter a price of the paint per gallon gof at least $10.00: ";
        cin >> fPaintPrice;
    }

    // Request the user to choose an option for the paint amount that can be purchased.
    cout << "Is paint sold per whole gallon, or any fractional amount can be sold?\n";
    cout << "Enter 1 for the whole gallons, or 2 for any amount: ";
    cin >> iPaintAmount;

    // Validate the input.
    while (iPaintAmount != 1 && iPaintAmount != 2) // If the menu choice is invalid, resquest new input.
    {
        cout << "Invalid input. Please enter 1 for whole gallons, or 2 for any amount: ";
        cin >> iPaintAmount;
    }

    // Calculate the gallons of paint needed for the paint job.
    switch (iPaintAmount)   // Check and execute the code that matches the user's menu choice.
    {
        case 1:
            fGallonsTotal = paintWholeGallons(iWallSpaceTotal); // Use the function that calculates the amount of whole gallons.
            break;
        case 2:
            fGallonsTotal = paintFractionalGallons(iWallSpaceTotal);    // Use the function that calculates the fractional amount of paint.
            break;
        default:
            cout << "Error. Invallid menu choice was entered";  // If the menu choice didn't match, display an error message.
            return 1;
    }

    // Call the functions to calculate the data for the paint job.
    fHoursTotal = laborHours(iWallSpaceTotal);
    fPaintCost = paintCost(fGallonsTotal, fPaintPrice);
    fLaborCost = laborCost(fHoursTotal);
    fTotalCost = totalCost(fPaintCost, fLaborCost);
    displayResults(fGallonsTotal, fHoursTotal, fPaintCost, fLaborCost, fTotalCost); // Display the results.

    return 0;   // Return 0 to indicate successful completion of the program.
}

// Function to calculate the amount of paint to be bought if it can be sold by fractions of a gallon.
double paintFractionalGallons(int iWallSpaceTotal)
{
    const double SQFT_PER_GALLON = 115.0;   // The amount of wall space that can be painted with one gallon of paint.
    double fGallonsTotal;
    fGallonsTotal = (double)iWallSpaceTotal / SQFT_PER_GALLON;  // The fractional amount of gallons needed to pain the walls.
    return fGallonsTotal;
}

// Function to calculate the amount of paint to be bought if it's sold by whole gallons.
int paintWholeGallons(int iWallSpaceTotal)
{
    const int SQFT_PER_GALLON = 115;    // The amount of wall space that can be painted with one gallon of paint.
    int iGallonsTotal;
    if (iWallSpaceTotal % SQFT_PER_GALLON == 0) // If there's no remainder, the walls can be painted with an integer amount of gallons of paint.
        iGallonsTotal = iWallSpaceTotal / SQFT_PER_GALLON;
    else
        iGallonsTotal = iWallSpaceTotal / SQFT_PER_GALLON + 1;  // If there's a remainder, one more gallon of paint will be needed.
    return iGallonsTotal;
}

// Function to calculate the hours of labor for the paint job.
double laborHours(int iWallSpaceTotal)
{
    const double SQFT_PER_HOUR = 115.0 / 8.0;   // The amount of wall space that can be painted in an hour.
    double fHoursTotal;
    fHoursTotal = (double)iWallSpaceTotal / SQFT_PER_HOUR;  // The number of hours needed to paint the walls.
    return fHoursTotal;
}

// Function to calculate the total cost for the paint.
double paintCost(double fGallonsTotal, double fPaintPrice)
{
    double fPaintCost;
    fPaintCost = fGallonsTotal * fPaintPrice;   // Total paint cost.
    return fPaintCost;
}

// Function to calculate the cost for the labor.
double laborCost(double fHoursTotal)
{
    const double LABOR_PER_HOUR = 18.0; // The labor cost per hour.
    double fLaborCost;
    fLaborCost = fHoursTotal * LABOR_PER_HOUR;  // Total labor cost.
    return fLaborCost;
}

// Function to calculate the total cost for the paint job.
double totalCost(double fPaintCost, double fLaborCost)
{
    double fTotalCost;
    fTotalCost = fPaintCost + fLaborCost;   // Total job cost.
    return fTotalCost;
}

// Function to display the calculated data for the paint job.
void displayResults(double fGallonsTotal, double fHoursTotal, double fPaintCost, double fLaborCost, double fTotalCost)
{
    cout << setprecision(2) << fixed;   // Display to 2 decimal places.
    cout << "Gallons of paint required: " << fGallonsTotal << endl;
    cout << "Hours of labor required: " << fHoursTotal << endl;
    cout << "Paint cost: $" << fPaintCost << endl;
    cout << "Labor cost: $" << fLaborCost << endl;
    cout << "Total cost: $" << fTotalCost << endl;
}
