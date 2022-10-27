<?php


require 'customer.inc';


$host = "127.0.0.1";
$user = "root";
$password = "";
$database="hotel system";
$connect = mysqli_connect($host, $user, $password, $database);

if (!$connect) {
    die('Could not connect to MySQL: ' . mysqli_connect_error());
}



class Booking {
  
    
    private $id;
    private $checkin;
    private $checkout;
    private $boardtype;
    private $customer_id;
    
    
    
    
    public function Extendbooking()
    {
        
    }
    
    public function CheckAvailability()
    {
        
    }
    
    public function Book()
    {
        
    }
    
    public function Editbooking()
    {
        
    }
    
}


mysqli_close($connect);

?>