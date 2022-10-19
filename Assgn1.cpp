#include "Inventory.h"
void showNoProducts(Inventory);

int main()
{
	cout << "Inventory object examples from Inventory.data file:" << endl << endl;
	Inventory company("Inventory.data", 15);
	cout << "\nNumber of products = "
		<< company.getNoProducts() << endl;
	cout << "printing all products in Inventory.data to the screen:\n\n";
	company.writeInventory(cout);
	cout << "\nLooking up product # 54312:\n";
	company.showProduct(54312);		//should be in Inventory.data, if not add it
	cout << "\nIncrease price by $1.22 for product # 54312\n\n";
	company.increasePrice(54312, 1.22);
	cout << "Looking up new price for product # 54312:\n";
	company.showProduct(54312);		//should be incremented
	cout << "\nLooking up product # 60000:\n";
	company.showProduct(60000);		//incremented over $1000
	cout << "\n\nIncrease price by $1000 for product # 60000:\n";
	company.increasePrice(60000, 1000.);
	cout << "Looking up new price for product # 60000\n\n";
	company.showProduct(60000);		//incremented over $1000
	cout << "Number of products = " << company.getNoProducts() << endl;
	cout << "\nprinting all products in Inventory.data screen:\n\n";
	company.writeInventory(cout);


	cout << "\n\n\nEmpty object examples from default.data file" << endl << endl;
	Inventory myshop("default.data");			//empty file
	cout << "Number of products = " << myshop.getNoProducts() << endl << endl;
	cout << "Increase price by $1.22 for product # 24000\n\n";//not in file
	myshop.increasePrice(3483, 1.22);
	ofstream fout("output.file");
	if (!fout.is_open())
	{
		cout << "error opening file " << endl;
		system("pause");
		exit(1);
	}
	fout << fixed << setprecision(2);
	myshop.writeInventory(fout);




	cout << "\n\nFull file (products.data file) examples" << endl << endl;
	Inventory fullLoad("product.data");  //file has more than 25 records
	fullLoad.increasePrice(854, 2.00);
	fullLoad.writeInventory(cout);
	cout << "Number of products  = " << fullLoad.getNoProducts()
		<< endl << endl;
	cout << "\nLooking up product # 666:\n";
	fullLoad.showProduct(666);  //pass one that doesn't exist

	//add the code to call your showNoProducts() function here
	showNoProducts(fullLoad);

	system("type output.file");
	system("pause");
}
void showNoProducts(Inventory products)
{
	cout << "Number of products: " << products.getNoProducts() << endl;
}
/*
Inventory object examples from Inventory.data file:


Number of products = 6
printing all products in Inventory.data to the screen:

Code      Description              Price

1023      calendar                 10.00
2310      Computer Desk           200.00
7382      Book Bag                 75.75
3421      Desk Lamp                37.99
54312     Golf Set                876.00
60000     Magic Syrum             555.55

Number of Products: 6

Looking up product # 54312:

54312     Golf Set                876.00

Increase price by $1.22 for product # 54312

Looking up new price for product # 54312:

54312     Golf Set                877.22

Looking up product # 60000:

60000     Magic Syrum             555.55


Increase price by $1000 for product # 60000:

Error price over 1000. Maximum price of $1000 was assigned.

Looking up new price for product # 60000


60000     Magic Syrum            1000.00
Number of products = 6

printing all products in Inventory.data screen:

Code      Description              Price

1023      calendar                 10.00
2310      Computer Desk           200.00
7382      Book Bag                 75.75
3421      Desk Lamp                37.99
54312     Golf Set                877.22
60000     Magic Syrum            1000.00

Number of Products: 6



Empty object examples from default.data file

Number of products = 0

Increase price by $1.22 for product # 24000

Error Finding Product ID


Full file (products.data file) examples

Code      Description              Price

1023      calendar                 10.00
2310      Computer Desk           200.00
7382      Book Bag                 75.75
3421      Desk Lamp                37.99
54312     Golf Set                876.00
60000     Magic Syrum             555.55
90093     Laptop                  997.99
72528     Pool Table              734.90
8547      Dinner Table            892.90
854       Tv                      999.00
24532     Couch                   234.56
83642     fridge                  980.89
27452     engine winch            999.99
7284      walkie-talkie            89.99
27903     oil filter               28.99
92833     oil                      45.59
90823     strut                   130.30
78293     control arm              90.90
78932     engine air filter        38.83
78294     cabin air filter         32.95
82393     brake pads               54.45
98340     rims                    167.67
29830     winter tires            165.90
29832     winter saftey kit        82.99
29838     random item               9.99

Number of Products: 25
Number of products  = 25


Looking up product # 666:
Error Finding Product ID
Number of products: 25

Press any key to continue . . .
*/