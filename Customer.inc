<?php

require_once 'person.inc';

class Customer extends person{
    
    private $id;
    private $ssn;
    private $email;
   
    
    
    public function getId() {
        return $this->id;
    }

    public function getSsn() {
        return $this->ssn;
    }

    public function getEmail() {
        return $this->email;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function setSsn($ssn) {
        $this->ssn = $ssn;
    }

    public function setEmail($email) {
        $this->email = $email;
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

    
    public function Registeration($name,$username,$password,$ssn,$email)
    {
  

        include 'DataBaseConnect.php';
                
//id	name	username	password	ssn	email
  $query   = "INSERT INTO customer (name,username,password,ssn,email)  VALUES( '$name' , '$username' , '$password' , '$ssn' , '$email' )";        
    $result = mysqli_query($connect, $query);
      
      if(!$result)
      {
          die("ERR");
      }
      else
          {
          echo 'DONE';
          
      }
 
      mysqli_close($connect);       
    }
    
    
          
    
    
   public function Book($board,$activation ,$customerid,$checkin,$checkout,$rooms)
   {
       
       include 'DataBaseConnect.php';             
       
       $query="INSERT INTO booking(board_type,activation,customer_id) VALUES('$board',$activation,$customerid)";     
       $result = mysqli_query($connect, $query);
      
      if(!$result)
      {
          die("ERR");
      }
          
          $query2 ="SELECT MAX(id) FROM booking ";
          $result2 = mysqli_query($connect, $query2);
          
          if(!$result2)
          {
              die('ERROR');
          }
              
              
             $row = mysqli_fetch_assoc($result2); 
             
             $book_id=$row['MAX(id)'] ;
             
             echo '</br>' . $book_id . '</br>'  ;
             
             foreach ($rooms as $key) {
                 
                  echo '</br>' . $key . '</br>'  ;
       $query3 = "INSERT INTO room_book (room_id,book_id,check_in,check_out)  VALUES  ( $key, $book_id ,'$checkin' , '$checkout' )" ;     
       $result3= mysqli_query($connect, $query3);
      
      if(!$result3)
      {
          die("ERR". mysqli_errno($connect));
      }
 else {
     echo '</br>' . 'true ' .'</br>'  ;              
 }
      
      
                 
                 
                 
             }
             
             mysqli_free_result($result2);
             mysqli_close($connect);

      }
      
   
 
   
   
   
   public function CheckAvailability($checkin,$checkout,$single,$double,$triple)
   {
       
  include 'DataBaseConnect.php';
               
  $query   = "SELECT number,type
From  room
WHERE number NOT IN
(SELECT DISTINCT room_id
FROM   room_book
WHERE  check_out>= '$checkin' AND check_in <='$checkout' 
)";
  
  $result = mysqli_query($connect, $query);
      
      if(!$result)
      {
          die("ERR");
      }
      
          $singleTimes=0;
          $doubleTimes=0;
          $tripleTimes=0;


         $Rooms = array();
          $flag = 1;        
          while ($row= mysqli_fetch_assoc($result))
          {
              
              $Rooms[] = $row['number'];
              
              switch ($row['type'])
              {
                  case 'Single':
                  $singleTimes++;
                      break;
                  case 'double':
                      $doubleTimes++;
                      break;
                  case 'triple':
                      $tripleTimes++;
                      break;
                      
              }
          }
          if($singleTimes < $single)
          {
              echo 'MORE single Rooms than we can handle ';
              $flag = 0;
          }
          if($doubleTimes < $double)
          {
              echo 'MORE double Rooms than we can handle ';
                  $flag = 0;
              
          }
          if($tripleTimes < $triple)
          {
               echo 'MORE triple Rooms than we can handle';
                  $flag = 0;
               
          }
                  
       mysqli_free_result($result);
      mysqli_close($connect);    
      
          if($flag == 0)
          {
              return 0;
          }
          else{
              return $Rooms ;
          }
   
      
          }
       
       
   
    
   public function ExtendBooking($book_id,$check_out)
   {
                  
      include 'DataBaseConnect.php';
      
      
      $query4 = " 
                  SELECT DISTINCT  check_out
                  FROM    room_book
                  WHERE   book_id='$book_id' ";
      
             $result4 = mysqli_query($connect, $query4);
      
      if(!$result4)
      {
          die("ERR1");
      }
      
      $row = mysqli_fetch_assoc($result4);
      
      
      $date =$row['check_out'] ;
      

      $check_in= strftime("%Y-%m-%d", strtotime("$date +1 day"));

      
      

      $query = " 
                        SELECT number,type
                        From  room
                        WHERE number NOT IN
                        (SELECT DISTINCT room_id
                        FROM   room_book
                        WHERE  check_out>= '$check_in' AND check_in <='$check_out' 
                        )
                        AND number IN
                        (SELECT room_id
                         FROM   room_book
                         WHERE book_id = '$book_id'
                         )

                        ";
      
       $result = mysqli_query($connect, $query);
      
      if(!$result)
      {
          die("ERR2");
      }
      
      $query2 = " 
           SELECT room_id
           FROM  room_book
            WHERE  book_id = '$book_id' " ;
      
      $result2= mysqli_query($connect, $query2);
      
      if(!$result2)
      {
          die("ERR3");
      }
      
  
      if(mysqli_num_rows($result)  == mysqli_num_rows($result2)  )
      {
          $query3 = " UPDATE room_book
                              SET check_out ='$check_out'
                              WHERE book_id= '$book_id'  ";
      
          
                $result3= mysqli_query($connect, $query3);
      
      if(!$result3)
      {
          die("ERR4");
      }
      else{
          echo 'DONE'   ;
          return true;
      }
          
      }
      else{
          echo 'NOT AVAILABLE';
          return false ;
      }
      
       
   }
   
   public function EditCustomer($customer_id,$password,$email)
   {
        include 'DataBaseConnect.php';
        
 $query = "   UPDATE customer
                     SET email='$email' , password = '$password'
                     WHERE id = $customer_id";
                
        $result = mysqli_query($connect, $query);
        
          if(!$result)
      {
          die("ERR");
      }
      else{
          
          echo   '<br/>'. 'DONE'. '</br>';
      
          mysqli_close($connect);
      }
      
        
   }
    
   public function deleteRoom()
   {
       
   }
   
   
    
    
   
}