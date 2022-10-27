<?php

 require'DataBaseConnect.php';
 
 class person
{
     private $db;
     
    private $name;
    
    private $username;
    
    private $password;
    
    function  __construct() {
       $this->db=new DatabaseConnect();
    }    
    public function getName() {
        return $this->name;
    }

    public function getUsername() {
        return $this->username;
    }

    public function getPassword() {
        return $this->password;
    }

    public function setName($name) {
        $this->name = $name;
    }

    public function setUsername($username) {
        $this->username = $username;
    }

    public function setPassword($password) {
        $this->password = $password;
    }
    public function Login ($user,$pass,$tablename)
    {
        $this->db->Connect();             
     $query = "SELECT *  FROM  $tablename  WHERE  username = '$user'   AND  password = '$pass' ";     
    
     $result = mysqli_query($this->db->getconnect(), $query);
      
      if(mysqli_num_rows($result)>0)
      {
          return $result;
      }
      else
      {
          return 0;
      }

       $this->db->disconnet();
    }

}

    