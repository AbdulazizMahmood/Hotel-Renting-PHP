<?php
   class DatabaseConnect
   {
    private $host = "127.0.0.1"; 
    private $database="hotel system";
    private $connect;
    public function __construct()
    {}
     public function Connect()
     {
         $this->connect= mysqli_connect($this->host,"root","",$this->database);
        if (!$this->connect) {
           echo mysqli_errno($this->connect);
        }
     }
     public function getconnect()
     {       
         return $this->connect;
     }

     public function disconnect()
     {
         mysqli_close($this->connect);
     }
     
   }
 
?>