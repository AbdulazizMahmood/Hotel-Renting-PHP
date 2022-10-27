<?php

require_once 'person.inc';

class receptionist extends person
{
    private $db; 
    public function __construct() {
        parent::__construct();
        $this->db=new DatabaseConnect();
    }
    public function getName() {
        return parent::getName();
    }

    public function getPassword() {
        return parent::getPassword();
    }

    public function getUsername() {
        return parent::getUsername();
    }

    public function setName($name) {
        parent::setName($name);
    }

    public function setPassword($password) {
        parent::setPassword($password);
    }

    public function setUsername($username) {
        parent::setUsername($username);
    } 
    
    public function SearchCustomer()
    {
        
    }
    public function CheckOut()
    {
        
    }
    public function ActiveReservation()
    {
        
    }
    public function AddCustomer()
    {
        
    }
    
    public function SearchBooking()
    {
        
    }
    public function AddReceptionist()
    {
        $this->db->Connect();
        $name=$this->getName();
        $username=$this->getUsername();
        $password=$this->getPassword();
        $query="INSERT INTO receptionist VALUES('$name','$username','$password')";
        $result= mysqli_query($this->db->getconnect(), $query);
        if(!$result)
        {
            die(mysqli_error($this->db->getconnect()));
        }
        $this->db->disconnect();
        
    }
    public function UpdateReceptionist($name,$username,$password)
    {
        $row=$this->SearchReceptionist($username);
        if($row)
        {
           $this->db->Connect();
           $row['name']=$name;
           $row['username']=$username;
           $row['password']=$password;
           $newname=$row['name'];
           $newpassword=$row['password'];
           $query="UPDATE receptionist 
                   SET name='$newname',password='$newpassword' WHERE username='$username'";
           
           $result= mysqli_query($this->db->getconnect(), $query);
           if($result) 
           {
               echo "Done";
           }
            else
           {
               echo mysqli_error($result);
           }
           $this->db->disconnect();
        }
        
            
         
    }
    public function SearchReceptionist($username)
    {
        $this->db->Connect();
        $query = "SELECT *  FROM  receptionist  WHERE  username = '$username'  ";
        $result= mysqli_query($this->db->getconnect(), $query);
        if(!mysqli_num_rows($result))
        {
            echo"Not Found";
            return 0;
        }
        else
        {
            echo "Found";
            $row= mysqli_fetch_assoc($result);
            return $row;
        }
        $this->db->disconnect();
    }
    public function RemoveReceptionist($username)
    {
        $row=$this->SearchReceptionist($username);
        if(!$row) 
        {
            echo 'Not found';
        }
        else
        {
           $this->db->Connect();
           $query="DELETE FROM receptionist WHERE username='$username'";
           $result= mysqli_query($this->db->getconnect(), $query);
           if($result) 
           {
               echo "Done";
           }
           else
           {
               echo mysqli_error($result);
           }
           $this->db->disconnect();
        }
    }
}
?>