#include "Homepage.h"

#include "Item.h"
#include "ItemDA.h"

#include "Order.h"
#include "OrderDA.h"

#include "Supplier.h"
#include "SupplierDA.h"

#include "User.h"
#include "UserDA.h"


using namespace std;

int main()
{
	//// uncomment this and delete other lines for launching actual system
	// Homepage Homepage;


	SupplierDA supplierDA;

	supplierDA.displayList(supplierDA.importSupplier());
}