#include "Homepage.h"
#include "Storage.h"

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
Storage<LinkedList<Supplier>*>* Storage<LinkedList<Supplier>*>::instance = nullptr;
Storage<LinkedList<Order>*>* Storage<LinkedList<Order>*>::instance = nullptr;
Storage<LinkedList<Item>*>* Storage<LinkedList<Item>*>::instance = nullptr;

void Initialization() {

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
	// uncomment this and delete other lines to launch the actual system
	Initialization();
	Homepage Homepage;
	
	
}

