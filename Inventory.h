#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ostream>

using namespace std;
// lab 2 specification file
// nick eliopopulos

const int SIZE = 25;
struct ProductRec {

	int productId;
	string productType;
	double price;
};
class Inventory
{
private:
	ProductRec products[SIZE];
	int maxProducts;
	int noProducts;
	int searchProduct(int /*productId*/);
public:
	void showProduct(int/*productId*/);
	void writeInventory(ostream&/*out*/) const;
	int getNoProducts() { return noProducts; }
	void increasePrice(int/*productId*/, double /*newPrice*/);
	Inventory(string/*file name*/, int = SIZE/*max products*/);

};

