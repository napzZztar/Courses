class Product{
	int prodId;
	String prodName;
	String manuDate;
	String expDate;
	double unitProdCost;
	double unitSellPrice;
	static int prodNumber;
	
	//@Constructors
	Product(){
		this.prodId = 0;
		this.prodName = "";
		this.manuDate = "";
		this.expDate = "";
		this.unitProdCost = 0.0;
		this.unitSellPrice = 0.0;
		//prodNumber++;
		
	}

	Product(int prodId,  String prodName,  String manuDate,  String expDate,  double unitProdCost,  double unitSellPrice){
		this.prodId = prodId;
		this.prodName = prodName;
		this.manuDate = manuDate;
		this.expDate = expDate;
		this.unitProdCost = unitProdCost;
		this.unitSellPrice = unitSellPrice;
		prodNumber++;
	}

	
	//@ Set methods
	void setProdId(int prodId){
		this.prodId = prodId;
	}
	
	void setProdName(String prodName){
		this.prodName = prodName;
	}
	
	void setManuDate(String manuDate){
		this.manuDate = manuDate;
	}

	void setExpDate(String expDate){
		this.expDate = expDate;
	}
	
	void setUnitProdCost(double unitProdCost){
		this.unitProdCost = unitProdCost;
	}
	
	void setUnitSellPrice(double unitSellPrice){
		this.unitSellPrice = unitSellPrice;
	}
	
	static void setProdNumber(int prodNum){
		prodNumber = prodNum;
	}

	
	//@ get methods
	int getProdId(){
		return this.prodId;
	}
	
	String getProdName(){
		return this.prodName;
	}
	
	String getManuDate(){
		return this.manuDate;
	}
	
	String getExpDate(){
		return this.expDate;
	}
	
	double getUnitProdCost(){
		return this.unitProdCost;
	}
	
	double getSellPrice(){
		return this.unitSellPrice;
	}

	int getProdNumber(){
		return prodNumber;
	}
	
	//@ Main method
	public static void main(String args[]){
		System.out.println("Test RUN");
	}
	
}