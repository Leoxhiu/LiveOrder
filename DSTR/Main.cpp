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
	Initialization();

	// uncomment this to launch the actual system
	// Homepage Homepage;



	// Dynamic Array Bubble Sort Testing
	/*ItemDA supp;
	supp.displayList();

	cout << endl;
	supp.sortItembyID(ItemDA::sortMethod::descending);
	supp.displayList();

	cout << endl;

	supp.sortItembyQuantity(ItemDA::sortMethod::descending);
	supp.displayList();

	cout << endl;

	supp.sortItembyPrice(ItemDA::sortMethod::descending);
	supp.displayList();*/
	

	// linked list quick sort testing
	/*OrderDA orderDA;
	LinkedList<Order>* orderData = orderDA.getOrderData();

	orderDA.displayList();
	
	orderDA.sortOrderByID(orderDA.getOrderData(), 0, orderData->getLength()-1, OrderDA::sortMethod::descending);
	orderDA.displayList();
	cout << endl;
	orderDA.sortOrderByID(orderDA.getOrderData(), 0, orderData->getLength() - 1, OrderDA::sortMethod::ascending);
	orderDA.displayList();*/


	/*UserDA userDA;

	LinkedList<User>* userData = userDA.getUserData();
	userDA.displayList();

	userDA.sortUserByID(userDA.getUserData(), 0, userData->getLength() - 1, UserDA::sortMethod::descending);
	userDA.displayList();
	userDA.sortUserByID(userDA.getUserData(), 0, userData->getLength() - 1, UserDA::sortMethod::ascending);
	userDA.displayList();*/


	// Linked List Merge Sort Testing
	/*cout << endl;
	orderDA.sortOrderByQuantity(&orderData->head, OrderDA::sortMethod::descending);
	orderDA.displayList();

	cout << endl;
	orderDA.sortOrderByQuantity(&orderData->head, OrderDA::sortMethod::ascending);
	orderDA.displayList();

	cout << endl;
	orderDA.sortOrderByItemID(&orderData->head, OrderDA::sortMethod::ascending);
	orderDA.displayList();

	cout << endl;
	orderDA.sortOrderByItemID(&orderData->head, OrderDA::sortMethod::descending);
	orderDA.displayList();*/
}