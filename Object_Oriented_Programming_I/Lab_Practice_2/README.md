Write a Java class for a “Point of Sales (POS)” application for a Product. Name the class as “Sales”. The objective of the class is to perform the sales operation. The class has the attributes  and functionality as follows:
Attribute Name		Functionality
totalSalesAmount	The amount in Taka of  the total sales
salesAmount			The amount in Taka of  the current sales
productCounter		The quantity of the product available
unitBuyPrice		The unit buy price of the product
unitSellPrice		The unit sell price of the product
totalProfit			The profit from the sales, [totalProfit += (unitSellPrice- unitBuyPrice)* unitOfSales			The class has some methods with some functionality as follows: 


Method Name					Functionality
__________________________________
* addProduct(quantity)		The productCounter will be increased by the value passed to it.
* doSales(quantitySold)		This method performs the sales operation. This method will 										decrease the product * counter by quantity sold, calculate the 									payable amount of current sales and add the current sales amount 								to the total sales amount.
* setUnitBuyPrice(newPrice)	Sets the unit buy price of the product with the given value.
* setUnitSellPrice(newPrice)	Sets the unit sell price of the product with the given value.
* showBills()					Prints the details of the current Sales.
* showTotalSales()			Prints the amount of the total Sales.
* showTotalProfit()

The class contains a main method. Write necessary code to call the methods mentioned above.				
