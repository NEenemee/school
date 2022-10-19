#include "Inventory.h"

// implimentation file for inventory
// Nick Eliopoulos

Inventory::Inventory(string FileName, int newMaxProducts)
{
	maxProducts = (newMaxProducts < SIZE) ? newMaxProducts : SIZE;
	ifstream fin(FileName);
	if (!fin.is_open())
	{
		cout << "error opening" << FileName << "file ";
		system("pause");
		cout << endl;
	}
	int ctr = 0;
	for (; ctr < maxProducts; ctr++)
	{
		fin >> products[ctr].productId;
		fin.ignore(80, '\n');
		getline(fin, products[ctr].productType);
		fin >> products[ctr].price;
		if (fin.eof()|| ctr==maxProducts-1)
		{
			break;
		}
	}
	noProducts = (ctr < 1) ? ctr : ctr + 1;
	
}
void Inventory::showProduct(int findProductId)
{
	int num = searchProduct(findProductId);
		if (products[num].productId == findProductId)
		{
			cout << fixed << setprecision(2);
			cout << endl<<left<< setw(10) << products[num].productId << setw(20) << products[num].productType << setw(10) << right
				<< products[num].price << endl;
		}
		
}
void Inventory::writeInventory(ostream& out) const
{
	out << left << setw(10) << "Code" << setw(20) << "Description"
		<< setw(10) << right << "Price" << endl << endl;
	int ctr = 0;
	for (; ctr < noProducts; ctr++)
	{
		out << fixed << setprecision(2);
		out << left << setw(10) << products[ctr].productId <<
			setw(20) << products[ctr].productType << setw(10) <<
			right << products[ctr].price << endl;
	}
	out << endl << "Number of Products: " << noProducts << endl;
}
void Inventory::increasePrice(int findProductId, double newPrice)
{
	int findNum = searchProduct(findProductId);
	products[findNum].price = (products[findNum].price+newPrice < 1000) ? products[findNum].price += newPrice : 1000;
	if (products[findNum].price == 1000)
		cout << endl << "Error price over 1000. Maximum price of $1000 was assigned." << endl << endl;
}
int Inventory::searchProduct(int searchedId)
{
	int ctr = 0;
	for (; ctr < noProducts; ctr++)
	{
		if (searchedId == products[ctr].productId)
			break;
	}
	if (searchedId != products[ctr].productId)
		cout << "Error Finding Product ID" << endl;
	return ctr;
}

