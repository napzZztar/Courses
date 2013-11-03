class Employee{
   int empId;
   String name;
   String dept;
   String designation;
   String joinDate;
   String dateOfBirth;
   String contactNo;
   String email;
   double basicSalary;
   double commission;
   double totalSalary;
   double totalSalesAmount;
   double medicalAllowance;
   double houseRent;

   Employee(String name, int empId, String dept, String designation, double totalSalesAmount){
     this.name = name;
     this.empId = empId;
     this.dept = dept;
     this.designation = designation;
     this.totalSalesAmount = totalSalesAmount;

     if(this.dept=="Sales"){

     }

   }

   void showEmpInfo(){
      System.out.ptintln("------------------------------")
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
      System.out.println("Commission    : "+this.totalSalesAmount)
      System.out.ptintln("------------------------------")
      System.out.println("Total Salary  : "+this.totalSalary);

   }

   public static void main(String args[]){
      Employee emp1 = new Employee("Ashik Ahmed", 1220, "CSE", "Manager");
      emp1.showEmpInfo();

   }
}
