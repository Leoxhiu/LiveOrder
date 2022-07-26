#include "Homepage.h"
#include "Storage.h"
#include "LinkedList.h"
#include "DynamicArray.h"

#include "Item.h"
#include "ItemDA.h"

#include "Order.h"
#include "OrderDA.h"

#include "Supplier.h"
#include "SupplierDA.h"

#include "User.h"
#include "UserDA.h"



using namespace std;

Storage<LinkedList<User>*>* Storage<LinkedList<User>*>::instance = nullptr;
Storage<DynamicArray<Supplier>*>* Storage<DynamicArray<Supplier>*>::instance = nullptr;
Storage<LinkedList<Order>*>* Storage<LinkedList<Order>*>::instance = nullptr;
Storage<DynamicArray<Item>*>* Storage<DynamicArray<Item>*>::instance = nullptr;

void initialization() {

	// import user data into linked list (store at run time)
	UserDA userDA;
	userDA.importUser();

	// import supplier data into linked list (store at run time)
	SupplierDA supplierDA;
	supplierDA.importSupplier();

	// import order data into linked list (store at run time)
	OrderDA orderDA;
	orderDA.importOrder();

	// import item data into linked list (store at run time)
	ItemDA itemDA;
	itemDA.importItem();
}

int main()
{
	initialization();
	Homepage Homepage;
}