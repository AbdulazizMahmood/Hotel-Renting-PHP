<?php

require_once'person.inc';
require_once 'room.inc';
class admin extends person 
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
    
    
    public function AddReceptionist($name,$password,$username)
    {
      $recep=new receptionist();
      $recep->setName($name);
      $recep->setUsername($username);
      $recep->setPassword($password);
      $recep->AddReceptionist();
    }
    public function UpdateReceptionist($name,$username,$password)
    {
        $recep=new receptionist();
        $recep->UpdateReceptionist($name, $username, $password);
    }
    public function RemoveReceptionist($username)
    {
        $recep=new receptionist();
        $recep->RemoveReceptionist($username);
    }
    public function SearchReceotionist($username)
    {
        $recep=new receptionist();
        $recep->SearchReceptionist($username);
    }
    
    public function AddRooms(room $room ,$type,$price)
    {
       $room->add($type, $price);     
    }
    public function UpdateRooms(room $room,$number,$type,$price)
    {
        $room->update($number, $type, $price);
    }
    public function RemoveRooms(room $room,$number)
    {
        $room->delete($number);
    }
    public function SearchRooms(room $room,$number)
    {
        $room->search($number);
    }
}




?>