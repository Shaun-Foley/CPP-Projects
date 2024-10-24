//*************************************************************************************************
//
//      This program demonstrates a simple Bug Tracker. It allows the user to add, view, search, 
//      update, and delete bugs. The program continues to run until the user chooses to quit. 
//
//*************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//*************************************************************************************************

class Bug{
    public: //members
        int id; //Unique ID for each bug
        std::string title; //Short title for the bug
        std::string description; //Desciption of bug
        std::string priority; // priority status of bug 
        std::string status; // bug status 

        //Constructor - Bug object with an ID, title, description, priority, and status
        Bug(int _id, std::string _title, std::string _description, std::string _priority, std::string _status)
            : id(_id), title(_title), description(_description), priority(_priority), status(_status) {}

        void display() const { 
            std::cout << "ID: " << id << "\nTitle: " << title
                << "\nDescription: " << description 
                << "\nPriority: " << priority 
                << "\nStatus: " << status << "\n\n";
        }
};

//*************************************************************************************************

class BugTracker {
    private:
        std::vector<Bug> bugs; // vector (dynamic array) to store bugs
        int nextId = 1; //unique id generator

    public:
        void addBug(); //add new bug
        void listBugs() const; //show bugs
        void updateBugStatus(); //update bug
        void deleteBug(); //delete bug
        void searchBug();
        void saveToFile(); ///data persist
        void loadFromFile(); //data persist
};

//*************************************************************************************************

/**
 * @brief This function is the main entry point of the program. It creates a BugTracker
 * object and enters a loop where it continually prompts the user for input.
 * The user can add a bug, view all bugs, search for bugs, update a bug's status,
 * delete a bug, or save and exit the program.
 * 
 */
int main() {
    BugTracker tracker; //manage bug operations
    tracker.loadFromFile(); //load existing bugs if any

    int choice;

    do {
        std::cout << "\nBug Tracker Menu\n";
        std::cout << "1. Add Bug\n";
        std::cout << "2. View All Bugs\n";
        std::cout << "3. Search Bugs\n";
        std::cout << "4. Update Bug Status\n";
        std::cout << "5. Delete Bug\n";
        std::cout << "6. Save and Exit\n";
        std::cout << "Enter choice: ";
        
        if (!(std::cin >> choice)) {
            std::cerr << "Error: Invalid input\n";
            return 1;
        }

        switch (choice) {
            case 1:
                tracker.addBug();
                break;
            case 2:
                tracker.listBugs();
                break;
            case 3:
                tracker.searchBug();
                break;
            case 4:
                tracker.updateBugStatus();
                break;
            case 5:
                tracker.deleteBug();
                break;
            case 6:
                tracker.saveToFile();
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    
    return 0;
}

//*************************************************************************************************


/**
 * @brief This function prompts the user to input the title, description, and priority of the bug, 
 *        and adds it to the bug tracker.
 * 
 */
void BugTracker::addBug() {
    std::string title, description, priority, status = "Open";
    std::cout << "Enter Bug Title: ";
    std::cin.ignore();
    if (!std::getline(std::cin, title)) {
        std::cerr << "Error: Invalid input\n";
        return;
    }
    if (title.empty()) {
        std::cout << "Title cannot be empty!\n";
        return;
    }
    if (title.length() < 5 || title.length() > 50) {
        std::cout << "Title must be between 5 and 50 characters!\n";
        return;
    }
    

    std::cout << "Enter Bug Desciption: ";
        if (!std::getline(std::cin, description)) {
            std::cerr << "Error: Invalid input\n";
            return;
        }
        if (description.empty()) {
            std::cout << "Description cannot be empty!\n";
            return;
        }
        if (description.length() < 10 || description.length() > 500) {
            std::cout << "Description must be between 10 and 500 characters!\n";
            return;
        }

    std::cout << "Enter Bug Priority (Low, Medium, High): ";
        if (!std::getline(std::cin, priority)) {
            std::cerr << "Error: Invalid input\n";
            return;
        }
        if (priority != "Low" && priority != "Medium" && priority != "High") {
            std::cout << "Invalid input!\n";
            std::cout << "Bug Priority must be Low, Medium, or High!\n";
            return;
        }

    Bug newBug(nextId++, title, description, priority, status);
    bugs.push_back(newBug);

    std::cout << "Bug added successfully!\n";
}

//*************************************************************************************************


/**
 * @brief List all bugs in the bug tracker
 *
 */
void BugTracker::listBugs() const {
    if (bugs.empty()) {
        std::cout << "No bugs to display!\n";
        return;
    }
    for (const Bug& bug : bugs) { // loops through the bugs and uses display variable
        bug.display();
    }
}

//*************************************************************************************************


/**
 * @brief Update the status of an existing bug
 * 
 */
void BugTracker::updateBugStatus() {
    int id;
    std::string newStatus;

    std::cout << "Enter Bug ID to update: ";
    std::cin >> id;

    bool found = false; //check if bug is found
    for (Bug& bug : bugs) {
        if (bug.id == id) {
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Bug with ID " << id << " not found!\n";
        return;
    }

    for (Bug& bug : bugs) {
        if(bug.id == id) {
            std::cout << "Enter new status (Open, In Progress, Closed): ";
            if (newStatus != "Open" && newStatus != "In Progress" && newStatus != "Closed") {
                std::cout << "Invalid input!\n";
                std::cout << "Bug Status must be Open, In Progress, or Closed!\n";
                return;
            }
            std::cin.ignore();
            std::getline(std::cin, newStatus);
            bug.status = newStatus;
            std::cout << "Status updated successfully!\n";
            return;
        }

        
    }
    std::cout << "Bug with ID " << id << " not found!\n";
}

//*************************************************************************************************


/**
 * @brief Deletes a bug from the bug tracker based on a given ID.
 *
 */
void BugTracker::deleteBug() {
    int id;
    std::cout << "Enter Bug ID to delete: ";
    std::cin >> id;

    // check if ID is valid
    bool found = false;
    for (Bug& bug : bugs) {
        if (bug.id == id) {
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Bug with ID " << id << " not found!\n";
        return;
    }

    for (auto it = bugs. begin(); it != bugs.end(); ++it) { //find the id and delete
        if (it->id == id) {
            bugs.erase(it);
            std::cout << "Bug deleted successfully!\n";
            return;
        }
    }
    std::cout << "Bug with ID " << id << " not found!\n";
}

//*************************************************************************************************


/**
 * @brief Search for bugs by title, description, status, or priority
 *
 */
void BugTracker::searchBug() {
    std::string searchTerm;
    std::cout << "Enter search term: ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);
        if(searchTerm.empty()) {
            std::cout << "Search term cannot be empty!\n";
            return;
        }
        if(searchTerm.length() > 50) {
            std::cout << "Search term must be less than 50 characters!\n";
            return;
        }

    //Case sensitive search
    std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);

    std::cout << "Search results:\n";
    bool found = false;
    for (const Bug& bug : bugs) {
        //lowercase bug fields for comparison
        std::string lowerTitle = bug.title;
        std::string lowerDescription = bug.description;
        std::string lowerStatus = bug.status;
        std::string lowerPriority = bug.priority;
        std::transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
        std::transform(lowerDescription.begin(), lowerDescription.end(), lowerDescription.begin(), ::tolower);
        std::transform(lowerStatus.begin(), lowerStatus.end(), lowerStatus.begin(), ::tolower);        
        std::transform(lowerPriority.begin(), lowerPriority.end(), lowerPriority.begin(), ::tolower);

        if (lowerTitle.find(searchTerm) != std::string::npos || // npos check if search was successful or not
            lowerDescription.find(searchTerm) != std::string::npos ||
            lowerStatus.find(searchTerm) != std::string::npos ||
            lowerPriority.find(searchTerm) != std::string::npos) {
            bug.display();
            found = true;
            }
    }

    if (!found) {
        std::cout << "No results found!\n";
    }
}

//*************************************************************************************************


/**
 * @brief This function saves the bug repository to a file named "bugs.txt". 
 *        Each bug is written to a new line, with its fields separated by spaces.
 */
void BugTracker::saveToFile() {
    std::ofstream file("bugs.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!\n";
        return;
    }

    for (const Bug& bug : bugs) {
        file << bug.id << "\n" << bug.title << "\n" << bug.description << "\n"
        << bug.priority << "\n" << bug.status << "\n";
    }
    file.close();
    std::cout << "Bugs saved to file!\n";
}

//*************************************************************************************************

/**
 * @brief This function loads bugs from a text file "bugs.txt" and stores them in the bugs vector.
 * 
 */
void BugTracker::loadFromFile() {
    std::ifstream file("bugs.txt");
    
    if(!file) {
        std::cout << "No existing data file found.\n";
        return;
    }

    if (!file.is_open()) {
        std::cerr << "Failed to load file!\n";
        return;
    }

    int id;
    std::string title, description, priority, status;
    while (file >> id) {
        file.ignore();
        std::getline(file, title);
        std::getline(file, description);
        std::getline(file, priority);
        std::getline(file, status);

        bugs.push_back(Bug(id, title, description, priority, status));
        nextId = id + 1; // ensure that continue from last bug id
    }
    file.close();
    std::cout << "Bugs loaded from file! \n";
}

//*************************************************************************************************

