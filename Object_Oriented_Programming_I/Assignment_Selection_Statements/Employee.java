class Employee{

   //@ Attributes
   private int empId;//{{{
   private String name;
   private String dept;
   private String designation;
   private String joinDate;
   private String dateOfBirth;
   private String contactNo;
   private String email;
   private double basicSalary;
   private double commission;
   private double totalSalary;
   private double totalSalesAmount;
   private double medicalAllowance;
   private double houseRent;
   private double commissionPer;
   private double houseRentPer;
//}}}

   //@ Constructors.
   public Employee(String name, int empId, String dept, String designation, double totalSalesAmount){//{{{
     this.name = name;
     this.empId = empId;
     this.dept = dept;
     this.designation = designation;
     this.totalSalesAmount = totalSalesAmount;

     if(this.designation =="Executive"){
         this.basicSalary = 10000;
         this.houseRentPer = 50;
         this.medicalAllowance = 500;
         if(dept == "Sales")
            this.commissionPer = 20;
         else
            System.out.println("Depertment Not Found");

     }else if(this.designation == "Manager"){
         this.basicSalary = 20000;
         this.houseRentPer = 60;
         this.medicalAllowance = 1000;
         if(dept == "Sales")
            this.commissionPer = 30;
         else
            System.out.println("Depertment Not Found");
     }else{
        System.out.println("Designation Not Found");
     }

     this.commission = (this.commissionPer / 100) * this.totalSalesAmount;
     this.houseRent = (this.houseRentPer / 100) * this.basicSalary;
     this.totalSalary = this.basicSalary + this.houseRent + this.medicalAllowance + this.totalSalesAmount;

   }

   public Employee(String name, int empId, String dept, String designation){
      this(name, empId, dept, designation, 0.0);

   }

//}}}

   //@ Set methods
   void setEmpId(int empId){//{{{
      this.empId = empId;
   }
   void setName(String name){
      this.name = name;
   }
   void setDept(String dept){
      this.dept = dept;
   }
   void setDesignation(String designation){
      this.designation = designation;
   }
   void setJoinDate(String joinDate){
      this.joinDate = joinDate;
   }
   void setDateOfBirth(String dateOfBirth){
      this.dateOfBirth = dateOfBirth;
   }
   void setContactNo(String contactNo){
      this.contactNo = contactNo;
   }
   void setEmail(String email){
      this.email = email;
   }

   //}}}

   //@ Get Methods
   int getImpId(){//{{{

      return this.empId;
   }
   String getName(){
      return this.name;
   }
   String getDept(){
      return this.dept;
   }
   String getDesignation(){
      return this.designation;
   }
   String getJoinDate(){
      return this.joinDate;
   }
   String getDateOfBir(){
      return this.dateOfBirth;
   }
   String getContactNo(){
      return this.contactNo;
   }
   String getEmail(){
      return this.email;
   }
   double getBasicSala(){
      return this.basicSalary;
   }
   double getCommissio(){
      return this.commission;
   }
   double getTotalSala(){
      return this.totalSalary;
   }
   double getTotalSaleAmount(){
      return this.totalSalesAmount;
   }
   double getMedicalAllowance(){
      return this.medicalAllowance;
   }
   double getHouseRentHouseRent(){
      return this.houseRent;
   }
//}}}

   //@ Show methods
//{{{
   public void showPaySlip(){
      System.out.println("------------------------------");
      System.out.println("---------Pay Slip-------------");
      System.out.println("------------------------------");
      System.out.println("Employee Id       : "+this.empId);
      System.out.println("Employee Name     : "+this.name);
      System.out.println("Departments       : "+this.dept);
      System.out.println("Designation       : "+this.designation);
      System.out.println("Joining Date      : "+this.joinDate);
      System.out.println("Date of Birth     : "+this.dateOfBirth);
      System.out.println("Contact No        : "+this.contactNo);
      System.out.println("E-mail            : "+this.email);
      System.out.println("Basic Salary      : "+this.basicSalary+" $");
      System.out.println("House Rent        : "+this.houseRent+" $");
      System.out.println("Medical Allowance : "+this.medicalAllowance+" $");
      System.out.println("Commission        : "+this.commission+" $");
      System.out.println("Total Sale Amount : "+this.totalSalesAmount+" $");
      System.out.println("------------------------------");
      System.out.println("Total Salary      : "+this.totalSalary+" $");
      System.out.println("------------------------------");
      System.out.println("-------End of Pay Slip--------");
      System.out.println("------------------------------");
      System.out.println();


   }//}}}

   //@ Main Method
   public static void main(String args[]){
      Employee emp1 = new Employee("Bill Gates", 1220, "Sales", "Manager", 1200);
      Employee emp2 = new Employee("Mark Zuckerberg", 1229, "Other", "Executive");

      emp1.setDateOfBirth("October-28-1955");
      emp1.setJoinDate("January-01-2013");
      emp1.setEmail("billg@microsoft.com");
      emp1.setContactNo("N/A");

      emp2.setDateOfBirth("May-14-1984");
      emp2.setJoinDate("January-01-2012");
      emp2.setEmail("N/A");
      emp2.setContactNo("N/A");

      emp1.showPaySlip();
      emp2.showPaySlip();

   }
}
