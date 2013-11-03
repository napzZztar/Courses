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
//}}}

   //@ Constructors.
   public Employee(String name, int empId, String dept, String designation, double totalSalesAmount){//{{{
     this.name = name;
     this.empId = empId;
     this.dept = dept;
     this.designation = designation;
     this.totalSalesAmount = totalSalesAmount;

     if(this.dept=="Sales"){

     }

   }//}}}

   //@ Set methods
   void setName(String name){//{{{
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
   void setBasicSalary(double basicSalary){
      this.basicSalary = basicSalary;
   }
   void setCommission(double commission){this.commission = commission;
   }
   void setTotalSalary(double totalSalary){
      this.totalSalary = totalSalary;
   }
   void setTotalSalesAmount(double totalSalesAmount){
      this.totalSalesAmount = totalSalesAmount;
   }
   void setMedicalAllowance(double medicalAllowance){
      this.medicalAllowance = medicalAllowance;
   }
   void setHouseRent(double houseRent){
      this.houseRent = houseRent;
   }


   //}}}

   //@ Get Methods
   String getName(){ //{{{
      return this.name;
   }
   String getDept(){
      return this.dept;
   }
   String getDesignation(){
      return this.setDesignation;
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
   public void showEmpInfo(){
      System.out.println("------------------------------");
      System.out.println("Employee Id   : "+this.name);
      System.out.println("Employee Name : "+this.empId);
      System.out.println("Departments   : "+this.dept);
      System.out.println("Designation   : "+this.designation);
      System.out.println(" : "+this.joinDate);
      System.out.println(" : "+this.dateOfBirth);
      System.out.println(" : "+this.contactNo);
      System.out.println(" : "+this.email);
      System.out.println("Basic         : "+this.basicSalary);
      System.out.println("House Rent    : "+this.houseRent);
      System.out.println("Medical       : "+this.medicalAllowance);
      System.out.println("              : "+this.commission);
      System.out.println("Commission    : "+this.totalSalesAmount);
      System.out.println("------------------------------");
      System.out.println("Total Salary  : "+this.totalSalary);

   }//}}}

   public static void main(String args[]){
      Employee emp1 = new Employee("Ashik Ahmed", 1220, "Sales", "Manager", 1200);
      emp1.showEmpInfo();

   }
}
