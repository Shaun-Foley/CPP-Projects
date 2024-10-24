//*************************************************************************************************
//
//      This program demonstrates a simple supermarket management system. The program allows
//      the user to add, modify, and delete products, view the list of products, and generate a 
//      receipt.
//
//*************************************************************************************************

#include<iostream>
#include<fstream>
#include<vector>

//*************************************************************************************************

class shopping {
    private:
        int pcode;
        float price;
        float discount;
        std::string pname; 

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void removeProduct();
        void list();
        void receipt();
};

//*************************************************************************************************

/**
 * @brief The main entry point of the program.
 * 
 */
int main() {
    shopping s;
    s.menu();
}

//*************************************************************************************************

/**
 * @brief The main menu displays the options for administration, buyer, and exit.
 *          The user is prompted to enter a choice and the program will perform
 *          the respective action.
 */
void shopping::menu() { 
    while(true) {
        int choice;
        std::string email, password;

        std::cout << "\t\t\t\t------------------------------\n";
        std::cout << "\t\t\t\t     Supermarket Main Menu    \n";
        std::cout << "\t\t\t\t------------------------------\n";
        std::cout << "\n\t\t\t\t| 1. Administration       | \n";
        std::cout << "\t\t\t\t| 2. Buyer                | \n";
        std::cout << "\t\t\t\t| 3. Exit                 | \n";
        std::cout << "\n\t\t\t Please select! ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "\t\t\t Please Login \n";
                std::cout << "\t\t\t Enter email: ";
                std::cin >> email;
                std::cout << " \t\t\t Password: ";
                std::cin >> password;

                if ((email == "admin@admin") && (password == "admin")) {
                    administrator();
                } else {
                    std::cout << "\n\t\t\tInvalid email/password\n";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                exit(0);
                break;

            default:
                std::cout << "Please select from the given options\n";
        }
    }
}

//*************************************************************************************************

/**
 * 
 * @brief The administrator menu displays the options for adding, modifying, deleting, and going back to the main menu.
 *          The user is prompted to enter a choice and the program will perform the respective action.
 */
void shopping :: administrator(){
    while(true){
        int choice;
   
        std::cout << "\t\t\t\t------------------------------\n";
        std::cout << "\t\t\t\t      Administrator Menu      \n";
        std::cout << "\t\t\t\t------------------------------\n";
        std::cout << "\n\t\t\t\t| 1. Add the product      |";
        std::cout << "\n\t\t\t\t| 2. Modify the product   |";
        std::cout << "\n\t\t\t\t| 3. Delete the product   |";
        std::cout << "\n\t\t\t\t| 4. Back to main menu    |";

        std::cout << "\n\n\t\t\t Please enter your choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                add();
                break;

            case 2:
                edit();
                break;

            case 3:
                removeProduct();
                break;

            case 4:
                menu();
                break;

            default:
                std::cout << "\t\t\t Invalid choice! \n";

        }
    }
}

//*************************************************************************************************

/**
 * @brief The buyer menu displays the options for buying a product and going back to the main menu.
 *          The user is prompted to enter a choice and the program will perform the respective action.
 */
void shopping :: buyer(){
        int choice;
        do{
            std::cout << "\n\t\t\t| 1. Buy Product          |\n";;
            std::cout << "\t\t\t| 2. Go back              |\n"; 
            std::cin >> choice;

            switch(choice){
                case 1:
                    receipt();
                    break;
                case 2:
                    menu();
                    break;
                default:
                    std::cout << "\n\t\t\tInvalid choice \n";
            }        
            } while (choice != 2);

}

//*************************************************************************************************

/**
 * @brief The add function adds a new product to the database. It will ask the user to enter the product code,
 *        name, price, and discount. 
 * 
 */
void shopping :: add(){
    m:
    std::fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    std::string n;

    std::cout << "\t\t\tYou chose add new product. \n";
    std::cout << "\t\t\tPlease enter the product code: ";
    std::cin >> pcode;
    std::cout << "\t\t\tName of the product: ";
    std::cin >> pname;
    std::cout << "\t\t\tPrice of the product: ";
    std::cin >> price;
    std::cout << "\t\t\tDiscount on product: ";
    std::cin >> discount;

    data.open("database.txt", std::ios::in); 

    if(!data){ 
        data.open("database.txt", std::ios::app|std::ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n"; 
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c == pcode){ 
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token == 1)
        goto m;
    else{ 
        data.open("database.txt", std::ios::app|std::ios::out); 
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    std::cout << "\n\t\t\tRecord inserted ! \n";
}

//*************************************************************************************************

/**
 *
 * @brief This function is used to edit a product in the database. It asks the user
 *          to enter the product code of the product they want to edit, and then
 *          prompts them to enter the new code, name, price, and discount for the product.
 *
 * @note   If the product code entered by the user does not match with any product code
 *         in the database, it will not make any changes to the database.
 */
void shopping :: edit(){
    std::fstream data, data1; 
    int pkey;
    int token =0;
    int c;
    float p;
    float d;
    std::string n;

    std::cout << "\n\n\t\t\tModify the record \n";
    std::cout << "\t\t\tEnter the product code: "; 
    std::cin >> pkey;

    data.open("database.txt", std::ios::in); 
    if(!data){
        std::cout << "\n\t\t\tFile doesn't exist!\n";

    }
    else{
        data1.open("database1.txt", std::ios::app|std::ios::out);

        data >> pcode >> pname >> price >> discount;

        while(!data.eof()){
            if(pkey == pcode){
                std::cout << "\t\t\tProduct new code: ";
                std::cin >> c;
                std::cout << "\t\t\tName of the product: ";
                std::cin >> n;
                std::cout << "\t\t\tPrice: ";
                std::cin >> p;
                std::cout << "\t\t\tDiscount: ";
                std::cin >> d;
                data1 << " " << c << " " << p << " " << d << "\n";
                std::cout << "\n\t\t\tRecord edited\n";
                token++;
            }
            else{
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n"; 
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();

        std::remove("database.txt");
        rename("database1.txt", "database.txt"); 

        if(token == 0){
            std::cout << "\n\t\t\tRecord not found sorry! \n";
        }
    }

}

//*************************************************************************************************

/**
 * @brief Removes a product from the database with the given product code.
 * 
 */
void shopping :: removeProduct(){
    std::fstream data, data1;
    int pkey;
    int token = 0;
    std::cout << "\t\t\tDelete product \n";
    std::cout << "\t\t\tProduct code: ";
    std::cin >> pkey;
    data.open("database.txt", std::ios::in);
    if(!data){
        std::cout << "\n\t\t\tFile doesn't exist \n";

    }
    else{
        data1.open("database1.txt", std::ios::app|std::ios::out);
        data >> pcode >> pname >> price >> discount;
        while(!data.eof()){
            if(pcode == pkey){
                std::cout << "\t\t\tProduct deleted successfully\n";
                token++;
            }
            else{
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();

        std::remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0){
            std::cout << "\t\t\tRecord not found sorry!\n";
        }
    }
}

//*************************************************************************************************

/**
 * @brief This function reads the database and displays all the products in a formatted list.
 *        It displays the product code, name, and price.
 */
void shopping :: list(){
    std::fstream data;
    data.open("database.txt", std::ios::in);
    std::cout << "\n\n________________________________\n";
    std::cout << "ProNo\t\tName\t\tprice";
    std::cout << "\n\n________________________________\n";
    data >> pcode >> pname >> price >> discount;
        while(!data.eof()){
            std::cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
            data >> pcode >> pname >> price >> discount;
        }
    data.close();
}

//*************************************************************************************************

/**
 * @brief Displays the receipt for the purchased items.
 *        This function shows the receipt for the purchased items, including the product number, name, quantity, price, amount, and amount with discount. 
 *        It also displays the total amount.
 *
 */
void shopping :: receipt(){
    std::fstream data;

    std::vector<int> vProductCode;
    std::vector<int> vQuantity;
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    std::cout << "RECEIPT";
    data.open("database.txt", std::ios::in);

    if(!data) {
        std::cout << "\t\t\tEmpty database!\n";
        return;
    } 
    else {
        data.close();

        list(); 
        std::cout << "\t\t\tPlace your order\n";

        do {
            bool validProduct = false;
            int productCode, productQty;

            while (!validProduct) {
                std::cout << "\t\t\tEnter Product code: ";
                std::cin >> productCode;

                bool isDuplicate = false;
                for (int i = 0; i < c; i++) {
                    if (vProductCode[i] == productCode) {
                        std::cout << "\n\t\t\tDuplicate product code, please try again.\n";
                        isDuplicate = true;
                        break;
                    }
                }

                if (isDuplicate) {
                    continue; 
                }

                std::cout << "\t\t\tEnter the product quantity: ";
                std::cin >> productQty;

                vProductCode.push_back(productCode);
                vQuantity.push_back(productQty);
                c++;
                validProduct = true;
            }

            std::cout << "\t\t\tDo you want to buy another product? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y'); 

        std::cout << "\t\t\tRECEIPT\n";
        std::cout << "Product number\t Product Name\t Quantity\t Price\t Amount\t Amount with Discount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", std::ios::in);
            data >> pcode >> pname >> price >> discount;

            while (!data.eof()) {
                if (pcode == vProductCode[i]) {
                    amount = price * vQuantity[i];
                    float discountAmount = amount * (discount / 100);
                    float amountWithDiscount = amount - discountAmount;
                    total += amountWithDiscount;

                    std::cout << pcode << "\t\t" << pname << "\t\t" << vQuantity[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << amountWithDiscount << "\n";
                }
                data >> pcode >> pname >> price >> discount;
            }
            data.close();
        }
    }
    std::cout << "\t\t\tTotal amount: " << total << "\n";
}

//*************************************************************************************************