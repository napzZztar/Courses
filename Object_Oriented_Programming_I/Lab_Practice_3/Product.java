class Product{
	int prodId;
	String prodName;
	String manuDate;
	String expDate;
	double unitProdCost;
	double unitSellPrice;
	
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
	
	double get(){
		return this.unitSellPrice;
	}

	
	//@ Main method
	public static void main(String args[]){
		System.out.println("Test RUN");
	}
	
}